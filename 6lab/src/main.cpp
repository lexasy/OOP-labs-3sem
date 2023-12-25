#include "../includes/factory.hpp"

using set_t = std::set<std::shared_ptr<Npc>>;

void save(const set_t& array, const std::string& filename) {
    std::ofstream fs(filename);
    fs << array.size() << "\n";
    for (auto& n : array) {
        n->save(fs);
    }
    fs.flush();
    fs.close();
}

set_t load(const std::string& filename) {
    set_t result;
    std::ifstream is(filename);
    if (is.good() && is.is_open()) {
        int count;
        is >> count;
        for (int i = 0; i < count; i++) {
            result.insert(factory(is));
        }
        is.close();
    }
    else {
        std::cerr << "Error: " << std::strerror(errno) << std::endl;
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const set_t& array) {
    for (auto& n : array) {
        n->print();
    }
    return os;
}

set_t fight(const set_t& array, size_t distance) {
    set_t dead_list;
    for (const auto &attacker : array) {
        for (const auto &defender : array) {
            if ((attacker != defender) && (attacker->is_close(defender, distance))) {
                if (defender->accept(attacker)) {
                    dead_list.insert(defender);
                }
            }
        }
    }
    return dead_list;
}

int main() {
    set_t array;
    std::cout << "Generating..........\n";
    for (size_t i = 0; i < 10; i++) {
        array.insert(factory(NpcType(std::rand() % 3), "NPC", std::rand() % 500, std::rand() % 500));
    } 
    std::cout << "Saving ...\n";
    save(array, "npc.txt");
    std::cout << "Loading ...\n";
    array = load("npc.txt");
    std::cout << "Fighting ...\n" << array;
    for (size_t distance = 20; (distance <= 500) && !array.empty(); distance += 20) {
        auto dead_list = fight(array, distance);
        for (auto &d : dead_list) {
            array.erase(d);
        }
        std::cout << "\nFight stats ----------\ndistance: " << distance << "\nkilled: " << dead_list.size() << "\n\n";
    }
    std::cout << "Survivers: " << array << "\n";
}
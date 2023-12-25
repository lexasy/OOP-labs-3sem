#include "../includes/bear.hpp"
#include "../includes/elf.hpp"
#include "../includes/robber.hpp"

using set_t = std::set<std::shared_ptr<Npc>>;

class FileObserver : public Observer {
private:
    FileObserver() {}
public:
    static std::shared_ptr<Observer> get() {
        static std::shared_ptr<Observer> instance(new FileObserver());
        return instance;
    }
    void on_fight(const std::shared_ptr<Npc> attacker, const std::shared_ptr<Npc> defender, bool win) override {
        if (win) {
            std::ofstream file(FileOutput, std::ios_base::app);

            file << "\nMurder\n";
            attacker->print(file);
            file << "->";
            defender->print(file);
            file.close();
        }
    }
};

class OutputObserver : public Observer {
private:
    OutputObserver() {}
public:
    static std::shared_ptr<Observer> get() {
        static OutputObserver instance;
        return std::shared_ptr<Observer>(&instance, [](Observer *) {});
    }
    void on_fight(const std::shared_ptr<Npc> attacker, const std::shared_ptr<Npc> defender, bool win) override {
        if (win) {
            std::cout << "\nMurder\n"; 
            attacker->print();
            std::cout << "->";
            defender->print();
        }
    }
};

std::shared_ptr<Npc> factory(NpcType tp, std::string name, int x, int y) {
    std::shared_ptr<Npc> result;
    switch (tp) {
    case BearType:
        result = std::make_shared<Bear>(name, x, y);
        break;
    case ElfType:
        result = std::make_shared<Elf>(name, x, y);
        break;
    case RobberType:
        result = std::make_shared<Robber>(name, x, y);
        break;
    default:
        std::cerr << "Undefined NPC type\n";
        break;
    }
    if (result) {
        result->subscribe(OutputObserver::get());
        result->subscribe(FileObserver::get());
    }
    return result;
}

std::shared_ptr<Npc> factory(std::istream& is) {
    std::shared_ptr<Npc> result;
    int tp;
    is >> tp;
    switch (tp) {
    case BearType:
        result = std::make_shared<Bear>(is);
        break;
    case ElfType:
        result = std::make_shared<Elf>(is);
        break;
    case RobberType:
        result = std::make_shared<Robber>(is);
        break;
    default:
        std::cerr << "Undefined NPC type\n";
        break;
    }
    if (result) {
        result->subscribe(OutputObserver::get());
        result->subscribe(FileObserver::get());
    }
    return result;
}

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
                bool success = false;
                success = defender->accept(attacker);
                if (success) {
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
    std::cout << "Survivers: " << array;
}
#include "../includes/factory.hpp"
#include <sstream>
#include <thread>
#include <mutex>
#include <chrono>
#include <queue>
#include <optional>
#include <array>

using namespace std::chrono_literals;

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
        if (n->alive) {
            n->print();
        }
    }
    return os;
}

set_t fight(const set_t& array, size_t distance) {
    set_t dead_list;
    for (const auto &attacker : array) {
        for (const auto &defender : array) {
            if (attacker != defender) {
                if (attacker->is_close(defender, distance)) {
                    if (defender->accept(attacker)) {
                        dead_list.insert(defender);
                    }
                }
            }
        }
    }
    return dead_list;
}

struct print : std::stringstream {
    ~print() {
        static std::mutex mutex;
        std::lock_guard<std::mutex> lck(mutex_print);
        std::cout << this->str();
        std::cout.flush();
    }
};

bool fight_thread_flag = true;
bool move_thread_flag = true;

struct FightEvent {
    std::shared_ptr<Npc> attacker;
    std::shared_ptr<Npc> defender;
};

class FightManager {
private:
    std::queue<FightEvent> events;
    std::shared_mutex mutex;

    FightManager() {}

public:
    static FightManager &get() {
        static FightManager instance;
        return instance;
    }

    void add_event(FightEvent &&event) {
        std::lock_guard<std::shared_mutex> lock(mutex);
        events.push(event);
    }

    void operator()() {
        while (fight_thread_flag) {
            {
                std::optional<FightEvent> event;
                {
                    std::lock_guard<std::shared_mutex> lock(mutex);
                    if (!events.empty()) {
                        event = events.back();
                        events.pop();
                    }
                }
                if (event) {
                    if (event->attacker->is_alive()) {
                        if (event->defender->is_alive()) {
                            if (event->defender->accept(event->attacker)) {
                                event->defender->must_die();
                            }
                        }
                    }    
                }
                else {
                    std::this_thread::sleep_for(100ms);
                }
            }
        }
    }
};


int main() {
    set_t array;
    const int MAX_X = 100;
    const int MAX_Y = 100;
    const int DISTANCE = 40;
    std::cout << "Generating ..........\n";
    for (size_t i = 0; i < 50; i++) {
        array.insert(factory(NpcType(std::rand() % 3), "NPC", std::rand() % MAX_X, std::rand() % MAX_Y));
    }
    std::cout << "Starting list:\n" << array;
    std::thread fight_thread(std::ref(FightManager::get()));
    int timer = 0;
    std::thread move_thread([&array, MAX_X, MAX_Y, DISTANCE]() {
        while (move_thread_flag) {
            for (std::shared_ptr<Npc> npc : array) {
                if (npc->is_alive()) {
                    int shift_x = std::rand() % 20 - 10;
                    int shift_y = std::rand() % 20 - 10;
                    npc->move(shift_x, shift_y, MAX_X, MAX_Y);
                }
            }
            for (std::shared_ptr<Npc> npc : array) {
                for (std::shared_ptr<Npc> other : array) {
                    if (other != npc) {
                        if (npc->is_alive()) {
                            if (other->is_alive()) {
                                if (npc->is_close(other, DISTANCE)) {
                                    FightManager::get().add_event({npc, other});
                                }
                            }
                        }
                    }
                }
            }
            std::this_thread::sleep_for(1s);
        }
    });
    std::time_t start = std::time(nullptr);
    std::time_t finish = start + 30;
    while (start < finish) { // 30 seconds of battle
        const int grid{20}, step_x{MAX_X / grid}, step_y{MAX_Y / grid};
        {
            std::array<char, grid * grid> fields{0};
            for (std::shared_ptr<Npc> npc : array) {
                auto [x, y] = npc->position();
                int i = x / step_x;
                int j = y / step_y;
                if (npc->is_alive()) {
                    if (npc->get_type() == BearType) {
                        fields[i + grid * j] = 'B';
                    } else if (npc->get_type() == ElfType) {
                        fields[i + grid * j] = 'E';
                    } else if (npc->get_type() == RobberType) {
                        fields[i + grid * j] = 'R';
                    }
                } else {
                    fields[i + grid * j] = '.';
                }

            }
            std::lock_guard<std::mutex> lck(mutex_print);
            for (int j = 0; j < grid; ++j) {
                for (int i = 0; i < grid; ++i) {
                    char c = fields[i + j * grid];
                    if (c != 0) {
                        std::cout << "[" << c << "]";
                    }
                    else {
                        std::cout << "[ ]";
                    }
                }
                std::cout << "\n";
            }
            std::cout << "\n";
        }
        std::this_thread::sleep_for(1s);
        start = std::time(nullptr);
    };
        fight_thread_flag = false;
        move_thread_flag = false;
    move_thread.join();
    fight_thread.join();
    std::cout << "Survived monsters\n";
    std::cout << array << "\n";
}
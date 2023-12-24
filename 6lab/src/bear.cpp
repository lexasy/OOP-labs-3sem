#include "bear.hpp"
#include "elf.hpp"
#include "robber.hpp"

Bear::Bear(std::string name, int x, int y) : Npc(BearType, name, x, y) {}
Bear::Bear(std::string name, std::istream& is) : Npc(BearType, name, is) {}

void Bear::print() {
    std::cout << *this;
}

void Bear::save(std::ostream& os) {
    os << BearType << "\n";
    Npc::save(os);
}

bool Bear::is_bear() const {
    return true;
}

bool Bear::fight(std::shared_ptr<Elf> other) {
    fight_notify(other, true);
    return true;
}

bool Bear::fight(std::shared_ptr<Robber> other) {
    fight_notify(other, false);
    return false;
}

bool Bear::fight(std::shared_ptr<Bear> other) {
    fight_notify(other, false);
    return false;
}

std::ostream& operator<<(std::ostream& os, Bear& bear) {
    os << "Bear: " << *static_cast<Npc *> (&bear) << "\n";
    return os;
}
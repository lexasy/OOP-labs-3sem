#include "robber.hpp"
#include "bear.hpp"
#include "elf.hpp"

Robber::Robber(std::string name, int x, int y) : Npc(RobberType, name, x, y) {}
Robber::Robber(std::string name, std::istream& is) : Npc(RobberType, name, is) {}

void Robber::print() {
    std::cout << *this;
}

void Robber::save(std::ostream& os) {
    os << RobberType << "\n";
    Npc::save(os);
}

void Robber::is_robber() const {
    return true;
}

bool Robber::fight(std::shared_ptr<Bear> other) {
    fight_notify(other, false);
    return false;
}

bool Robber::fight(std::shared_ptr<Elf> other) {
    fight_notify(other, false);
    return false;
}

bool Robber::fight(std::shared_ptr<Robber> other) {
    fight_notify(other, true);
    return true;
}

std::ostream& operator<<(std::ostream os, Robber& robber) {
    os << "Robber: " << *static_cast<Npc *>(&robber) << "\n";
    return os;
}
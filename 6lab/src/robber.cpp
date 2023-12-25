#include "../includes/bear.hpp"
#include "../includes/elf.hpp"
#include "../includes/robber.hpp"

Robber::Robber(std::string name, int x, int y) : Npc(RobberType, name, x, y) {}
Robber::Robber(std::istream& is) : Npc(RobberType, is) {}

void Robber::print() {
    std::cout << *this;
}

void Robber::print(std::ostream& os) {
    os << *this;
}

void Robber::save(std::ostream& os) {
    os << RobberType << "\n";
    Npc::save(os);
}

bool Robber::is_robber() const {
    return true;
}

bool Robber::accept(std::shared_ptr<Npc> visitor) {
    return visitor->visit(std::make_shared<Robber>(*this));
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

std::ostream& operator<<(std::ostream& os, Robber& robber) {
    os << "Robber: " << *static_cast<Npc *>(&robber);
    return os;
}
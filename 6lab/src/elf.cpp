#include "../includes/bear.hpp"
#include "../includes/elf.hpp"
#include "../includes/robber.hpp"

Elf::Elf(std::string name, int x, int y) : Npc(ElfType, name, x, y) {}
Elf::Elf(std::istream& is) : Npc(ElfType, is) {}

void Elf::print() {
    std::cout << *this;
}

void Elf::print(std::ostream& os) {
    os << *this;
}

void Elf::save(std::ostream& os) {
    os << ElfType << "\n";
    Npc::save(os);
}

bool Elf::is_elf() const {
    return true;
}

bool Elf::accept(std::shared_ptr<Npc> visitor) {
    return visitor->visit(std::make_shared<Elf>(*this));
}

bool Elf::fight(std::shared_ptr<Bear> other) {
    fight_notify(other, false);
    return false;
}

bool Elf::fight(std::shared_ptr<Robber> other) {
    fight_notify(other, true);
    return true;
}

bool Elf::fight(std::shared_ptr<Elf> other) {
    fight_notify(other, false);
    return false;
}

std::ostream& operator<<(std::ostream& os, Elf& elf) {
    os << "Elf: " << *static_cast<Npc *>(&elf);
    return os;
}
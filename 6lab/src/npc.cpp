#include "../includes/npc.hpp"

Npc::Npc(NpcType tp, std::string _name, int _x, int _y) : npctype(tp), name(_name), x(_x), y(_y) {}
Npc::Npc(NpcType tp, std::istream& is) : npctype(tp) {
    is >> name;
    is >> x;
    is >> y;
}

void Npc::subscribe(std::shared_ptr<Observer> observer) {
    observers.push_back(observer);
}

void Npc::fight_notify(const std::shared_ptr<Npc> defender, bool win) {
    for (auto& o : observers) {
        o->on_fight(shared_from_this(), defender, win);
    }
}

bool Npc::is_close(const std::shared_ptr<Npc>& other, size_t distance) const {
    if (std::pow(x - other->x, 2) + std::pow(y - other->y, 2) <= std::pow(distance, 2)) {
        return true;
    }
    else {
        return false;
    }
}

bool Npc::is_bear() const {
    return false;
}

bool Npc::is_elf() const {
    return false;
}

bool Npc::is_robber() const {
    return false;
}

bool Npc::visit(std::shared_ptr<Bear> other) {
    return this->visit(other);
}

bool Npc::visit(std::shared_ptr<Elf> other) {
    return this->visit(other);
}

bool Npc::visit(std::shared_ptr<Robber> other) {
    return this->visit(other);
}

void Npc::save(std::ostream& os) {
    os << x << "\n";
    os << y << "\n";
}

std::ostream& operator<<(std::ostream& os, Npc& npc) {
    os << "{x: " << npc.x << ", y: " << npc.y << "}";
    return os;
}
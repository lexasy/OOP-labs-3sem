#include "../includes/npc.hpp"

Npc::Npc(NpcType tp, std::string _name, int _x, int _y) : npctype(tp), name(_name), x(_x), y(_y) {}
Npc::Npc(NpcType tp, std::istream& is) : npctype(tp) {
    is >> x;
    is >> y;
}

void Npc::subscribe(std::shared_ptr<Observer> observer) {
    observers.push_back(observer);
}

void Npc::fight_notify(const std::shared_ptr<Npc> defender, bool win) {
    for (auto& o : observers) {
        o->on_fight(std::shared_ptr<Npc>(this, [](Npc *){}), defender, win);
    }
}

bool Npc::is_close(const std::shared_ptr<Npc>& other, int distance) {
    auto [other_x, other_y] = other->position();
    std::lock_guard<std::mutex> lck(mutex);
    if (this->get_type() == BearType) {
        distance = BEAR_FIGHT_DISTANCE;
    } else if (this->get_type() == ElfType) {
        distance = ELF_FIGHT_DISTANCE;
    } else if (this->get_type() == RobberType) {
        distance = ROBBER_FIGHT_DISTANCE;
    }
    if (std::pow(x - other_x, 2) + std::pow(y - other_y, 2) <= std::pow(distance, 2)) {
        return true;
    }
    else {
        return false;
    }
}

NpcType Npc::get_type() {
    // std::lock_guard<std::mutex> lck(mutex);
    return npctype;
}

std::pair<int, int> Npc::position() {
    std::lock_guard<std::mutex> lck(mutex);
    return {x, y};
}

void Npc::save(std::ostream& os) {
    os << x << "\n";
    os << y << "\n";
}

void Npc::move(int shift_x, int shift_y, int max_x, int max_y) {
    std::lock_guard<std::mutex> lck(mutex);
    int distance = 0;
    if (this->get_type() == BearType) {
        distance = BEAR_STEP;
    } else if (this->get_type() == ElfType) {
        distance = ELF_STEP;
    } else if (this->get_type() == RobberType) {
        distance = ROBBER_STEP;
    }
    shift_x = distance * pow(-1, shift_x);
    shift_y = distance * pow(-1, shift_y);
    if ((x + shift_x >= 0) && (x + shift_x <= max_x)) {
        x += shift_x;
    }
    if ((y + shift_y >= 0) && (y + shift_y <= max_y)) {
        y += shift_y;
    }
} 

bool Npc::is_alive() {
    std::lock_guard<std::mutex> lck(mutex);
    return alive;
}

void Npc::must_die() {
    std::lock_guard<std::mutex> lck(mutex);
    alive = false;
}

std::ostream& operator<<(std::ostream& os, Npc& npc) {
    os << "{x: " << npc.x << ", y: " << npc.y << "}\n";
    return os;
}
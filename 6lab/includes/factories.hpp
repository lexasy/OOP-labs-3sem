#pragma once

#include "bear.hpp"
#include "elf.hpp"
#include "robber.hpp"

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

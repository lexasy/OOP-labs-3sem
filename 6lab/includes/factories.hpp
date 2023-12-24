#pragma once

#include "bear.hpp"
#include "elf.hpp"
#include "robber.hpp"

std::shared_ptr<Npc> factory(NpcType tp, std::string name, int x, int y) {
    switch (tp) {
    case BearType:
        return std::make_shared<Bear>(name, x, y);
    case ElfType:
        return std::make_shared<Elf>(name, x, y);
    case RobberType:
        return std::make_shared<Robber>(name, x, y);
    default:
        std::cout << "Not real npc type!\n";
        return nullptr;
    }
}

std::shared_ptr<Npc> factory(std::istream& is) {
    int tp;
    is >> tp;
    switch (tp) {
    case BearType:
        return std::make_shared<Bear>(is);
    case ElfType:
        return std::make_shared<Elf>(is);
    case RobberType:
        return std::make_shared<Robber>(is);
    default:
        std::cout << "Not real npc type!\n";
        return nullptr;
    }
}
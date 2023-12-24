#pragma once

#define FileOutput "./log.txt"

#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <random>
#include <fstream>
#include <set>
#include <math.h>
#include <obserevers.hpp>

class Npc;
class Bear;
class Elf;
class Robber;



typedef enum NpcType {
    UnknownType, BearType, ElfType, RobberType
};

class Npc : public std::enable_shared_from_this<Npc> {
public:
    NpcType npctype;
    int x, y;
    std::vector<std::shared_ptr<Observer>> observers;
    std::string name;

    Npc(NpcType type, std::string _name, int _x, int _y);
    Npc(NpcType type, std::istream& is);

    void subscribe(std::shared_ptr<Observer> observer);
    void fight_notify(const std::shared_ptr<Npc> defender, bool win);
    virtual bool is_close(const std::shared_ptr<Npc> &other, size_t distance) const;

    virtual bool is_bear() const;
    virtual bool is_elf() const;
    virtual bool is_robber() const;

    virtual bool fight(std::shared_ptr<Bear> other) = 0;
    virtual bool fight(std::shared_ptr<Elf> other) = 0;
    virtual bool fight(std::shared_ptr<Robber> other) = 0;

    virtual void print() = 0;

    virtual void save(std::ostream& os);

    friend std::ostream& operator<<(std::ostream& os, Npc& npc); 

};



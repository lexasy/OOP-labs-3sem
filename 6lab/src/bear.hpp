#pragma once
#include "npc.hpp"

class Bear : public Npc {
public:
    Bear(std::string name, int x, int y);
    Bear(std::string name, std::istream& is);
    void print() override;
    void save(std::ostream& os) override;
    bool is_bear() const override;
    bool fight(std::shared_ptr<Elf> other) override;
    bool fight(std::shared_ptr<Robber> other) override;
    bool fight(std::shared_ptr<Bear> other) override;
    friend std::ostream& operator<<(std::ostream& os, Bear& bear);
};
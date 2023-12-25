#pragma once
#include "npc.hpp"

class Robber : public Npc {
public:
    Robber(std::string name, int x, int y);
    Robber(std::istream& is);
    void print() override;
    void save(std::ostream& os) override;
    bool is_robber() const override;
    bool accept(std::shared_ptr<Npc> visitor) override;
    bool fight(std::shared_ptr<Bear> other) override;
    bool fight(std::shared_ptr<Elf> other) override;
    bool fight(std::shared_ptr<Robber> other) override;
    friend std::ostream& operator<<(std::ostream& os, Robber& robber);
};
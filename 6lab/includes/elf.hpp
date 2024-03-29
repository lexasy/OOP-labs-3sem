#pragma once
#include "npc.hpp"

class Elf : public Npc {
public:
    Elf(std::string name, int x, int y);
    Elf(std::istream& is);
    void print() override;
    void print(std::ostream& os) override;
    void save(std::ostream& os) override;
    bool is_elf() const override;
    bool accept(std::shared_ptr<Npc> visitor) override;
    bool fight(std::shared_ptr<Robber> other) override;
    bool fight(std::shared_ptr<Bear> other) override;
    bool fight(std::shared_ptr<Elf> other) override;
    friend std::ostream& operator<<(std::ostream& os, Elf& elf);
};
#pragma once

#include "npc.hpp"
#include "fstream"

class Observer {
public:
    virtual void on_fight(const std::shared_ptr<Npc> attacker, const std::shared_ptr<Npc> defender, bool win) = 0;
};

class OutputObserver : public Observer {
public:
    void on_fight(const std::shared_ptr<Npc> attacker, const std::shared_ptr<Npc> defender, bool win) override {
        if (win) {
            std::cout << "\nMurder\n" << *attacker << "->" << *defender << "\n"; 
        }
    }
};

class FileObserver : public Observer {
public:
    void on_fight(const std::shared_ptr<Npc> attacker, const std::shared_ptr<Npc> defender, bool win) override {
        if (win) {
            std::ofstream file(FileOutput, std::ios_base::app);
            file << "\nMurder\n" << *attacker << "->" << *defender << "\n";
            file.close();
        }
    }
};
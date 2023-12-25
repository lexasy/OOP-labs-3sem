#pragma once
#include "npc.hpp"

class FileObserver : public Observer {
private:
    FileObserver() {}
public:
    static std::shared_ptr<Observer> get() {
        static std::shared_ptr<Observer> instance(new FileObserver());
        return instance;
    }
    void on_fight(const std::shared_ptr<Npc> attacker, const std::shared_ptr<Npc> defender, bool win) override {
        if (win) {
            std::ofstream file(FileOutput, std::ios_base::app);

            file << "\nMurder\n";
            attacker->print(file);
            file << "->";
            defender->print(file);
            file.close();
        }
    }
};

class OutputObserver : public Observer {
private:
    OutputObserver() {}
public:
    static std::shared_ptr<Observer> get() {
        static OutputObserver instance;
        return std::shared_ptr<Observer>(&instance, [](Observer *) {});
    }
    void on_fight(const std::shared_ptr<Npc> attacker, const std::shared_ptr<Npc> defender, bool win) override {
        if (win) {
            std::cout << "\nMurder\n"; 
            attacker->print();
            std::cout << "->";
            defender->print();
        }
    }
};
#include "../include/Bear.hpp"

Bear::Bear(const std::string& name, int x, int y)
    : NPC(name, "Bear", x, y, 5, 10) {}

void Elf::fight(NPC* opponent, std::vector<std::shared_ptr<Observer>>& observers) {
    if (opponent->get_type() == "Knight") {
        std::string event = name + " kills " + opponent->get_name();
        for (auto& observer : observers) {
            observer->update(event);
        }
    }
}
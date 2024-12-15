#include "../include/Knight.hpp"


Knight::Knight(const std::string& name, int x, int y)
    : NPC(name, "Knight", x, y, 30, 10) {}

void Knight::fight(NPC* opponent, std::vector<std::shared_ptr<Observer>>& observers) {
    if (opponent->get_type() == "Orc") {
        std::string event = name + " kills " + opponent->get_name();
        for (auto& observer : observers) {
            observer->update(event);
        }
    }
}
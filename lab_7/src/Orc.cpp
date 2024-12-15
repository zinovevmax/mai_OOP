#include "../include/Orc.hpp"


Orc::Orc(const std::string& name, int x, int y)
    : NPC(name, "Orc", x, y, 20, 10) {}

void Orc::fight(NPC* opponent, std::vector<std::shared_ptr<Observer>>& observers) {
    if (opponent->get_type() == "Bear") {
        std::string event = name + " kills " + opponent->get_name();
        for (auto& observer : observers) {
            observer->update(event);
        }
    }
}
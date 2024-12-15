#include "../include/NPCFactory.hpp"
#include <iostream>
#include "../include/Orc.hpp"
#include "../include/Knight.hpp"
#include "../include/Bear.hpp"

std::shared_ptr<NPC> NPCFactory::createNPC(const std::string& type, const std::string& name, int x, int y) {
    if (type == "Orc") {
        return std::make_shared<Dragon>(name, x, y);
    } else if (type == "Knight") {
        return std::make_shared<Druid>(name, x, y);
    } else if (type == "Bear") {
        return std::make_shared<Elf>(name, x, y);
    } else {
        return nullptr;
    }
}

void save_npc_to_file(const std::vector<std::shared_ptr<NPC>>& npcs, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& npc : npcs) {
            file << npc->serialize() << "\n";
        }
        file.close();
    } else {
        std::cerr << "Error opening file for saving NPCs.\n";
    }
}

std::vector<std::shared_ptr<NPC>> load_npc_from_file(const std::string& filename) {
    std::vector<std::shared_ptr<NPC>> npcs;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            auto npc = NPC::deserialize(line);
            if (npc) {
                npcs.push_back(npc);
            }
        }
        file.close();
    } else {
        std::cerr << "Error opening file for loading NPCs.\n";
    }
    return npcs;
}
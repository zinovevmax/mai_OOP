#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <cmath>
#include <memory>
#include <fstream>
#include <sstream>

class NPC {
public:
    virtual ~NPC() = default;
    virtual void attack(NPC* target) = 0;
    virtual std::string get_name() const = 0;
    virtual std::string get_type() const = 0;
    virtual void print_info() const = 0;
    
    int x, y;
    std::string name;
};

class Bear : public NPC {
public:
    Bear(const std::string& name, int x, int y) {
        this->name = name;
        this->x = x;
        this->y = y;
    }
    void attack(NPC* target) override {
        if (target->get_type() == "Knight") {
            std::cout << name << " attacks " << target->get_name() << std::endl;
        }
    }
    std::string get_name() const override { return name; }
    std::string get_type() const override { return "Bear"; }
    void print_info() const override {
        std::cout << "Bear " << name << " (" << x << ", " << y << ")\n";
    }
};

class Orc : public NPC {
public:
    Orc(const std::string& name, int x, int y) {
        this->name = name;
        this->x = x;
        this->y = y;
    }
    void attack(NPC* target) override {
        if (target->get_type() == "Bear") {
            std::cout << name << " attacks " << target->get_name() << std::endl;
        }
    }
    std::string get_name() const override { return name; }
    std::string get_type() const override { return "Orc"; }
    void print_info() const override {
        std::cout << "Orc " << name << " (" << x << ", " << y << ")\n";
    }
};

class Knight : public NPC {
public:
    Knight(const std::string& name, int x, int y) {
        this->name = name;
        this->x = x;
        this->y = y;
    }
    void attack(NPC* target) override {
        if (target->get_type() == "Orc") {
            std::cout << name << " attacks " << target->get_name() << std::endl;
        }
    }
    std::string get_name() const override { return name; }
    std::string get_type() const override { return "Knight"; }
    void print_info() const override {
        std::cout << "Knight " << name << " (" << x << ", " << y << ")\n";
    }
};

class NPCFactory {
public:
    static std::unique_ptr<NPC> create_npc(const std::string& npc_type, const std::string& name, int x, int y) {
        if (! (0 <= x && x <= 500 && 0 <= y && y <= 500)){
            throw std::invalid_argument("Inappropriate location. Should be [0, 500]");
        }
        if (npc_type == "Bear") {
            return std::make_unique<Bear>(name, x, y);
        } else if (npc_type == "Orc") {
            return std::make_unique<Orc>(name, x, y);
        } else if (npc_type == "Knight") {
            return std::make_unique<Knight>(name, x, y);
        } else {
            throw std::invalid_argument("Unknown NPC type!");
        }
    }

    static std::vector<std::unique_ptr<NPC>> create_npcs_from_file(const std::string& file_path) {
        std::vector<std::unique_ptr<NPC>> npcs;
        std::ifstream file(file_path);
        std::string line;

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string type, name;
            int x, y;
            if (iss >> type >> name >> x >> y) {
                npcs.push_back(create_npc(type, name, x, y));
            }
        }
        
        return npcs;
    }
};

class BattleVisitor {
public:
    BattleVisitor(int range) : range_of_attack(range) {}

    void visit(NPC* npc1, NPC* npc2) {
        // Calculate distance
        int dx = npc1->x - npc2->x;
        int dy = npc1->y - npc2->y;
        double distance = std::sqrt(dx * dx + dy * dy);

        // If within attack range, engage battle
        if (distance <= range_of_attack) {
            npc1->attack(npc2);
            npc2->attack(npc1);
        }
    }

private:
    int range_of_attack;
};

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const std::string& message) = 0;
};

class FileObserver : public Observer {
public:
    FileObserver(const std::string& filename) : filename(filename) {}

    void update(const std::string& message) override {
        std::ofstream out_file(filename, std::ios::app);
        out_file << message << std::endl;
    }

private:
    std::string filename;
};

class ScreenObserver : public Observer {
public:
    void update(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

class BattleArena {
public:
    BattleArena(int attack_range) : attack_range(attack_range) {}

    void add_observer(std::shared_ptr<Observer> observer) {
        observers.push_back(observer);
    }

    void add_npc(std::unique_ptr<NPC> npc) {
        npcs.push_back(std::move(npc));
    }

    void battle() {
        BattleVisitor visitor(attack_range);
        for (size_t i = 0; i < npcs.size(); ++i) {
            for (size_t j = i + 1; j < npcs.size(); ++j) {
                visitor.visit(npcs[i].get(), npcs[j].get());
                notify_observers("Battle occurred between " + npcs[i]->get_name() + " and " + npcs[j]->get_name());
            }
        }
    }

private:
    void notify_observers(const std::string& message) {
        for (auto& observer : observers) {
            observer->update(message);
        }
    }

    int attack_range;
    std::vector<std::unique_ptr<NPC>> npcs;
    std::vector<std::shared_ptr<Observer>> observers;
};

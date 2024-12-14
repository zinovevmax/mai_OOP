#include <gtest/gtest.h>

#include "../src/npc.cpp" 

// Test NPC creation using NPCFactory
TEST(NPCFactoryTest, test_00) {
    auto npc = NPCFactory::create_npc("Bear", "Honey", 100, 200);
    EXPECT_EQ(npc->get_name(), "Honey");
    EXPECT_EQ(npc->get_type(), "Bear");
}

TEST(NPCFactoryTest, test_01) {
    auto npc = NPCFactory::create_npc("Orc", "Crusher", 200, 300);
    EXPECT_EQ(npc->get_name(), "Crusher");
    EXPECT_EQ(npc->get_type(), "Orc");
}

TEST(NPCFactoryTest, test_02) {
    auto npc = NPCFactory::create_npc("Knight", "Breon", 300, 400);
    EXPECT_EQ(npc->get_name(), "Breon");
    EXPECT_EQ(npc->get_type(), "Knight");
}

TEST(NPCFactoryTest, test_03) {
    EXPECT_THROW(NPCFactory::create_npc("Unknown", "UnknownNPC", 500, 600), std::invalid_argument);
}

TEST(NPCFactoryTest, test_04) {
    std::ofstream file("test_npc.txt");
    file << "Bear Honey 100 200\n";
    file << "Orc Crusher 300 400\n";
    file.close();

    auto npcs = NPCFactory::create_npcs_from_file("test_npc.txt");

    ASSERT_EQ(npcs.size(), 2);

    EXPECT_EQ(npcs[0]->get_name(), "Honey");
    EXPECT_EQ(npcs[0]->get_type(), "Bear");
    EXPECT_EQ(npcs[0]->x, 100);
    EXPECT_EQ(npcs[0]->y, 200);

    EXPECT_EQ(npcs[1]->get_name(), "Crusher");
    EXPECT_EQ(npcs[1]->get_type(), "Orc");
    EXPECT_EQ(npcs[1]->x, 300);
    EXPECT_EQ(npcs[1]->y, 400);
}

// Test attack functionality
TEST(NPCAttackTest, test_00) {
    auto Bear = NPCFactory::create_npc("Bear", "Honey", 100, 200);
    auto Knight = NPCFactory::create_npc("Knight", "Breon", 150, 250);
    
    std::stringstream ss;
    std::streambuf* orig_cout = std::cout.rdbuf(ss.rdbuf());  // Redirect std::cout to a stringstream

    Bear->attack(Knight.get());
    std::string expected_output = "Honey attacks Breon\n";
    EXPECT_EQ(ss.str(), expected_output);

    std::cout.rdbuf(orig_cout);
}

TEST(NPCAttackTest, test_01) {
    auto Orc = NPCFactory::create_npc("Orc", "Crusher", 200, 300);
    auto Bear = NPCFactory::create_npc("Bear", "Honey", 100, 200);
    
    std::stringstream ss;
    std::streambuf* orig_cout = std::cout.rdbuf(ss.rdbuf());  // Redirect std::cout to a stringstream

    Orc->attack(Bear.get());
    std::string expected_output = "Crusher attacks Honey\n";
    EXPECT_EQ(ss.str(), expected_output);

    // Restore original stdout
    std::cout.rdbuf(orig_cout);
}

// Test battle functionality
TEST(BattleVisitorTest, test_00) {
    auto Bear = NPCFactory::create_npc("Bear", "Honey", 100, 200);
    auto Knight = NPCFactory::create_npc("Knight", "Breon", 150, 250);
    BattleVisitor battle(100);  // Attack range of 100

    std::stringstream ss;
    std::streambuf* orig_cout = std::cout.rdbuf(ss.rdbuf());

    battle.visit(Bear.get(), Knight.get());

    EXPECT_EQ(ss.str(), "Honey attacks Breon\n");

    std::cout.rdbuf(orig_cout);
}

TEST(BattleVisitorTest, test_01) {
    auto Bear = NPCFactory::create_npc("Bear", "Honey", 100, 200);
    auto Orc = NPCFactory::create_npc("Orc", "Crusher", 400, 500);
    BattleVisitor battle(100);  // Attack range of 100

    std::stringstream ss;
    std::streambuf* orig_cout = std::cout.rdbuf(ss.rdbuf());

    battle.visit(Bear.get(), Orc.get());

    // No attack because they're out of range
    EXPECT_EQ(ss.str(), "");

    std::cout.rdbuf(orig_cout);
}

// Test Observer pattern functionality
TEST(ObserverPatternTest, test_00) {
    std::shared_ptr<FileObserver> fileObserver = std::make_shared<FileObserver>("test_log.txt");
    BattleArena arena(100);
    arena.add_observer(fileObserver);

    auto Bear = NPCFactory::create_npc("Bear", "Honey", 100, 200);
    auto Knight = NPCFactory::create_npc("Knight", "Breon", 150, 250);
    arena.add_npc(std::move(Bear));
    arena.add_npc(std::move(Knight));

    // Perform battle
    arena.battle();

    // Check the log file
    std::ifstream logFile("test_log.txt");
    std::string logLine;
    std::getline(logFile, logLine);

    EXPECT_EQ(logLine, "Battle occurred between Honey and Breon");
}

TEST(ObserverPatternTest, test_01) {
    std::shared_ptr<ScreenObserver> screenObserver = std::make_shared<ScreenObserver>();
    BattleArena arena(100);
    arena.add_observer(screenObserver);

    auto Bear = NPCFactory::create_npc("Bear", "Honey", 100, 200);
    auto Knight = NPCFactory::create_npc("Knight", "Breon", 150, 250);
    arena.add_npc(std::move(Bear));
    arena.add_npc(std::move(Knight));

    std::stringstream ss;
    std::streambuf* orig_cout = std::cout.rdbuf(ss.rdbuf());

    arena.battle();

    EXPECT_EQ(ss.str(), "Honey attacks Breon\nBattle occurred between Honey and Breon\n");

    std::cout.rdbuf(orig_cout);
}


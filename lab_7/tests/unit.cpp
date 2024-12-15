#include <gtest/gtest.h>
#include "../include/NPCFactory.hpp"

// Тесты
TEST(Test, test_00) {
    auto npc = NPCFactory::createNPC("Bear", "Honey", 100, 200);
    EXPECT_EQ(npc->get_name(), "Honey");
    EXPECT_EQ(npc->get_type(), "Bear");
}

TEST(Test, test_01) {
    auto npc = NPCFactory::createNPC("Orc", "Crusher", 200, 300);
    EXPECT_EQ(npc->get_name(), "Crusher");
    EXPECT_EQ(npc->get_type(), "Orc");
}

TEST(Test, test_02) {
    auto npc = NPCFactory::createNPC("Knight", "Breon", 300, 400);
    EXPECT_EQ(npc->get_name(), "Breon");
    EXPECT_EQ(npc->get_type(), "Knight");
}

TEST(Test, test_03) {
    auto npc = NPCFactory::createNPC("Orc", "Orc1", 100, 200);
    ASSERT_NE(npc, nullptr);
    EXPECT_EQ(npc->get_type(), "Orc");
    EXPECT_EQ(npc->get_name(), "Orc1");
    EXPECT_EQ(npc->x, 100);
    EXPECT_EQ(npc->y, 200);
}

TEST(Test, test_04) {
    std::string data = "Bear Bear1 300 400";
    auto npc = NPC::deserialize(data);
    ASSERT_NE(npc, nullptr);
    EXPECT_EQ(npc->get_type(), "Bear");
    EXPECT_EQ(npc->get_name(), "Bear1");
    EXPECT_EQ(npc->x, 300);
    EXPECT_EQ(npc->y, 400);
}

TEST(Test, test_05) {
    std::string data = "InvalidType Unknown 0 0";
    auto npc = NPC::deserialize(data);
    EXPECT_EQ(npc, nullptr);
}

TEST(Test, test_06) {
    auto npc1 = NPCFactory::createNPC("Knight", "Knight1", 100, 200);
    auto npc2 = NPCFactory::createNPC("Bear", "Bear1", 150, 250);

    double distance = npc1->distance_to(npc2.get());
    EXPECT_NEAR(distance, 70.7107, 0.0001);
}

TEST(Test, test_07) {
    std::vector<std::shared_ptr<NPC>> npcs;
    npcs.push_back(NPCFactory::createNPC("Orc", "Orc1", 100, 200));
    npcs.push_back(NPCFactory::createNPC("Bear", "Bear1", 150, 250));

    const std::string filename = "test_npcs.txt";
    save_npc_to_file(npcs, filename);

    std::vector<std::shared_ptr<NPC>> loadedNPCs = load_npc_from_file(filename);

    ASSERT_EQ(loadedNPCs.size(), 2);
    EXPECT_EQ(loadedNPCs[0]->get_type(), "Orc");
    EXPECT_EQ(loadedNPCs[1]->get_type(), "Bear");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

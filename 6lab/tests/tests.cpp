#include <gtest/gtest.h>
#include "../includes/bear.hpp"
#include "../includes/elf.hpp"
#include "../includes/robber.hpp"

TEST(test_01, task_test) {
    std::shared_ptr<Npc> bear = std::make_shared<Bear>("Bear", 5, 5);
    std::shared_ptr<Npc> elf = std::make_shared<Elf>("Elf", 3, 3);
    std::shared_ptr<Npc> robber = std::make_shared<Robber>("Robber", 4, 4);

    ASSERT_TRUE(elf->accept(bear));
    ASSERT_TRUE(robber->accept(elf));
    ASSERT_TRUE(robber->accept(robber));

    ASSERT_FALSE(bear->accept(bear));
    ASSERT_FALSE(bear->accept(elf));
    ASSERT_FALSE(bear->accept(robber));
    ASSERT_FALSE(elf->accept(elf));
    ASSERT_FALSE(elf->accept(robber));
    ASSERT_FALSE(robber->accept(bear));
}

TEST(test_02, is_close_method_test) {
    std::shared_ptr<Npc> bear = std::make_shared<Bear>("Bear", 5, 5);
    std::shared_ptr<Npc> elf = std::make_shared<Elf>("Elf", 3, 3);
    std::shared_ptr<Npc> robber = std::make_shared<Robber>("Robber", 4, 4);

    ASSERT_FALSE(bear->is_close(elf, 2));
    ASSERT_TRUE(bear->is_close(elf, 3));

    ASSERT_FALSE(robber->is_close(elf, 1));
    ASSERT_TRUE(robber->is_close(elf, 2));
}

TEST(test_03, print_methods_test1) {
    std::shared_ptr<Npc> bear = std::make_shared<Bear>("Bear", 5, 5);

    testing::internal::CaptureStdout();
    bear->print();
    std::string out = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << "Bear: {x: 5, y: 5}";
    std::string answer = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out, answer);
}

TEST(test_04, print_methods_test2) {
    std::shared_ptr<Npc> elf = std::make_shared<Elf>("Elf", 3, 3);

    testing::internal::CaptureStdout();
    elf->print();
    std::string out = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << "Elf: {x: 3, y: 3}";
    std::string answer = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out, answer);
}

TEST(test_05, print_methods_test3) {
    std::shared_ptr<Npc> robber = std::make_shared<Robber>("Robber", 4, 4);

    testing::internal::CaptureStdout();
    robber->print();
    std::string out = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << "Robber: {x: 4, y: 4}";
    std::string answer = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out, answer);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
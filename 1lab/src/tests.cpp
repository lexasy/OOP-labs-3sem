#include <gtest/gtest.h>
#include "task.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(task06("This website is for losers LOL!") == "Ths wbst s fr lsrs LL!");
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(task06("We hate this shit game!") == "W ht ths sht gm!");
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(task06("Does he remember what we said to him?") == "Ds h rmmbr wht w sd t hm?");
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(task06("We hate him, because he hates us!") == "W ht hm, bcs h hts s!");
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(task06("We don't remember they, because they are stupid guys!") == "W dn't rmmbr th, bcs th r stpd gs!");
}

TEST(test_06, basic_test_set)
{
    ASSERT_TRUE(task06("BRRRRrr!!!") == "BRRRRrr!!!");
}

TEST(test_07, basic_test_set)
{
    ASSERT_TRUE(task06("AAAAAaa!!!") == "!!!");
}

TEST(test_08, basic_test_set)
{
    ASSERT_TRUE(task06("") == "");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
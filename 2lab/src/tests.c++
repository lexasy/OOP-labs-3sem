#include <gtest/gtest.h>
#include "twelwe.h"


TEST(test_01, basic_test_set)
{
    ASSERT_TRUE((straddition("123AB", "123AB")) == "2479A");
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE((straddition("150", "BA3409A")) == "BA3422A");
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE((straddition("0", "1789AAAAAAB00")) == "1789AAAAAAB00");
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE((straddition("0", "0")) == "0");
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE((straddition("12", "35")) == "47");
}

TEST(test_06, basic_set_test)
{
    ASSERT_TRUE((strsubtraction("123AB", "123AB")) == "0");
}

TEST(test_07, basic_test_set) 
{
    ASSERT_TRUE((strsubtraction("0", "0")) == "0");
}

TEST(test_08, basic_test_set) 
{
    ASSERT_TRUE((strsubtraction("1209AB007", "ABBAABB")) == "1119B0108");
}

TEST(test_09, basic_test_set) 
{
    ASSERT_TRUE((strsubtraction("3321", "1231")) == "20B0");
}

TEST(test_10, basic_test_set) 
{
    ASSERT_TRUE((strsubtraction("12BB", "123AAB11")) == "Can't use negative numbers!");
}

TEST(test_11, basic_test_set) 
{
    ASSERT_TRUE((strmultiplication("123AB", "123AB")) == "15128B521");
}

TEST(test_12, basic_test_set) 
{
    ASSERT_TRUE((strmultiplication("12001ABBA", "0")) == "0");
}

TEST(test_13, basic_test_set) 
{
    ASSERT_TRUE((strmultiplication("0", "0")) == "0");
}

TEST(test_14, basic_test_set)
{
    ASSERT_TRUE((strmultiplication("123211ABBA09", "1")) == "123211ABBA09");
}

TEST(test_15, basic_test_set) 
{
    ASSERT_TRUE((strmultiplication("12312AABAA", "102AA")) == "1266770330A744");
}

TEST(test_16, basic_test_set)
{
    ASSERT_TRUE((strdivision("123AB", "123AB")) == "1");
}

TEST(test_17, basic_test_set) 
{
    ASSERT_TRUE((strdivision("0", "12BB12A907")) == "0");
}

TEST(test_18, basic_test_set)
{
    ASSERT_TRUE((strdivision("0", "0")) == "Division by zero!");
}

TEST(test_19, basic_test_set)
{
    ASSERT_TRUE((strdivision("12312AABAA", "102AA")) == "11B880");
}

TEST(test_20, basic_test_set)
{
    ASSERT_TRUE((strdivision("102AABB", "10000119384AB")) == "0");
}

TEST(test_21, basic_test_set)
{
    ASSERT_TRUE((strmpower("123AB", 2)) == "15128B521");
}

TEST(test_22, basic_test_set)
{
    ASSERT_TRUE((strmpower("120312AABB9", 0)) == "1");
}

TEST(test_23, basic_test_set)
{
    ASSERT_TRUE((strmpower("123AAB09A", 1)) == "123AAB09A");
}

TEST(test_24, basic_test_set)
{
    ASSERT_TRUE((strmpower("112", 5)) == "170BBBB9AA8");
}

TEST(test_25, basic_test_set)
{
    ASSERT_TRUE((strmpower("AABBAB", 2)) == "9B20A0420121");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
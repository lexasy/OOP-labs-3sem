#include <gtest/gtest.h>
#include "twelwe.h"

TEST(test_01, basic_test_set) // Default constructor test
{
    Twelwe num1;
    ASSERT_TRUE(num1.GetArrayPointer() == nullptr);
    ASSERT_TRUE(num1.GetArraySize() == 0);
}

TEST(test_02, basic_test_set) // Fill-array and copy constructor test
{
    Twelwe num1(5, 'A'); Twelwe num2(num1);
    ASSERT_TRUE(num1 == num2);
}

TEST(test_03, basic_test_set) // Copy string and initializer list constructor test
{
    Twelwe num1("123AB"); Twelwe num2 {'1', '2', '3', 'A', 'B'};
    ASSERT_TRUE(num1 == num2);
}

TEST(test_04, basic_test_set) // Move constructor test
{
    Twelwe num1("0123AB");
    size_t sz {num1.GetArraySize()};
    u_char arr[sz];
    for (size_t i {0}; i < sz; i++) {
        arr[i] = *(num1.GetArrayPointer() + i); 
    }
    Twelwe num2(std::move(num1));
    u_char arr1[num2.GetArraySize()];
    for (size_t i {0}; i < num2.GetArraySize(); i++) {
        arr1[i] = *(num2.GetArrayPointer() + i); 
    }
    ASSERT_TRUE(sz == num2.GetArraySize());
    for (size_t i {0}; i < sz; i++) {
        ASSERT_TRUE(arr[i] == arr1[i]);
    }
}

// Add method testds
TEST(test_05, basic_test_set) 
{
    Twelwe num1("0123AB"); Twelwe num2; Twelwe answer("123AB");
    Twelwe result = num1 + num2;
    ASSERT_TRUE(answer == result);
}

TEST(test_06, basic_test_set)
{
    Twelwe num1; Twelwe num2; Twelwe answer;
    Twelwe result = num1 + num2;
    ASSERT_TRUE(answer == result);

}

TEST(test_07, basic_test_set)
{
    Twelwe num1("000123AA0"); Twelwe num2("00000"); Twelwe answer("123AA0");
    Twelwe result = num1 + num2;
    ASSERT_TRUE(answer == result);
}

TEST(test_08, basic_test_set)
{
    Twelwe num1("123AB"); Twelwe num2("0123"); Twelwe answer("12512");
    Twelwe result = num1 + num2;
    ASSERT_TRUE(answer == result);
}

// Substraction method tests
TEST(test_09, basic_test_set)
{
    Twelwe num1("0123AB"); Twelwe num2; Twelwe answer("123AB");
    Twelwe result = num1 - num2;
    ASSERT_TRUE(answer == result);
}

TEST(test_10, basic_test_set)
{
    Twelwe num1("0123AB"); Twelwe num2("00123AB"); Twelwe answer("0");
    Twelwe result = num1 - num2;
    ASSERT_TRUE(answer == result);
}

TEST(test_11, basic_test_set)
{
    Twelwe num1("00000"); Twelwe num2("777");
    EXPECT_THROW(Twelwe result = num1 - num2, std::string);
}

TEST(test_12, basic_test_set)
{
    Twelwe num1("789AABB"); Twelwe num2("0000"); Twelwe answer("789AABB");
    Twelwe result = num1 - num2;
    ASSERT_TRUE(answer == result);
}

TEST(test_13, basic_test_set)
{
    Twelwe num1("1200ABA091"); Twelwe num2("12303A"); Twelwe answer("1200997053");
    Twelwe result = num1 - num2;
    ASSERT_TRUE(answer == result);
}

// Relation methods tests
TEST(test_14, basic_test_set)
{
    Twelwe num1; Twelwe num2("0000000");
    ASSERT_TRUE(num1 < num2);
}

TEST(test_15, basic_test_set)
{
    Twelwe num1("123AB"); Twelwe num2("00000000001A");
    ASSERT_FALSE(num1 < num2);
}

TEST(test_16, basic_test_set)
{
    Twelwe num1("123AB"); Twelwe num2("123AB");
    ASSERT_FALSE(num1 < num2);
}

TEST(test_17, basic_test_set)
{
    Twelwe num1; Twelwe num2;
    ASSERT_FALSE(num1 > num2);
}

TEST(test_18, basic_test_set)
{
    Twelwe num1("1234569AABB57565"); Twelwe num2("1234569AAAB57565");
    ASSERT_TRUE(num1 > num2);
}

TEST(test_19, basic_test_set)
{
    Twelwe num1("00000123AB"); Twelwe num2("123AB");
    ASSERT_FALSE(num1 > num2);
}

TEST(test_20, basic_test_set)
{
    Twelwe num1; Twelwe num2("00000000000000");
    ASSERT_FALSE(num1 == num2);
}

TEST(test_21, basic_test_set)
{
    Twelwe num1("01020A0B"); Twelwe num2("00000000000000000001020A0B");
    ASSERT_TRUE(num1 == num2);
}

TEST(test_22, basic_test_set)
{
    Twelwe num1; Twelwe num2;
    ASSERT_TRUE(num1 == num2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
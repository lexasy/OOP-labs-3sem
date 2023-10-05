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
    Twelwe num2(5, 'A'); Twelwe num3(num2);
    ASSERT_TRUE(num2.equals(num3) == true);
}

TEST(test_03, basic_test_set) // Copy string and initializer list constructor test
{
    Twelwe num4("123AB"); Twelwe num5 {'1', '2', '3', 'A', 'B'};
    ASSERT_TRUE(num4.equals(num5) == true);
}

TEST(test_04, basic_test_set) // Move constructor test
{
    Twelwe num6("0123AB");
    size_t sz6 {num6.GetArraySize()};
    u_char arr6[sz6];
    for (size_t i {0}; i < sz6; i++) {
        arr6[i] = *(num6.GetArrayPointer() + i); 
    }
    Twelwe num7(std::move(num6));
    u_char arr7[num7.GetArraySize()];
    for (size_t i {0}; i < num7.GetArraySize(); i++) {
        arr7[i] = *(num7.GetArrayPointer() + i); 
    }
    ASSERT_TRUE(sz6 == num7.GetArraySize());
    for (size_t i {0}; i < sz6; i++) {
        ASSERT_TRUE(arr6[i] == arr7[i]);
    }
}

// Add method testds
TEST(test_05, basic_test_set) 
{
    Twelwe num8("0123AB"); Twelwe num9; Twelwe answer1("123AB");
    Twelwe result1(num8.add(num9));
    ASSERT_TRUE(answer1.equals(result1) == true);
}

TEST(test_06, basic_test_set)
{
    Twelwe num10; Twelwe num11; Twelwe answer2;
    Twelwe result2(num10.add(num11));
    ASSERT_TRUE(answer2.equals(result2) == true);

}

TEST(test_07, basic_test_set)
{
    Twelwe num12("000123AA0"); Twelwe num13("00000"); Twelwe answer3("123AA0");
    Twelwe result3(num12.add(num13));
    ASSERT_TRUE(answer3.equals(result3) == true);
}

TEST(test_08, basic_test_set)
{
    Twelwe num14("123AB"); Twelwe num15("0123"); Twelwe answer4("12512");
    Twelwe result4(num14.add(num15));
    ASSERT_TRUE(answer4.equals(result4) == true);
}

// Substraction method tests
TEST(test_09, basic_test_set)
{
    Twelwe num16("0123AB"); Twelwe num17; Twelwe answer5("123AB");
    Twelwe result5(num16.substraction(num17));
    ASSERT_TRUE(answer5.equals(result5) == true);
}

TEST(test_10, basic_test_set)
{
    Twelwe num18("0123AB"); Twelwe num19("00123AB"); Twelwe answer6("0");
    Twelwe result6(num18.substraction(num19));
    ASSERT_TRUE(answer6.equals(result6) == true);
}

TEST(test_11, basic_test_set)
{
    Twelwe num20("00000"); Twelwe num21("777"); Twelwe answer7("0");
    EXPECT_THROW(Twelwe result7(num20.substraction(num21)), std::string);
}

TEST(test_12, basic_test_set)
{
    Twelwe num22("789AABB"); Twelwe num23("0000"); Twelwe answer8("789AABB");
    Twelwe result8(num22.substraction(num23));
    ASSERT_TRUE(answer8.equals(result8) == true);
}

TEST(test_13, basic_test_set)
{
    Twelwe num24("1200ABA091"); Twelwe num25("12303A"); Twelwe answer9("1200997053");
    Twelwe result9(num24.substraction(num25));
    ASSERT_TRUE(answer9.equals(result9) == true);
}

// Relation methods tests
TEST(test_14, basic_test_set)
{
    Twelwe num26; Twelwe num27("0000000");
    ASSERT_TRUE(num26.less(num27) == true);
}

TEST(test_15, basic_test_set)
{
    Twelwe num28("123AB"); Twelwe num29("00000000001A");
    ASSERT_TRUE(num28.less(num29) == false);
}

TEST(test_16, basic_test_set)
{
    Twelwe num30("123AB"); Twelwe num31("123AB");
    ASSERT_TRUE(num30.less(num31) == false);
}

TEST(test_17, basic_test_set)
{
    Twelwe num32; Twelwe num33;
    ASSERT_TRUE(num32.more(num33) == false);
}

TEST(test_18, basic_test_set)
{
    Twelwe num34("1234569AABB57565"); Twelwe num35("1234569AAAB57565");
    ASSERT_TRUE(num34.more(num35) == true);
}

TEST(test_19, basic_test_set)
{
    Twelwe num36("00000123AB"); Twelwe num37("123AB");
    ASSERT_TRUE(num36.more(num37) == false);
}

TEST(test_20, basic_test_set)
{
    Twelwe num38; Twelwe num39("00000000000000");
    ASSERT_TRUE(num38.equals(num39) == false);
}

TEST(test_21, basic_test_set)
{
    Twelwe num40("01020A0B"); Twelwe num41("00000000000000000001020A0B");
    ASSERT_TRUE(num40.equals(num41) == true);
}

TEST(test_22, basic_test_set)
{
    Twelwe num42; Twelwe num43;
    ASSERT_TRUE(num42.equals(num43) == true);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
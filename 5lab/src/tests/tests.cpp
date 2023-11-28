#include <gtest/gtest.h>
#include "../allocator.hpp"
#include "../dynamic_array.hpp"

TEST(test_01, container_default_constructor_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr;
    ASSERT_TRUE(arr.capacity() == 1);
    ASSERT_TRUE(arr.empty() == true);
}

TEST(test_02, container_expand_with_push_back_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr;
    ASSERT_TRUE(arr.capacity() == 1);
    arr.push_back(123);
    ASSERT_TRUE(arr[0] == 123);
    arr.push_back(125);
    ASSERT_TRUE((arr.capacity() == 2) && (arr[0] == 123) && (arr[1] == 125)); 
}

TEST(test_03, container_expand_with_emplace_back_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr;
    ASSERT_TRUE(arr.capacity() == 1);
    arr.emplace_back(123);
    ASSERT_TRUE(arr[0] == 123);
    arr.emplace_back(125);
    ASSERT_TRUE((arr.capacity() == 2) && (arr[0] == 123) && (arr[1] == 125)); 
}

TEST(test_04, container_shrink_with_pop_back_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr;
    for (std::size_t i = 0; i < 4; i++) {
        arr.push_back(i);
    }
    ASSERT_TRUE(arr.capacity() == 4);
    arr.pop_back(); arr.pop_back();
    ASSERT_TRUE((arr.capacity() == 2) && (arr[0] == 0) && (arr[1] == 1));
}

TEST(test_05, container_non_const_iterator_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr = {0, 1, 2, 3};
    auto it = arr.begin();
    for (int i = 0; i < 4; i++, ++it) {
        ASSERT_TRUE(*it == i);
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
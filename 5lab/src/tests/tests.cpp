#include <gtest/gtest.h>
#include <string>
#include <map>
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

TEST(test_03, container_expand_with_push_back_test) {
    my_nsp::Dynamic_array<double, my_nsp::Allocator<double, 10>> arr;
    ASSERT_TRUE(arr.capacity() == 1);
    arr.push_back(123);
    ASSERT_TRUE(arr[0] == 123);
    arr.push_back(125);
    ASSERT_TRUE((arr.capacity() == 2) && (arr[0] == 123) && (arr[1] == 125)); 
}

TEST(test_04, container_expand_with_emplace_back_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr;
    ASSERT_TRUE(arr.capacity() == 1);
    arr.emplace_back(123);
    ASSERT_TRUE(arr[0] == 123);
    arr.emplace_back(125);
    ASSERT_TRUE((arr.capacity() == 2) && (arr[0] == 123) && (arr[1] == 125)); 
}

TEST(test_05, container_expand_with_emplace_back_test) {
    my_nsp::Dynamic_array<double, my_nsp::Allocator<double, 10>> arr;
    ASSERT_TRUE(arr.capacity() == 1);
    arr.emplace_back(123);
    ASSERT_TRUE(arr[0] == 123);
    arr.emplace_back(125);
    ASSERT_TRUE((arr.capacity() == 2) && (arr[0] == 123) && (arr[1] == 125)); 
}

TEST(test_06, container_shrink_with_pop_back_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr;
    for (std::size_t i = 0; i < 4; i++) {
        arr.push_back(i);
    }
    ASSERT_TRUE(arr.capacity() == 4);
    arr.pop_back(); arr.pop_back();
    ASSERT_TRUE((arr.capacity() == 2) && (arr[0] == 0) && (arr[1] == 1));
}

TEST(test_07, container_shrink_with_pop_back_test) {
    my_nsp::Dynamic_array<double, my_nsp::Allocator<double, 10>> arr;
    for (std::size_t i = 0; i < 4; i++) {
        arr.push_back(i);
    }
    ASSERT_TRUE(arr.capacity() == 4);
    arr.pop_back(); arr.pop_back();
    ASSERT_TRUE((arr.capacity() == 2) && (arr[0] == 0) && (arr[1] == 1));
}

TEST(test_08, container_non_const_iterator_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr = {0, 1, 2, 3};
    auto it = arr.begin();
    for (int i = 0; i < 4; i++, it++) {
        ASSERT_TRUE(*it == i);
    }
    auto it1 = arr.begin();
    ++it1; *it1 = 123;
    ASSERT_TRUE(arr[1] == 123);
}

TEST(test_09, container_const_iterator_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr = {0, 1, 2, 3};
    auto it = arr.cbegin();
    for (int i = 0; i < 4; i++, it++) {
        ASSERT_TRUE(*it == i);
    }
}

TEST(test_10, container_insert_method_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr = {0, 1, 2, 3};
    auto it = arr.cbegin();
    it++;
    arr.insert(it, 123);
    testing::internal::CaptureStdout();
    arr.print();
    std::string out = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << 0 << " " << 123 << " " << 1 << " " << 2 << " " << 3 << " ";
    std::string answer = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out, answer);
}

TEST(test_11, container_insert_method_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr = {0, 1, 2, 3};
    auto it = arr.cbegin();
    arr.insert(it, 123);
    testing::internal::CaptureStdout();
    arr.print();
    std::string out = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << 123 << " " << 0 << " " << 1 << " " << 2 << " " << 3 << " ";
    std::string answer = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out, answer);
}

TEST(test_12, container_insert_method_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr = {0, 1, 2, 3};
    auto it = arr.cend();
    arr.insert(it, 123);
    testing::internal::CaptureStdout();
    arr.print();
    std::string out = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << 0 << " " << 1 << " " << 2 << " " << 3 << " " << 123 << " ";
    std::string answer = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out, answer);
    it++;
    arr.insert(it, 1234);
    testing::internal::CaptureStdout();
    arr.print();
    std::string out1 = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << 0 << " " << 1 << " " << 2 << " " << 3 << " " << 123 << " " << 1234 << " ";
    std::string answer1 = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out1, answer1);
}

TEST(test_13, container_insert_method_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr;
    auto it1 = arr.cbegin();
    arr.insert(it1, 123);
    ASSERT_TRUE(arr[0] == 123);
    arr.pop_back();
    ASSERT_TRUE(arr.empty() == true);
    auto it2 = arr.cend();
    arr.insert(it2, 123);
    ASSERT_TRUE(arr[0] == 123);
    it2++;
    arr.insert(it2, 1234);
    testing::internal::CaptureStdout();
    arr.print();
    std::string out = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << 123 << " " << 1234 << " ";
    std::string answer = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out, answer);
    arr.insert(it1, 12);
    testing::internal::CaptureStdout();
    arr.print();
    std::string out1 = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << 12 << " " << 123 << " " << 1234 << " ";
    std::string answer1 = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out1, answer1);
}

TEST(test_14, container_emplace_method_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr = {0, 1, 2, 3};
    auto it = arr.cbegin();
    it++;
    arr.emplace(it, 123);
    testing::internal::CaptureStdout();
    arr.print();
    std::string out = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << 0 << " " << 123 << " " << 1 << " " << 2 << " " << 3 << " ";
    std::string answer = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out, answer);
}

TEST(test_15, container_emplace_method_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr = {0, 1, 2, 3};
    auto it = arr.cbegin();
    arr.emplace(it, 123);
    testing::internal::CaptureStdout();
    arr.print();
    std::string out = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << 123 << " " << 0 << " " << 1 << " " << 2 << " " << 3 << " ";
    std::string answer = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out, answer);
}

TEST(test_16, container_emplace_method_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr = {0, 1, 2, 3};
    auto it = arr.cend();
    arr.emplace(it, 123);
    testing::internal::CaptureStdout();
    arr.print();
    std::string out = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << 0 << " " << 1 << " " << 2 << " " << 3 << " " << 123 << " ";
    std::string answer = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out, answer);
    it++;
    arr.emplace(it, 1234);
    testing::internal::CaptureStdout();
    arr.print();
    std::string out1 = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << 0 << " " << 1 << " " << 2 << " " << 3 << " " << 123 << " " << 1234 << " ";
    std::string answer1 = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out1, answer1);
}

TEST(test_17, container_emplace_method_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr;
    auto it1 = arr.cbegin();
    arr.emplace(it1, 123);
    ASSERT_TRUE(arr[0] == 123);
    arr.pop_back();
    ASSERT_TRUE(arr.empty() == true);
    auto it2 = arr.cend();
    arr.emplace(it2, 123);
    ASSERT_TRUE(arr[0] == 123);
    it2++;
    arr.emplace(it2, 1234);
    testing::internal::CaptureStdout();
    arr.print();
    std::string out = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << 123 << " " << 1234 << " ";
    std::string answer = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out, answer);
    arr.emplace(it1, 12);
    testing::internal::CaptureStdout();
    arr.print();
    std::string out1 = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << 12 << " " << 123 << " " << 1234 << " ";
    std::string answer1 = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out1, answer1);
}

TEST(test_18, container_erase_method_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr = {0, 1, 2, 3};
    auto it = arr.cbegin();
    std::size_t tmp_size = arr.size();
    for (std::size_t i = 0; i < tmp_size; i++) {
        arr.erase(it);
    }
    ASSERT_TRUE(arr.empty());
}

TEST(test_19, container_shrink_to_fit_method_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr = {0, 1, 2, 3, 4, 5};
    ASSERT_TRUE(arr.capacity() == 8);
    arr.shrink_to_fit();
    ASSERT_TRUE(arr.capacity() == arr.size());
    testing::internal::CaptureStdout();
    arr.print();
    std::string out = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << 0 << " " << 1 << " " << 2 << " " << 3 << " " << 4 << " " << 5 << " ";
    std::string answer = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out, answer);
}

TEST(test_20, container_shrink_to_fit_method_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr = {0};
    arr.pop_back();
    ASSERT_TRUE((arr.size() == 0) && (arr.capacity() == 1));
    arr.shrink_to_fit();
    ASSERT_TRUE(arr.capacity() == 0);
    arr.push_back(123);
    ASSERT_TRUE((arr.size() == 1) && (arr.capacity() == 1) && (arr[0] == 123));
}

TEST(test_21, container_pop_back_method_exception_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr;
    EXPECT_THROW(arr.pop_back(), std::logic_error);
}

TEST(test_22, container_erase_method_exception_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr;
    auto it = arr.cbegin();
    EXPECT_THROW(arr.erase(it), std::logic_error);
}

TEST(test_23, iterator_increment_method_exception_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr;
    auto it = arr.end();
    EXPECT_THROW(it++, std::logic_error);
}

TEST(test_24, const_iterator_increment_method_exception_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr;
    auto it = arr.cend();
    EXPECT_THROW(it++, std::logic_error);
}

TEST(test_25, memory_allocate_exception_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 8>> arr = {0, 1, 2, 3, 4, 5, 6, 7};
    EXPECT_THROW(arr.push_back(123), std::bad_alloc);
}

TEST(test_26, container_clear_method_test) {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 8>> arr = {0, 1, 2, 3, 4, 5, 6, 7};
    arr.clear();
    ASSERT_TRUE(arr.empty());
}

TEST(test_27, container_other_template_types_test) {
    my_nsp::Dynamic_array<char, my_nsp::Allocator<char, 4>> arr;
    arr.push_back('a'); arr.push_back('b'); arr.push_back('c'); arr.push_back('d');
    testing::internal::CaptureStdout();
    arr.print();
    std::string out = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << "a b c d ";
    std::string answer = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out, answer);
    arr.pop_back();
    testing::internal::CaptureStdout();
    arr.print();
    std::string out1 = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << "a b c ";
    std::string answer1 = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out1, answer1);
    auto it = arr.cbegin();
    arr.erase(it);
    testing::internal::CaptureStdout();
    arr.print();
    std::string out2 = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << "b c ";
    std::string answer2 = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out2, answer2);
    it++; it++;
    arr.insert(it, 'a');
    testing::internal::CaptureStdout();
    arr.print();
    std::string out3 = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << "b c a ";
    std::string answer3 = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out3, answer3);
    auto it1 = arr.cend();
    arr.insert(it1, 'd');
    testing::internal::CaptureStdout();
    arr.print();
    std::string out4 = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << "b c a d ";
    std::string answer4 = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out4, answer4);
}

TEST(test_28, container_other_template_types_test) {
    my_nsp::Dynamic_array<double, my_nsp::Allocator<double, 4>> arr;
    arr.push_back(3.14); arr.push_back(3.15); arr.push_back(3.16); arr.push_back(3.17);
    testing::internal::CaptureStdout();
    arr.print();
    std::string out = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << 3.14 << " " << 3.15 << " " << 3.16 << " " << 3.17 << " ";
    std::string answer = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out, answer);
    arr.pop_back();
    testing::internal::CaptureStdout();
    arr.print();
    std::string out1 = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << 3.14 << " " << 3.15 << " " << 3.16 << " ";
    std::string answer1 = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out1, answer1);
    auto it = arr.cbegin();
    arr.erase(it);
    testing::internal::CaptureStdout();
    arr.print();
    std::string out2 = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << 3.15 << " " << 3.16 << " ";
    std::string answer2 = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out2, answer2);
    it++; it++;
    arr.insert(it, 3.14);
    testing::internal::CaptureStdout();
    arr.print();
    std::string out3 = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << 3.15 << " " << 3.16 << " " << 3.14 << " ";
    std::string answer3 = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out3, answer3);
    auto it1 = arr.cend();
    arr.insert(it1, 3.17);
    testing::internal::CaptureStdout();
    arr.print();
    std::string out4 = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << 3.15 << " " << 3.16 << " " << 3.14 << " " << 3.17 << " ";
    std::string answer4 = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out4, answer4);
}

TEST(test_29, stl_vector_with_custom_allocator_test) {
    std::vector<int, my_nsp::Allocator<int, 10>> arr;
    for (std::size_t i = 0; i < 4; i++) {
        arr.emplace_back(i);
    }
    testing::internal::CaptureStdout();
    for (std::size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::string out = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << 0 << " " << 1 << " " << 2 << " " << 3 << " ";
    std::string answer = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out, answer);
    for (std::size_t i = 0; i < 3; i++) {
        arr.pop_back();
    }
    testing::internal::CaptureStdout();
    for (std::size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::string out1 = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << 0 << " ";
    std::string answer1 = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out1, answer1);
    for (std::size_t i = 1; i < 4; i++) {
        arr.push_back(i);
    }
    testing::internal::CaptureStdout();
    for (std::size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::string out2 = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << 0 << " " << 1 << " " << 2 << " " << 3 << " ";
    std::string answer2 = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out2, answer2);
}

TEST(test_30, stl_map_with_custom_allocator_test) {
    std::map<int, int, std::less<int>, my_nsp::Allocator<std::pair<const int, int>, 10>> mp;
    for (std::size_t i = 0; i < 5; i++) {
        mp[i] = i * i;
    }
    testing::internal::CaptureStdout();
    for (auto i : mp) {
        std::cout << i.first << " " << i.second << "\n";
    }
    std::string out = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << 0 << " " << 0 << "\n";
    std::cout << 1 << " " << 1 << "\n";
    std::cout << 2 << " " << 4 << "\n";
    std::cout << 3 << " " << 9 << "\n";
    std::cout << 4 << " " << 16 << "\n";
    std::string answer = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out, answer);
    std::map<int, char, std::less<int>, my_nsp::Allocator<std::pair<const int, char>, 10>> mp1;
    for (std::size_t i = 0; i < 5; i++) {
        mp1[i] = 'a' + i;
    }
    testing::internal::CaptureStdout();
    for (auto i : mp1) {
        std::cout << i.first << " " << i.second << "\n";
    }
    std::string out1 = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    std::cout << 0 << " " << 'a' << "\n";
    std::cout << 1 << " " << 'b' << "\n";
    std::cout << 2 << " " << 'c' << "\n";
    std::cout << 3 << " " << 'd' << "\n";
    std::cout << 4 << " " << 'e' << "\n";
    std::string answer1 = testing::internal::GetCapturedStdout();
    ASSERT_EQ(out1, answer1); 
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
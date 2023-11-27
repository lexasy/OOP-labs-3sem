#include "allocator.hpp"
#include "dynamic_array.hpp"
#include <iostream>
#include <vector>

int main() {
    // std::vector<int, my_nsp::Allocator<int, 8>> arr;
    // // std::vector<int> arr;
    // for (std::size_t i = 0; i < 4; i++) {
    //     arr.push_back(i);
    //     std::cout << arr.capacity() << "\n";
    // }
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 16>> arr;
    for (std::size_t i = 0; i < 4; i++) {
        arr.emplace_back(i);
    }
    // auto it = arr.begin();
    // ++it;
    // it = arr.emplace(it, 123);
    // arr.clear();
    // std::cout << arr.size() << "\n";
    auto it = arr.end();
    it = arr.erase(it);
    arr.push_back(123);
    auto it1 = arr.end();
    // arr.pop_back();
    arr.erase(it1);
    auto it2 = arr.begin();
    arr.insert(it2, 123);
    arr.push_back(124);
    ++it2;
    arr.erase(it2);
    for (std::size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
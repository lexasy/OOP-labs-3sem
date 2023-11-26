#include "allocator.hpp"
#include "dynamic_array.hpp"
#include <iostream>

int main() {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 16>> arr;
    for (std::size_t i = 0; i < 4; i++) {
        arr.push_back(i);
        std::cout << arr.capacity() << "\n";
    }
    auto it = arr.end();
    it = arr.erase(it);
    for (std::size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
#include "allocator.hpp"
#include "dynamic_array.hpp"
#include <iostream>

int main() {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 16>> arr;
    for (std::size_t i = 0; i < 16; i++) {
        arr.push_back(i);
    }
    auto it = arr.end();
    std::cout << *it << "\n";
}
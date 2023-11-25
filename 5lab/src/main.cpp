#include "allocator.hpp"
#include "dynamic_array.hpp"
#include <iostream>

int main() {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr;
    for (std::size_t i = 0; i < 1; i++) {
        arr.push_back(i);
    }
    // arr.pop_back();
    std::cout << arr[0] << "\n";
}
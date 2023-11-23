#include "allocator.hpp"
#include "dynamic_array.hpp"
#include <iostream>

int main() {
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 10>> arr;
    arr.push_back(3);
    arr.push_back(4);
    // arr.pop_back();
    std::cout << arr[0] << " " << arr[1] << "\n";
}
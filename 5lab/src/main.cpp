#include "allocator.hpp"
#include "dynamic_array.hpp"
#include <iostream>
#include <vector>
#include <map>

template <int N>
int factorial()
{
    return N * factorial<N - 1>();
}
template <>
int factorial<0>()
{
    return 1;
}

using map_type_with_allocator =
    std::map<int, int, std::less<int>, my_nsp::Allocator<std::pair<const int, int>, 10>>;

template <int N>
void fill_map(map_type_with_allocator &map)
{
    map.insert(std::pair<int, int>(N, factorial<N>()));
    fill_map<N - 1>(map);
}

template <>
void fill_map<0>(map_type_with_allocator &map)
{
    map.insert(std::pair<int, int>(0, factorial<0>()));
}

int main() {
    map_type_with_allocator my_map_with_allocator;
    fill_map<9>(my_map_with_allocator);
    std::cout << "FACTORIAL MAP WITH CUSTOM ALLOCATOR" << "\n";
    for (auto p : my_map_with_allocator)
        std::cout << p.first << " " << p.second << std::endl;
    // std::vector<int, my_nsp::Allocator<int, 8>> arr;
    // // std::vector<int> arr;
    // for (std::size_t i = 0; i < 4; i++) {
    //     arr.push_back(i);
    //     std::cout << arr.capacity() << "\n";
    // }
    std::cout << "FILLING CUSTOM DYNAMIC ARRAY WITH CUSTOM ALLOCATOR" << "\n";
    my_nsp::Dynamic_array<int, my_nsp::Allocator<int, 16>> arr;
    for (std::size_t i = 0; i < 16; i++) {
        arr.emplace_back(i);
    }
    // auto it = arr.begin();
    // ++it;
    // it = arr.emplace(it, 123);
    // arr.clear();
    // std::cout << arr.size() << "\n";
    // auto it = arr.end();
    // it = arr.erase(it);
    // arr.push_back(123);
    // auto it1 = arr.end();
    // // arr.pop_back();
    // arr.erase(it1);
    // auto it2 = arr.begin();
    // arr.insert(it2, 123);
    // arr.push_back(124);
    // ++it2;
    // arr.erase(it2);
    for (std::size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
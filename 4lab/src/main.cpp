#include "includes/pentagon.hpp"
#include "includes/hexagon.hpp"
#include "includes/octagon.hpp"

int main() {
    Point<int> pt1(1, 1); Point<int> pt2(1, 1); Point<int> pt3(1, 1); Point<int> pt4(1, 1); Point<int> pt5(1, 1);
    std::cout << length_btw_points(pt1,  pt2) << "\n";
    // Pentagon<int> pent;  std::cin >> pent; std::cout << pent;
}
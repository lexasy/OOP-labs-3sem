#include "includes/figure.hpp"

void Figure::print_coords() {
    std::cout << "Coordinates of " << this->return_type() << ":\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Point" << i + 1 << ": " << points[i];
    }
}

void Figure::read_coords() {
    std::cout << "Please type in the coordinates of points of your " << this->return_type() << ", order [x,y], separated by spaces:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Point" << i + 1 << ": "; std::cin >> points[i];
    }
}
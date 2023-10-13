#include "includes/figure.hpp"

Point Figure::geometrical_centre() const {
    Point result;
    for (int i = 0; i < n; i++) {
        result.x += points[i].x;
        result.y += points[i].y;
    }
    result.x /= n; result.y /= n;
    return result;
}

float Figure::area() const {
    return (n * length_btw_points(points[1], points[0]) * length_btw_points(points[1], points[0]) / 4) * (1 / tan(M_PI / n));
}

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
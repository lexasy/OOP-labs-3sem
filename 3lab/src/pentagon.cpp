#include "includes/pentagon.hpp"

Point Pentagon::geometrical_centre() const {
    Point result;
    result.x = (p1.x + p2.x + p3.x + p4.x + p5.x) / 5;
    result.y = (p1.y + p2.y + p3.y + p4.y + p5.y) / 5;
    return result;
}

void Pentagon::print_coords() {
    std::cout << "Coordinates of your pentagon:\n";
    std::cout << "         X  Y\n";
    std::cout << "Point1: " << p1;
    std::cout << "Point2: " << p2;
    std::cout << "Point3: " << p3;
    std::cout << "Point4: " << p4;
    std::cout << "Point5: " << p5;
}

void Pentagon::read_coords() {
    std::cout << "Please type in the coordinates of points of your pentagon, order [x,y], separated by spaces:\n";
    std::cout << "        X Y\n";
    std::cout << "Point1: "; std::cin >> p1;
    std::cout << "Point2: "; std::cin >> p2;
    std::cout << "Point3: "; std::cin >> p3;
    std::cout << "Point4: "; std::cin >> p4;
    std::cout << "Point5: "; std::cin >> p5;
}

double Pentagon::area() const {
    return (1 / 4) * sqrt(5 * (5 + 2 * sqrt(5))) * pow(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2), 2);
}

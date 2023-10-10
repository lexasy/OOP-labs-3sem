#include "includes/hexagon.hpp"

Hexagon::Hexagon(Point& pt1, Point& pt2, Point& pt3, Point& pt4, Point& pt5, Point& pt6) {
    p1 = pt1; p2 = pt2; p3 = pt3; p4 = pt4; p5 = pt5; p6 = pt6;
}

Point Hexagon::geometrical_centre() const {
    Point result;
    result.x = (p1.x + p2.x + p3.x + p4.x + p5.x + p6.x) / 6;
    result.y = (p1.y + p2.y + p3.y + p4.y + p5.y + p6.y) / 6;
    return result;
}

void Hexagon::print_coords() {
    std::cout << "Coordinates of your hexagon:\n";
    std::cout << "         X  Y\n";
    std::cout << "Point1: " << p1;
    std::cout << "Point2: " << p2;
    std::cout << "Point3: " << p3;
    std::cout << "Point4: " << p4;
    std::cout << "Point5: " << p5;
    std::cout << "Point6: " << p6;
}

void Hexagon::read_coords() {
    std::cout << "Please type in the coordinates of points of your hexagon, order [x,y], separated by spaces:\n";
    std::cout << "        X Y\n";
    std::cout << "Point1: "; std::cin >> p1;
    std::cout << "Point2: "; std::cin >> p2;
    std::cout << "Point3: "; std::cin >> p3;
    std::cout << "Point4: "; std::cin >> p4;
    std::cout << "Point5: "; std::cin >> p5;
    std::cout << "Point6: "; std::cin >> p6;
}

double Hexagon::area() const {
    return (3 * sqrt(3) * pow(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2), 2)) / 2;
}

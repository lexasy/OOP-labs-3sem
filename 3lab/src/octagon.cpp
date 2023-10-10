#include "includes/octagon.hpp"

Octagon::Octagon(Point& pt1, Point& pt2, Point& pt3, Point& pt4, Point& pt5, Point& pt6, Point& pt7, Point& pt8) {
    p1 = pt1; p2 = pt2; p3 = pt3; p4 = pt4; p5 = pt5; p6 = pt6; p7 = pt7; p8 = pt8;
}

Point Octagon::geometrical_centre() const {
    Point result;
    result.x = (p1.x + p2.x + p3.x + p4.x + p5.x + p6.x + p7.x + p8.x) / 8;
    result.y = (p1.y + p2.y + p3.y + p4.y + p5.y + p6.y + p7.y + p8.y) / 8;
    return result;
}

void Octagon::print_coords() {
    std::cout << "Coordinates of your octagon:\n";
    std::cout << "Point1: " << p1;
    std::cout << "Point2: " << p2;
    std::cout << "Point3: " << p3;
    std::cout << "Point4: " << p4;
    std::cout << "Point5: " << p5;
    std::cout << "Point6: " << p6;
    std::cout << "Point7: " << p7;
    std::cout << "Point8: " << p8;
}

void Octagon::read_coords() {
    std::cout << "Please type in the coordinates of points of your octagon, order [x,y], separated by spaces:\n";
    std::cout << "Point1: "; std::cin >> p1;
    std::cout << "Point2: "; std::cin >> p2;
    std::cout << "Point3: "; std::cin >> p3;
    std::cout << "Point4: "; std::cin >> p4;
    std::cout << "Point5: "; std::cin >> p5;
    std::cout << "Point6: "; std::cin >> p6;
    std::cout << "Point7: "; std::cin >> p7;
    std::cout << "Point8: "; std::cin >> p8;
}

double Octagon::area() const {
    return 2 * pow(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2), 2) * (1 + sqrt(2));
}

#include "includes/octagon.hpp"

Octagon::Octagon(Point& pt1, Point& pt2, Point& pt3, Point& pt4, Point& pt5, Point& pt6, Point& pt7, Point& pt8) {
    p1 = pt1; p2 = pt2; p3 = pt3; p4 = pt4; p5 = pt5; p6 = pt6; p7 = pt7; p8 = pt8;
}

Point Octagon::geometrical_centre() const {
    Point result;
    result.x = (p1.x + p2.x + p3.x + p4.x + p5.x + p6.x + p7.x - p8.x + p8.x + p8.x) / 8; // KOSTYL.net
    result.y = (p1.y + p2.y + p3.y + p4.y + p5.y + p6.y + p7.y + p8.y - p2.y + p2.y) / 8; // KOSTYL.net
    return result;
}

void Octagon::print_coords() {
    std::cout << "Coordinates of octagon:\n";
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
    return abs(p1.x * p2.y + p2.x * p3.y + p3.x * p4.y + p4.x * p5.y + p5.x * p6.y + p6.x * p7.y + p7.x * p8.y + p8.x * p1.y - p2.x * p1.y - p3.x * p2.y - p4.x * p3.y - p5.x * p4.y - p6.x * p5.y - p7.x * p6.y - p8.x * p7.x - p1.x * p8.y) / 2;
}

std::string Octagon::return_type() const {
    return {"Octagon"};
}

void Octagon::operator=(const Octagon& fig) {
    this->p1 = fig.p1; this->p2 = fig.p2; this->p3 = fig.p3; this->p4 = fig.p4; this->p5 = fig.p5; this->p6 = fig.p6; this->p7 = fig.p7; this->p8 = fig.p8;
}

void Octagon::operator=(Octagon&& fig) {
    this->p1 = fig.p1; this->p2 = fig.p2; this->p3 = fig.p3; this->p4 = fig.p4; this->p5 = fig.p5; this->p6 = fig.p6; this->p7 = fig.p7; this->p8 = fig.p8;
    fig.p1 = 0; fig.p2 = 0; fig.p3 = 0; fig.p4 = 0; fig.p5 = 0; fig.p6 = 0; fig.p7 = 0; fig.p8 = 0;
}

bool Octagon::operator==(const Octagon& fig) const {
    return this->area() == fig.area();
}
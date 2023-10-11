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
    std::cout << "Coordinates of hexagon:\n";
    std::cout << "Point1: " << p1;
    std::cout << "Point2: " << p2;
    std::cout << "Point3: " << p3;
    std::cout << "Point4: " << p4;
    std::cout << "Point5: " << p5;
    std::cout << "Point6: " << p6;
}

void Hexagon::read_coords() {
    std::cout << "Please type in the coordinates of points of your hexagon, order [x,y], separated by spaces:\n";
    std::cout << "Point1: "; std::cin >> p1;
    std::cout << "Point2: "; std::cin >> p2;
    std::cout << "Point3: "; std::cin >> p3;
    std::cout << "Point4: "; std::cin >> p4;
    std::cout << "Point5: "; std::cin >> p5;
    std::cout << "Point6: "; std::cin >> p6;
}

double Hexagon::area() const {
    return abs(p1.x * p2.y + p2.x * p3.y + p3.x * p4.y + p4.x * p5.y + p5.x * p6.y + p6.x * p1.y - p2.x * p1.y - p3.x * p2.y - p4.x * p3.y - p5.x * p4.y - p6.x * p5.y - p1.x * p6.y) / 2;
}

std::string Hexagon::return_type() const {
    return {"Hexagon"};
}

void Hexagon::operator=(const Hexagon& fig) {
    this->p1 = fig.p1; this->p2 = fig.p2; this->p3 = fig.p3; this->p4 = fig.p4; this->p5 = fig.p5; this->p6 = fig.p6;
}

void Hexagon::operator=(Hexagon&& fig) {
    this->p1 = fig.p1; this->p2 = fig.p2; this->p3 = fig.p3; this->p4 = fig.p4; this->p5 = fig.p5; this->p6 = fig.p6;
    fig.p1 = 0; fig.p2 = 0; fig.p3 = 0; fig.p4 = 0; fig.p5 = 0; fig.p6 = 0;
}

bool Hexagon::operator==(const Hexagon& fig) const {
    return this->area() == fig.area();
}
#include "includes/pentagon.hpp"

Pentagon::Pentagon(Point& pt1, Point& pt2, Point& pt3, Point& pt4, Point& pt5) {
    p1 = pt1; p2 = pt2; p3 = pt3; p4 = pt4; p5 = pt5;
}

Point Pentagon::geometrical_centre() const {
    Point result;
    result.x = (p1.x + p2.x + p3.x + p4.x + p5.x) / 5;
    result.y = (p1.y + p2.y + p3.y + p4.y + p5.y) / 5;
    return result;
}

void Pentagon::print_coords() {
    std::cout << "Coordinates of pentagon:\n";
    std::cout << "Point1: " << p1;
    std::cout << "Point2: " << p2;
    std::cout << "Point3: " << p3;
    std::cout << "Point4: " << p4;
    std::cout << "Point5: " << p5;
}

void Pentagon::read_coords() {
    std::cout << "Please type in the coordinates of points of your pentagon, order [x,y], separated by spaces:\n";
    std::cout << "Point1: "; std::cin >> p1;
    std::cout << "Point2: "; std::cin >> p2;
    std::cout << "Point3: "; std::cin >> p3;
    std::cout << "Point4: "; std::cin >> p4;
    std::cout << "Point5: "; std::cin >> p5;
}

double Pentagon::area() const {
    return abs(p1.x * p2.y + p2.x * p3.y + p3.x * p4.y + p4.x * p5.y + p5.x * p1.y - p2.x * p1.y - p3.x * p2.y - p4.x * p3.y - p5.x * p4.y - p1.x * p5.y) / 2;
}

std::string Pentagon::return_type() const {
    return {"Pentagon"};
}

void Pentagon::operator=(const Pentagon& fig) {
    this->p1 = fig.p1; this->p2 = fig.p2; this->p3 = fig.p3; this->p4 = fig.p4; this->p5 = fig.p5;
}

void Pentagon::operator=(Pentagon&& fig) {
    this->p1 = fig.p1; this->p2 = fig.p2; this->p3 = fig.p3; this->p4 = fig.p4; this->p5 = fig.p5;
    fig.p1 = 0; fig.p2 = 0; fig.p3 = 0; fig.p4 = 0; fig.p5 = 0;
}

bool Pentagon::operator==(const Pentagon& fig) const {
    return this->area() == fig.area();
}

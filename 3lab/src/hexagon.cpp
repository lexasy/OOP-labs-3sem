#include "includes/figures.hpp"

Hexagon::Hexagon() {
    p1 = new point; p2 = new point; p3 = new point; p4 = new point; p5 = new point; p6 = new point;
}

point *Hexagon::geometrical_centre() const {
    point *result = new point;
    result->x = (p1->x + p2->x + p3->x + p4->x + p5->x + p6->x) / 6;
    result->y = (p1->y + p2->y + p3->y + p4->y + p5->y + p6->y) / 6;
    return result;
}

double Hexagon::area() const {
    return (3 * sqrt(3) * pow(pow(p2->x - p1->x, 2) + pow(p2->y - p2->y, 2), 2)) / 2;
}

Hexagon::~Hexagon() {
    delete p1; delete p2; delete p3; delete p4; delete p5; delete p6;
}
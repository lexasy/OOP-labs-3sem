#include "includes/figures.hpp"

Octagon::Octagon() {
    p1 = new point; p2 = new point; p3 = new point; p4 = new point; p5 = new point; p6 = new point; p7 = new point; p8 = new point;
}

point *Octagon::geometrical_centre() const {
    point *result = new point;
    result->x = (p1->x + p2->x + p3->x + p4->x + p5->x + p6->x + p7->x + p8->x) / 8;
    result->y = (p1->y + p2->y + p3->y + p4->y + p5->y + p6->y + p7->y + p8->y) / 8;
    return result;
}

double Octagon::area() const {
    return 2 * pow(pow(p2->x - p1->x, 2) + pow(p2->y - p2->y, 2), 2) * (1 + sqrt(2));
}

Octagon::~Octagon() {
    delete p1; delete p2; delete p3; delete p4; delete p5; delete p6; delete p7; delete p8;
}
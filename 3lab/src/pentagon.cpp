#include "includes/figures.hpp"

Pentagon::Pentagon() {
    p1 = new point; p2 = new point; p3 = new point; p4 = new point; p5 = new point;
}

point *Pentagon::geometrical_centre() const {
    point *result = new point;
    result->x = (p1->x + p2->x + p3->x + p4->x + p5->x) / 5;
    result->y = (p1->y + p2->y + p3->y + p4->y + p5->y) / 5;
    return result;
}

double Pentagon::area() const {
    return (1 / 4) * sqrt(5 * (5 + 2 * sqrt(5))) * pow(pow(p2->x - p1->x, 2) + pow(p2->y - p2->y, 2), 2);
}

Pentagon::~Pentagon() {
    delete p1; delete p2; delete p3; delete p4; delete p5;
}
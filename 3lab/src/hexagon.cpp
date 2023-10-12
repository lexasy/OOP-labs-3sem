#include "includes/hexagon.hpp"

Hexagon::Hexagon() {
    n = 6;
    points = new Point[n];
}

Hexagon::Hexagon(Point& pt1, Point& pt2, Point& pt3, Point& pt4, Point& pt5, Point& pt6) {
    n = 6;
    points = new Point[n];
    points[0] = pt1; points[1] = pt2; points[2] = pt3; points[3] = pt4; points[4] = pt5; points[5] = pt6;
}

Point Hexagon::geometrical_centre() const {
    Point result;
    result.x = (points[0].x + points[1].x + points[2].x + points[3].x + points[4].x + points[5].x) / 6;
    result.y = (points[0].y + points[1].y + points[2].y + points[3].y + points[4].y + points[5].y) / 6;
    return result;
}

double Hexagon::area() const {
    return abs(points[0].x * points[1].y + points[1].x * points[2].y + points[2].x * points[3].y + points[3].x * points[4].y + points[4].x * points[5].y + points[5].x * points[0].y - points[1].x * points[0].y - points[2].x * points[1].y - points[3].x * points[2].y - points[4].x * points[3].y - points[5].x * points[4].y - points[0].x * points[5].y) / 2;
}

std::string Hexagon::return_type() const {
    return {"Hexagon"};
}

void Hexagon::operator=(const Hexagon& fig) {
    this->points[0] = fig.points[0]; this->points[1] = fig.points[1]; this->points[2] = fig.points[2]; this->points[3] = fig.points[3]; this->points[4] = fig.points[4]; this->points[5] = fig.points[5];
}

void Hexagon::operator=(Hexagon&& fig) {
    this->points[0] = fig.points[0]; this->points[1] = fig.points[1]; this->points[2] = fig.points[2]; this->points[3] = fig.points[3]; this->points[4] = fig.points[4]; this->points[5] = fig.points[5];
    fig.points[0] = 0; fig.points[1] = 0; fig.points[2] = 0; fig.points[3] = 0; fig.points[4] = 0; fig.points[5] = 0;
}

bool Hexagon::operator==(const Hexagon& fig) const {
    return this->area() == fig.area();
}

Hexagon::~Hexagon() {
    delete[] points;
}
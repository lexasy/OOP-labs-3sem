#include "../includes/hexagon.hpp"

Hexagon::Hexagon() {
    n = 6;
    points = new Point[n];
}

Hexagon::Hexagon(Point& pt1, Point& pt2, Point& pt3, Point& pt4, Point& pt5, Point& pt6) {
    n = 6;
    points = new Point[n];
    points[0] = pt1; points[1] = pt2; points[2] = pt3; points[3] = pt4; points[4] = pt5; points[5] = pt6;
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
    return static_cast<double>(*this) == static_cast<double>(fig);
}

Hexagon::~Hexagon() {
    delete[] points;
}
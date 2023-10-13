#include "../includes/octagon.hpp"

Octagon::Octagon() {
    n = 8;
    points = new Point[n];
}

Octagon::Octagon(Point& pt1, Point& pt2, Point& pt3, Point& pt4, Point& pt5, Point& pt6, Point& pt7, Point& pt8) {
    n = 8;
    points = new Point[n];
    points[0] = pt1; points[1] = pt2; points[2] = pt3; points[3] = pt4; points[4] = pt5; points[5] = pt6; points[6] = pt7; points[7] = pt8;
}

std::string Octagon::return_type() const {
    return {"Octagon"};
}

void Octagon::operator=(const Octagon& fig) {
    this->points[0] = fig.points[0]; this->points[1] = fig.points[1]; this->points[2] = fig.points[2]; this->points[3] = fig.points[3]; this->points[4] = fig.points[4]; this->points[5] = fig.points[5]; this->points[6] = fig.points[6]; this->points[7] = fig.points[7];
}

void Octagon::operator=(Octagon&& fig) {
    this->points[0] = fig.points[0]; this->points[1] = fig.points[1]; this->points[2] = fig.points[2]; this->points[3] = fig.points[3]; this->points[4] = fig.points[4]; this->points[5] = fig.points[5]; this->points[6] = fig.points[6]; this->points[7] = fig.points[7];
    fig.points[0] = 0; fig.points[1] = 0; fig.points[2] = 0; fig.points[3] = 0; fig.points[4] = 0; fig.points[5] = 0; fig.points[6] = 0; fig.points[7] = 0;
}

bool Octagon::operator==(const Octagon& fig) const {
    return static_cast<double>(*this) == static_cast<double>(fig);
}

Octagon::~Octagon() {
    delete[] points;
}
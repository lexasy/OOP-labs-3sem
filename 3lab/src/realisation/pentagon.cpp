#include "../includes/pentagon.hpp"

Pentagon::Pentagon() {
    n = 5;
    points = new Point[n];
}

Pentagon::Pentagon(Point& pt1, Point& pt2, Point& pt3, Point& pt4, Point& pt5) {
    n = 5;
    points = new Point[n];
    points[0] = pt1; points[1] = pt2; points[2] = pt3; points[3] = pt4; points[4] = pt5;
}

std::string Pentagon::return_type() const {
    return {"Pentagon"};
}

void Pentagon::operator=(const Pentagon& fig) {
    this->points[0] = fig.points[0]; this->points[1] = fig.points[1]; this->points[2] = fig.points[2]; this->points[3] = fig.points[3]; this->points[4] = fig.points[4];
}

void Pentagon::operator=(Pentagon&& fig) {
    n = fig.n;
    points = fig.points;
    fig.n = 0;
    fig.points = nullptr;
}

bool Pentagon::operator==(const Pentagon& fig) const {
    return static_cast<double>(*this) == static_cast<double>(fig);
}

Pentagon::~Pentagon() {
    n = 0;
    delete[] points;
    points = nullptr;
}

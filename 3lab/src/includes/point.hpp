#pragma once

#include <iostream>

class Point {
public:
    Point() = default;
	Point(double x, double y) : x(x), y(y) {}
    void operator=(const Point& pt) {
        this->x = pt.x; this->y = pt.y;
    }
    void operator=(double num) {
        this->x = num; this->y = num;
    }
	~Point() = default;
    double x{}; 
	double y{}; 
};

inline std::istream& operator>>(std::istream& is, Point& p) {
    double x, y;
    is >> x >> y;
    p.x = x; p.y = y;
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << std::fixed << p.x << ", " << p.y << ")\n";
    return os;
}
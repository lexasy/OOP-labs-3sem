#pragma once

#include <iostream>
#include <math.h>

class Point {
public:
    Point() = default;
	Point(float x, float y) : x(x), y(y) {}
    void operator=(const Point& pt) {
        this->x = pt.x; this->y = pt.y;
    }
    void operator=(float num) {
        this->x = num; this->y = num;
    }
	~Point() = default;
    float x{}; 
	float y{}; 
};

inline std::istream& operator>>(std::istream& is, Point& p) {
    float x, y;
    is >> x >> y;
    p.x = x; p.y = y;
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << std::fixed << p.x << ", " << p.y << ")\n";
    return os;
}

float length_btw_points(const Point& p1, const Point& p2);
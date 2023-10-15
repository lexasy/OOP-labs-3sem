#pragma once

#include <iostream>
#include <math.h>

// Point class
class Point {
public:
    // Default constructor
    Point() = default;
    // Double constructor
	Point(double x, double y) : x(x), y(y) {}
    // Overloaded copy operator1 (this->x = pt.x, this->y = pt.y)
    void operator=(const Point& pt) {
        this->x = pt.x; this->y = pt.y;
    }
    // Overloaded copy operator2 (this->x = num, this->y = num)
    void operator=(double num) {
        this->x = num; this->y = num;
    }
    // Overloaded compare operator
    bool operator==(Point& p) const {
        return this->x == p.x && this->y == p.y;
    }
    // Destructor
	~Point() = default;
    // Coordinates by x
    double x{}; 
    // Coordinates by y
	double y{}; 
};

// Overloaded coordinates reading operator
inline std::istream& operator>>(std::istream& is, Point& p) {
    double x, y;
    is >> x >> y;
    p.x = x; p.y = y;
    return is;
}

// Overloaded coordinates printing operator
inline std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << std::fixed << p.x << ", " << p.y << ")\n";
    return os;
}

// Calculates legth between two points
double length_btw_points(const Point& p1, const Point& p2);
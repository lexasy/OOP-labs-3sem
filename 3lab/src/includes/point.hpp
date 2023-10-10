#pragma once

#include <iostream>

class Point {
public:
    Point() = default;
	Point(double x, double y) : 
		x(x), y(y){
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
    os << "(" <<  p.x << ", " << p.y << ")\n";
    return os;
}
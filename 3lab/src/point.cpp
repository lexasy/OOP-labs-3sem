#include "includes/point.hpp"

double length_btw_ptrs(Point p1, Point p2) {
    return (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
}
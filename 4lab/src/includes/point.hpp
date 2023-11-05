#pragma once

#include <bits/stdc++.h>
#include <concepts>

template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template <Numeric T>
class Point {
public:
    Point() = default;
    Point(T x, T y) : coords(x, y) {}
    void operator=(const Point& pt) {
        this->coords = pt.coords;
    }
    void operator=(T num) {
        this->coords.first = num;
        this->coords.second = num;
    }
    bool operator==(const Point& pt) const {
        return this->coords == pt.coords;
    }
    std::pair<T, T> coords;
    ~Point() = default;
};

template <Numeric T>
inline std::istream& operator>>(std::istream& is, Point<T>& pt) {
    T x, y;
    is >> x >> y;
    pt.coords.first = x; pt.coords.second = y;
    return is;
} 

template<Numeric T>
inline std::ostream& operator<<(std::ostream& os, const Point<T>& pt) {
    os << "(" << std::fixed << pt.coords.first << ", " << pt.coords.second << ")\n";
    return os;
}

template <Numeric T>
double length_btw_points(const Point<T>& pt1, const Point<T>& pt2) {
    return sqrt((pt2.coords.first - pt1.coords.first) * (pt2.coords.first - pt1.coords.first) + (pt2.coords.second - pt1.coords.second) * (pt2.coords.second - pt1.coords.second));
}
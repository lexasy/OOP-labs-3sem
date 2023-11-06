#pragma once

#include <bits/stdc++.h>
#include <concepts>

template <typename T>
concept Numeric = (std::integral<T> || std::floating_point<T>) && !std::same_as<T, bool> && !std::same_as<T, char>;

// Class Point<T>, T is integral or floating point type
template <Numeric T>
class Point {
public:
    // Default constructor
    Point() = default;
    // Copy coordinates constructor
    Point(T x, T y) : coords(x, y) {}
    // Overloaded =(copy) operator1 this->coords = pt.coords
    void operator=(const Point<T>& pt) {
        this->coords = pt.coords;
    }
    // Overloaded =(copy) operator2 this->coords.first(second) = num;
    void operator=(T num) {
        this->coords.first = num;
        this->coords.second = num;
    }
    // Overloaded ==(compare) operator
    bool operator==(const Point<T>& pt) const {
        return this->coords == pt.coords;
    }
    // Coordinates of point (x, y)
    std::pair<T, T> coords;
    // Destructor
    ~Point() = default;
};

// Overloaded read operator for coordinates of point
template <Numeric T>
inline std::istream& operator>>(std::istream& is, Point<T>& pt) {
    T x, y;
    is >> x >> y;
    pt.coords.first = x; pt.coords.second = y;
    return is;
} 
// Overloaded print operator for coordinates of point
template<Numeric T>
inline std::ostream& operator<<(std::ostream& os, const Point<T>& pt) {
    os << "(" << std::fixed << pt.coords.first << ", " << pt.coords.second << ")\n";
    return os;
}

// Calculating length between points operator
template <Numeric T, Numeric U>
double length_btw_points(const Point<T>& pt1, const Point<U>& pt2) {
    return sqrt((pt2.coords.first - pt1.coords.first) * (pt2.coords.first - pt1.coords.first) + (pt2.coords.second - pt1.coords.second) * (pt2.coords.second - pt1.coords.second));
}
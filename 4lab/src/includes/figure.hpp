#pragma once

#include "point.hpp"
#include <memory>
#include <typeinfo>

template<Numeric T>
class Figure {
public:
    operator double() const;
    std::shared_ptr<Point<T>[]> points;
    size_t n;
};

template<Numeric T>
inline std::istream& operator>>(std::istream& is, Figure<T>& fig) {
    std::cout << "Please type in the coordinates of points of your " << typeid(fig).name() << ", order [x,y], separated by spaces:\n";
    for (size_t i = 0; i < fig.n; i++) {
        std::cout << "Point" << i + 1 << ": "; is >> fig.points[i]; 
    }
    return is;
}

template<Numeric T>
inline std::ostream& operator<<(std::ostream& os, std::shared_ptr<Figure<T>> fig) {
    os << "Coordinates of " << typeid(*fig).name() << ":\n";
    for (size_t i = 0; i < *fig.get().n)
}
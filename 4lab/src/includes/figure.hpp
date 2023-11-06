#pragma once

#include "point.hpp"
#include <memory>

// Base abstact figure class with Points<T>
template <Numeric T>
class Figure {
public:
    // Pure virtual return type of figure method
    virtual const std::string return_type() const = 0;
    // Overloaded read operator
    friend inline std::istream& operator>>(std::istream& is, Figure<T>& fig) {
        std::cout << "Please type in the coordinates of points of your " << fig.return_type() << ", order [x,y], separated by spaces:\n";
        for (size_t i = 0; i < fig.n; i++) {
            std::cout << "Point" << i + 1 << ": "; is >> fig.points[i];
        }
        return is;
    }
    // Overloaded conversion to double for calculating area
    operator double() const {
        for (size_t i = 1; i < this->n; i++) {
            if (round(length_btw_points(this->points[i], this->points[i + 1 == n ? 0 : i + 1]) * 1000) / 1000 != round(length_btw_points(this->points[0], this->points[1]) * 1000) / 1000) {
                throw std::logic_error{"That's not a correct figure!\n"};
            }
        }
        return round((this->n * length_btw_points(this->points[1], this->points[0]) * length_btw_points(this->points[1], this->points[0]) / 4) * (1 / tan(M_PI / this->n)) * 1000) / 1000; // round to 3 digits
    }
    // Points-array pointer getter
    std::shared_ptr<Point<T>[]> points_array_pointer_getter() const {
        return this->points;
    }
    // Printing coordinates method
    void print_coords() const {
        std::cout << "Coordinates of " << this->return_type() << ":\n";
        for (size_t i = 0; i < this->n; i++) {
            std::cout << "Point" << i + 1 << ": " << this->points[i];
        }
    }
    // Calculating geometrical centre method
    Point<T> geometrical_centre() const {
        for (size_t i = 1; i < this->n; i++) {
            if (round(length_btw_points(this->points[i], this->points[i + 1 == n ? 0 : i + 1]) * 1000) / 1000 != round(length_btw_points(this->points[0], this->points[1]) * 1000) / 1000) {
                throw std::logic_error{"That's not a correct figure!\n"};
            }
        }
        Point<T> result;
        for (size_t i = 0; i < this->n; i++) {
            result.coords.first += this->points[i].coords.first;
            result.coords.second += this->points[i].coords.second;
        }
        result.coords.first /= this->n; result.coords.second /= this->n;
        result.coords.first = round(result.coords.first * 1000) / 1000;
        result.coords.second = round(result.coords.second * 1000) / 1000;
        return result;
    }
    // Destructor
    ~Figure() = default;
protected:
    // Array of points
    std::shared_ptr<Point<T>[]> points;
    // Quantity of points
    size_t n;
};
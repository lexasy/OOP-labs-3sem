#ifndef FIGURE_H
#define FIGURE_H

#include "point.hpp"
#include <cmath>

// Figure base abstract class
class Figure {
public:
    // Read coordinates overloded operator
    friend std::istream& operator>>(std::istream& is, Figure& fig);
    // Print coordinates overloaded operator
    friend std::ostream& operator<<(std::ostream& os, Figure *fig);
    // Calculate geometrical centre of figure method
    Point geometrical_centre() const;
    // Returns type of figure
    virtual std::string return_type() const = 0;
    // Points array pointer getter
    Point *get_array_pointer();
    // Ovrloaded double operator for calculating area
    operator double() const;
protected:
    // Array of figure points
    Point *points;
    // Quantity of figure points
    int n;
};

inline std::istream& operator>>(std::istream& is, Figure& fig) {
    std::cout << "Please type in the coordinates of points of your " << fig.return_type() << ", order [x,y], separated by spaces:\n";
    for (int i = 0; i < fig.n; i++) {
        std::cout << "Point" << i + 1 << ": "; is >> fig.points[i];
    }
    return is;
}

inline std::ostream& operator<<(std::ostream& os, Figure *fig) {
    os << "Coordinates of " << fig->return_type() << ":\n";
    for (int i = 0; i < fig->n; i++) {
        os << "Point" << i + 1 << ": " << fig->points[i];
    }
    return os;
}

#endif

#ifndef FIGURE_H
#define FIGURE_H

#include "point.hpp"
#include <cmath>

class Figure {
public:
    Point geometrical_centre() const;
    void print_coords();
    void read_coords();
    virtual std::string return_type() const = 0;
    Point *get_array_pointer();
    operator double() const;
protected:
    Point *points;
    int n;
};

#endif

#ifndef FIGURE_H
#define FIGURE_H

#include <math.h>
#include "point.hpp"

class Figure {
public:
    virtual Point geometrical_centre() const = 0;
    void print_coords();
    void read_coords();
    virtual double area() const = 0;
    virtual std::string return_type() const = 0;
protected:
    Point *points;
    int n;
};

#endif

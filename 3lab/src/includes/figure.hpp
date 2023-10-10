#ifndef FIGURE_H
#define FIGURE_H

#include <math.h>
#include "point.hpp"

class Figure {
public:
    virtual Point geometrical_centre() const = 0;
    virtual void print_coords() = 0;
    virtual void read_coords() = 0;
    virtual double area() const = 0;
    virtual std::string return_type() const = 0;
};

#endif

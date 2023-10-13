#ifndef FIGURE_H
#define FIGURE_H

#include "point.hpp"

class Figure {
public:
    Point geometrical_centre() const;
    void print_coords();
    void read_coords();
    float area() const;
    virtual std::string return_type() const = 0;
protected:
    Point *points;
    int n;
};

#endif

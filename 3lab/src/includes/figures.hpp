#include <iostream>
#include <math.h>
#include "point.hpp"

class Figure {
public:
    virtual point *geometrical_centre() const = 0;
    virtual void print_coords() = 0;
    virtual void read_coords() = 0;
    virtual double area() const = 0;
    virtual ~Figure() = 0;
};

Figure::~Figure() {};

class Pentagon : public Figure {
public:
    Pentagon();
    point *geometrical_centre() const override;
    void print_coords() override;
    void read_coords() override;
    double area() const override;
    ~Pentagon() override;
private:
    point *p1, *p2, *p3, *p4, *p5;
};

class Hexagon : public Figure {
public:
    Hexagon();
    point *geometrical_centre() const override;
    void print_coords() override;
    void read_coords() override;
    double area() const override;
    ~Hexagon() override;
private:
    point *p1, *p2, *p3, *p4, *p5, *p6;
};

class Octagon : public Figure {
public:
    Octagon();
    point *geometrical_centre() const override;
    void print_coords() override;
    void read_coords() override;
    double area() const override;
    ~Octagon() override;
private:
    point *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8;
};
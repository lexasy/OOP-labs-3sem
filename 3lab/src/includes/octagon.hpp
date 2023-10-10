#include "figure.hpp"

class Octagon : public Figure {
public:
    Point geometrical_centre() const override;
    void print_coords() override;
    void read_coords() override;
    double area() const override;
private:
    Point p1, p2, p3, p4, p5, p6, p7, p8;
};
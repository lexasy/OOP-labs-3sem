#include "figure.hpp"

class Hexagon : public Figure {
public:
    Hexagon() = default;
    Hexagon(Point& pt1, Point& pt2, Point& pt3, Point& pt4, Point& pt5, Point& pt6);
    Point geometrical_centre() const override;
    void print_coords() override;
    void read_coords() override;
    double area() const override;
private:
    Point p1, p2, p3, p4, p5, p6;
};
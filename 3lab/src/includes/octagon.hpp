#include "figure.hpp"

class Octagon : public Figure {
public:
    Octagon() = default;
    Octagon(Point& pt1, Point& pt2, Point& pt3, Point& pt4, Point& pt5, Point& pt6, Point& pt7, Point& pt8);
    Point geometrical_centre() const override;
    void print_coords() override;
    void read_coords() override;
    double area() const override;
    std::string return_type() const override;
    void operator=(const Octagon& fig);
    void operator=(Octagon&& fig);
    bool operator==(const Octagon& fig) const;
private:
    Point p1, p2, p3, p4, p5, p6, p7, p8;
};
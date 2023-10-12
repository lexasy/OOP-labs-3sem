#include "figure.hpp"

class Octagon : public Figure {
public:
    Octagon();
    Octagon(Point& pt1, Point& pt2, Point& pt3, Point& pt4, Point& pt5, Point& pt6, Point& pt7, Point& pt8);
    Point geometrical_centre() const override;
    double area() const override;
    std::string return_type() const override;
    void operator=(const Octagon& fig);
    void operator=(Octagon&& fig);
    bool operator==(const Octagon& fig) const;
    ~Octagon();
};
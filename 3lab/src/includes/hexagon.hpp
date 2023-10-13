#include "figure.hpp"

class Hexagon : public Figure {
public:
    Hexagon();
    Hexagon(Point& pt1, Point& pt2, Point& pt3, Point& pt4, Point& pt5, Point& pt6);
    std::string return_type() const override;
    void operator=(const Hexagon& fig);
    void operator=(Hexagon&& fig);
    bool operator==(const Hexagon& fig) const;
    ~Hexagon();
};
#include "figure.hpp"

class Pentagon : public Figure {
public:
    Pentagon() = default;
    Pentagon(Point& pt1, Point& pt2, Point& pt3, Point& pt4, Point& pt5);
    Point geometrical_centre() const override;
    void print_coords() override;
    void read_coords() override;
    double area() const override;
    std::string return_type() const override;
    void operator=(const Pentagon& fig);
    void operator=(Pentagon&& fig);
    bool operator==(const Pentagon& fig) const;
private:
    Point p1, p2, p3, p4, p5;
};
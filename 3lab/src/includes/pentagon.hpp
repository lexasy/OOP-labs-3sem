#include "figure.hpp"

class Pentagon : public Figure {
public:
    Pentagon();
    Pentagon(Point& pt1, Point& pt2, Point& pt3, Point& pt4, Point& pt5);
    std::string return_type() const override;
    void operator=(const Pentagon& fig);
    void operator=(Pentagon&& fig);
    bool operator==(const Pentagon& fig) const;
    ~Pentagon();
};
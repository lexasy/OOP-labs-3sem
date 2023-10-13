#include "figure.hpp"

// Octagones class (Figure heir)
class Octagon : public Figure {
public:
    // Default constructor
    Octagon();
    // Copy points constructor
    Octagon(Point& pt1, Point& pt2, Point& pt3, Point& pt4, Point& pt5, Point& pt6, Point& pt7, Point& pt8);
    // Returns type of figure
    std::string return_type() const override;
    // Overloaded copy operator
    void operator=(const Octagon& fig);
    // Overloaded move operator
    void operator=(Octagon&& fig);
    // Overloaded compare operator
    bool operator==(const Octagon& fig) const;
    // Destructor
    ~Octagon();
};
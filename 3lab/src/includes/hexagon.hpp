#include "figure.hpp"

// Hexagones class (Figure heir)
class Hexagon : public Figure {
public:
    // Default constructor
    Hexagon();
    // Copy points constructor
    Hexagon(Point& pt1, Point& pt2, Point& pt3, Point& pt4, Point& pt5, Point& pt6);
    // Returns type of figure
    std::string return_type() const override;
    // Overloaded copy operator
    void operator=(const Hexagon& fig);
    // Overloaded move operator
    void operator=(Hexagon&& fig);
    // Overloaded compare operator
    bool operator==(const Hexagon& fig) const;
    // Destructor
    ~Hexagon();
};
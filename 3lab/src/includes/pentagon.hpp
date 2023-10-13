#include "figure.hpp"

// Pentagones class (Figure heir)
class Pentagon : public Figure {
public:
    // Default constructor
    Pentagon();
    // Copy points constructor
    Pentagon(Point& pt1, Point& pt2, Point& pt3, Point& pt4, Point& pt5);
    // Returns type of figure
    std::string return_type() const override;
    // Overloaded copy operator
    void operator=(const Pentagon& fig);
    // Overloaded move operator
    void operator=(Pentagon&& fig);
    // Overloaded compare operator
    bool operator==(const Pentagon& fig) const;
    // Destructor
    ~Pentagon();
};
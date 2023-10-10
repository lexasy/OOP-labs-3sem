#include "includes/pentagon.hpp"
#include "includes/hexagon.hpp"
#include "includes/octagon.hpp"

int main() {
    Point pt1(1, 0); Point pt2(0.5, sqrt(3) / 2); Point pt3(-0.5, sqrt(3) / 2); Point pt4(-1, 0); Point pt5(-0.5, -sqrt(3) / 2); Point pt6(0.5, -sqrt(3) / 2);
    Hexagon hex(pt1, pt2, pt3, pt4, pt5, pt6);
    hex.print_coords();
    std::cout << "Geometrical centre of hexagon is: " << hex.geometrical_centre();
    std::cout << "Area of your hexagon is: " << hex.area() << "\n";
}
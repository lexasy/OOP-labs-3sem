#include "includes/pentagon.hpp"
#include "includes/hexagon.hpp"
#include "includes/octagon.hpp"

int main() {
    Hexagon hex;
    hex.read_coords();
    std::cout << "Geometrical centre of hexagon is: " << hex.geometrical_centre() << "\n";
    std::cout << "Area of your hexagon is: " << hex.area() << "\n";
    hex.print_coords();
}
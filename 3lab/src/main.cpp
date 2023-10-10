#include "includes/pentagon.hpp"
#include "includes/hexagon.hpp"
#include "includes/octagon.hpp"

int main() {
    // std::cout << "Now you need to type in how many figures you want to keep in figure array and coordinates of your figures (Press Enter to continue)";
    // char c; while ((c = getchar()) != 10) {} std::cout << "\n";
    // int n; std::cout << "How many figures you want to keep in your figure array: "; std::cin >> n;
    // if (n > 3) {
    //     std::cerr << "You can't keep in array more than 3 figures!\n"; exit(-1);
    // }
    // Figure **fig_array = new Figure*[n];
    // Pentagon pent; Hexagon hex; Octagon oct;
    // int flagp = 0; int flagh = 0; int flago = 0;
    // for (int i = 0; i < n; i++) {
    //     std::cout << "What figure you want to add in the your figure array (pentagon or hexagon or octagon only): ";
    //     std::string fig; std::cin >> fig;
    //     if (fig == "pentagon") {
    //         if (!flagp) {
    //             pent.read_coords();
    //             fig_array[i] = &pent;
    //             flagp = 1;
    //         } else {
    //             std::cerr << "You alredy have this figure!\n"; exit(-1);
    //         }
    //     } else if (fig == "hexagon") {
    //         if (!flagh) {
    //             hex.read_coords();
    //             fig_array[i] = &hex;
    //             flagh = 1;
    //         } else {
    //             std::cerr << "You alredy have this figure!\n"; exit(-1);
    //         }
    //     } else if (fig == "octagon") {
    //         if (!flago) {
    //             oct.read_coords();
    //             fig_array[i] = &oct;
    //             flago = 1;
    //         } else {
    //             std::cerr << "You alredy have this figure!\n"; exit(-1);
    //         }
    //     } else {
    //         std::cerr << "Invalid figure!\n"; exit(-1);
    //     }
    // }
    // std::cout << "Your array of figures is: [ ";
    // for (int i = 0; i < n; i++) {
    //     std::cout << fig_array[i]->return_type() << " ";
    // }
    // std::cout << "]\n";
    // for (int i = 0; i < n; i++) {
    //     fig_array[i]->print_coords();
    // }
    // std::cout << "--------------------------------------------------------------------------------------------------\n";

    std::cout << "Now we take a look on overloaded operators of copy, move and compare. (Press Enter to continue)";
    char s; while ((s = getchar()) != 10) {} std::cout << "\n";
    Point p1pt1(0, 1); Point p1pt2(0.951, 0.309); Point p1pt3(0.588, -0.809); Point p1pt4(-0.588, -0.809); Point p1pt5(-0.951, 0.309);
    Point p2pt1(1, 0); Point p2pt2(0.809, 0.588); Point p2pt3(-0.309, 0.951); Point p2pt4(-0.809, -0.588); Point p2pt5(0.309, -0.951);
    Point p3pt1(-1, 0); Point p3pt2(-0.809, 0.588); Point p3pt3(0.309, 0.951); Point p3pt4(0.809, -0.588); Point p3pt5(-0.309, -0.951);
    Pentagon pent1(p1pt1, p1pt2, p1pt3, p1pt4, p1pt5);
    Pentagon pent2(p2pt1, p2pt2, p2pt3, p2pt4, p2pt5);
    Pentagon pent3(p3pt1, p3pt2, p3pt3, p3pt4, p3pt5);
    std::cout << "Pentagon 1:\n"; pent1.print_coords();
    std::cout << "Pentagon 2:\n"; pent2.print_coords();
    std::cout << "Pentagon 3:\n"; pent3.print_coords();
    std::cout << "\nPentagon 2 copy to Pentagon 1...\n\n";
    pent1 = pent2;
    std::cout << "Pentagon 1:\n"; pent1.print_coords();
    std::cout << "Pentagon 2:\n"; pent2.print_coords();
    std::cout << "\nPentagon 1 move to Pentagon 3...\n\n";
    pent3 = std::move(pent1);
    std::cout << "Pentagon 1:\n"; pent1.print_coords();
    std::cout << "Pentagon 3:\n"; pent3.print_coords();
    std::cout << "\nPentagon 2 compare with Pentagon 3...\n\n";
    std::cout << "Pentagon 2:\n"; pent2.print_coords();
    std::cout << "Pentagon 3:\n"; pent3.print_coords();
    bool eq = (pent2 == pent3);
    std::cout << "Is Pentagon 2 equal with Pentagon 3? -> " << eq << "\n\n";

    Point h1pt1(1, 0); Point h1pt2(0.5, sqrt(3) / 2); Point h1pt3(-0.5, sqrt(3) / 2); Point h1pt4(-1, 0); Point h1pt5(-0.5, -sqrt(3) / 2); Point h1pt6(0.5, -sqrt(3) / 2);
    Point h2pt1(sqrt(3) / 2, 0.5); Point h2pt2(0, 1); Point h2pt3(-sqrt(3) / 2, 0.5); Point h2pt4(-sqrt(3) / 2, -0.5); Point h2pt5(0, -1); Point h2pt6(sqrt(3) / 2, -0.5);
    Point h3pt1(-0.5, sqrt(3) / 2); Point h3pt2(-1, 0); Point h3pt3(-0.5, -sqrt(3) / 2); Point h3pt4(0.5, -sqrt(3) / 2); Point h3pt5(1, 0); Point h3pt6(0.5, sqrt(3) / 2); 
    Hexagon hex1(h1pt1, h1pt2, h1pt3, h1pt4, h1pt5, h1pt6);
    Hexagon hex2(h2pt1, h2pt2, h2pt3, h2pt4, h2pt5, h2pt6);
    Hexagon hex3(h3pt1, h3pt2, h3pt3, h3pt4, h3pt5, h3pt6);
    std::cout << "Hexagon 1:\n"; hex1.print_coords();
    std::cout << "Hexagon 2:\n"; hex2.print_coords();
    std::cout << "Hexagon 3:\n"; hex3.print_coords();
    std::cout << "\nHexagon 2 copy to Hexagon 1...\n\n";
    hex1 = hex2;
    std::cout << "Hexagon 1:\n"; hex1.print_coords();
    std::cout << "Hexagon 2:\n"; hex2.print_coords();
    std::cout << "\nHexagon 1 move to Hexagon 3...\n\n";
    hex3 = std::move(hex1);
    std::cout << "Hexagon 1:\n"; hex1.print_coords();
    std::cout << "Hexagon 3:\n"; hex3.print_coords();
    std::cout << "\nHexagon 2 compare with Hexagon 3...\n\n";
    std::cout << "Hexagon 2:\n"; hex2.print_coords();
    std::cout << "Hexagon 3:\n"; hex3.print_coords();
    eq = (hex2 == hex3);
    std::cout << "Is Hexagon 2 equal with Hexagon 3? -> " << eq << "\n\n";

    Point o1pt1(1, 0); Point o1pt2(0.707, 0.707); Point o1pt3(0, 1); Point o1pt4(-0.707, 0.707); Point o1pt5(-1, 0); Point o1pt6(-0.707, -0.707); Point o1pt7(0, -1); Point o1pt8(0.707, -0.707);
    Point o2pt1(sqrt(2) / 2, sqrt(2) / 2); Point o2pt2(0, 1); Point o2pt3(-sqrt(2) / 2, sqrt(2) / 2); Point o2pt4(-1, 0); Point o2pt5(-sqrt(2) / 2, -sqrt(2) / 2); Point o2pt6(0, -1); Point o2pt7(sqrt(2) / 2, -sqrt(2) / 2); Point o2pt8(1, 0);
    Point o3pt1(0.5, sqrt(3) / 2); Point o3pt2(-0.5, sqrt(3) / 2); Point o3pt3(-1, 0.5); Point o3pt4(-1, -0.5); Point o3pt5(-0.5, -sqrt(3) / 2); Point o3pt6(0.5, -sqrt(3) / 2); Point o3pt7(1, -0.5); Point o3pt8(1, 0.5); 
    Octagon oct1(o1pt1, o1pt2, o1pt3, o1pt4, o1pt5, o1pt6, o1pt7, o1pt8);
    Octagon oct2(o2pt1, o2pt2, o2pt3, o2pt4, o2pt5, o2pt6, o2pt7, o2pt8);
    Octagon oct3(o3pt1, o3pt2, o3pt3, o3pt4, o3pt5, o3pt6, o3pt7, o3pt8);
    std::cout << "Octagon 1:\n"; oct1.print_coords();
    std::cout << "Octagon 2:\n"; oct2.print_coords();
    std::cout << "Octagon 3:\n"; oct3.print_coords();
    std::cout << "\nOctagon 2 copy to Octagon 1...\n\n";
    oct1 = oct2;
    std::cout << "Octagon 1:\n"; oct1.print_coords();
    std::cout << "Octagon 2:\n"; oct2.print_coords();
    std::cout << "\nOctagon 1 move to Octagon 3...\n\n";
    oct3 = std::move(oct1);
    std::cout << "Octagon 1:\n"; oct1.print_coords();
    std::cout << "Octagon 3:\n"; oct3.print_coords();
    std::cout << "\nOctagon 2 compare with Octagon 3...\n\n";
    std::cout << "Octagon 2:\n"; oct2.print_coords();
    std::cout << "Octagon 3:\n"; oct3.print_coords();
    eq = (oct2 == oct3);
    std::cout << "Is Octagon 2 equal with Octagon 3? -> " << eq << "\n";
    std::cout << "--------------------------------------------------------------------------------------------------\n";
    
}
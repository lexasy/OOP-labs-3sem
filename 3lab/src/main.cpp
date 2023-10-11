#include "includes/figure_array.hpp"

void all_figure_methods(Figure_array *arr) {
    for (int i = 0; i < arr->size; i++) {
        arr->array[i]->print_coords();
        std::cout << "\nGeometrical centre of " << arr->array[i]->return_type() << " is point: " << arr->array[i]->geometrical_centre();
        std::cout << "The area of " << arr->array[i]->return_type() << " is: " << arr->array[i]->area() << "\n\n";
    }
}

double overall_area(Figure_array *arr) {
    double overall_area = 0;
    for (int i = 0; i < arr->size; i++) {
        overall_area += arr->array[i]->area();
    }
    return overall_area;
}

int main() {
    std::cout << "Now you need to type coordinates of your figures (Press Enter to continue) ";
    char c; while ((c = getchar()) != 10) {} std::cout << "\n";
    std::string input; Figure_array *fig_array = create_array();
    while (input != "end") {
        std::cout << "What figure you want to add in the your figure array (pentagon or hexagon or octagon only). If you don't want to add new figures, just type in 'end': ";
        std::cin >> input;
        if (input == "pentagon") {
            Pentagon *pent = new Pentagon;
            pent->read_coords();
            append_figure(fig_array, pent);
        } else if (input == "hexagon") {
            Hexagon *hex = new Hexagon;
            hex->read_coords();
            append_figure(fig_array, hex);
        } else if (input == "octagon") {
            Octagon *oct = new Octagon;
            oct->read_coords();
            append_figure(fig_array, oct);
        }
    }
    std::cout << "Your array of figures is: [ ";
    for (int i = 0; i < fig_array->size; i++) {
        std::cout << fig_array->array[i]->return_type() << " ";
    }
    std::cout << "]\n";
    for (int i = 0; i < fig_array->size; i++) {
        fig_array->array[i]->print_coords();
    }
    destroy_array(fig_array);
    std::cout << "--------------------------------------------------------------------------------------------------\n";

    std::cout << "Now we take a look on overloaded operators of copy, move and compare for all figures (Press Enter to continue) ";
    char s; if ((s = getchar()) == 10) {while ((s = getchar()) != 10) {} } std::cout << "\n";
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

    std::cout << "Now we take some our previous figures to the figure array and check methods of any figure in the array (Press Enter to continue) ";
    char q; while ((q = getchar()) != 10) {} std::cout << "\n";
    Figure_array *fig_array1 = create_array();
    append_figure(fig_array1, &pent2); append_figure(fig_array1, &hex2); append_figure(fig_array1, &oct2);
    std::cout << "Figures in array: [ ";
    for (int i = 0; i < 3; i++) {
        std::cout << fig_array1->array[i]->return_type() << " ";
    }
    std::cout << "]\n";
    all_figure_methods(fig_array1);
    std::cout << "--------------------------------------------------------------------------------------------------\n";
    
    std::cout << "Now we take the previous array and calculate overall area of figures in array (Press Enter to continue) ";
    char y; while ((y = getchar()) != 10) {} std::cout << "\n";
    std::cout << "Overall area of figures in array is: " << overall_area(fig_array1) << "\n";
    std::cout << "--------------------------------------------------------------------------------------------------\n";

    std::cout << "And now we take the previous array and you need to delete all figures by index from this array (Press Enter to continue) ";
    char t; while ((t = getchar()) != 10) {} std::cout << "\n";
    std::cout << "Figures in array: [ ";
    for (int i = 0; i < 3; i++) {
        std::cout << fig_array1->array[i]->return_type() << " ";
    }
    std::cout << "]\n";
    u_int16_t idx; int sz = fig_array1->size;
    for (int i = 0; i < sz; i++) {
        std::cout << "Choose idx for delete: "; std::cin >> idx;
        if (idx > fig_array1->size - 1) {
            std::cerr << "Invalid index!\n"; exit(-1);
        }
        fig_array1->array = rmv_figure(fig_array1, idx); fig_array1->size--;
        std::cout << "Figures in array: [ ";
        for (int j = 0; j < fig_array1->size; j++) {
            std::cout << fig_array1->array[j]->return_type() << " ";
        }
        std::cout << "]\n";
    }
    destroy_array(fig_array1);
}
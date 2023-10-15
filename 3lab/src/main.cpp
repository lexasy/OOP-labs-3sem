#include "includes/figure_array.hpp"

// Calculates gemetrical centre and area of all figures in figure array
void all_figure_methods(Figure_array *arr) {
    for (int i = 0; i < arr->size; i++) {
        std::cout << arr->array[i];
        try {
            std::cout << "\nGeometrical centre of " << arr->array[i]->return_type() << " is point: " << arr->array[i]->geometrical_centre();
            std::cout << "The area of " << arr->array[i]->return_type() << " is: " << static_cast<double>(*arr->array[i]) << "\n\n";
        } catch (const std::logic_error& error_message) {
            std::cerr << "Caught: " << error_message.what() << " Type: " << typeid(error_message).name() << "\n";
        }
    }
}
// Calculates overall area of figures in figure array
double overall_area(Figure_array *arr) {
    double overall_area = 0;
    for (int i = 0; i < arr->size; i++) {
        try {
            overall_area += static_cast<double>(*arr->array[i]);
        } catch (const std::logic_error& error_message) {
            std::cerr << "Caught: " << error_message.what() << " Type: " << typeid(error_message).name() << "\n";
        }
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
            std::cin >> *pent;
            append_figure(fig_array, pent);
        } else if (input == "hexagon") {
            Hexagon *hex = new Hexagon;
            std::cin >> *hex;
            append_figure(fig_array, hex);
        } else if (input == "octagon") {
            Octagon *oct = new Octagon;
            std::cin >> *oct;
            append_figure(fig_array, oct);
        }
    }
    std::cout << "Your array of figures is: [ ";
    for (int i = 0; i < fig_array->size; i++) {
        std::cout << fig_array->array[i]->return_type() << " ";
    }
    std::cout << "]\n";
    for (int i = 0; i < fig_array->size; i++) {
        std::cout << fig_array->array[i];
    }
    destroy_array(fig_array);
    std::cout << "--------------------------------------------------------------------------------------------------\n";

    std::cout << "Now we take a look on overloaded operators of copy, move and compare for all figures (Press Enter to continue) ";
    char s; if ((s = getchar()) == 10) {while ((s = getchar()) != 10) {} } std::cout << "\n";
    Point p1pt1(2, 0); Point p1pt2(2 * cos(2 * M_PI / 5), 2 * sin(2 * M_PI / 5)); Point p1pt3(2 * cos(4 * M_PI / 5), 2 * sin(4 * M_PI / 5)); Point p1pt4(2 * cos(6 * M_PI / 5), 2 * sin(6 * M_PI / 5)); Point p1pt5(2 * cos(8 * M_PI / 5), 2 * sin(8 * M_PI / 5));
    Point p2pt1(1, 0); Point p2pt2(cos(2 * M_PI / 5), sin(2 * M_PI / 5)); Point p2pt3(cos(4 * M_PI / 5), sin(4 * M_PI / 5)); Point p2pt4(cos(6 * M_PI / 5), sin(6 * M_PI / 5)); Point p2pt5(cos(8 * M_PI / 5), sin(8 * M_PI / 5));
    Point p3pt1(3, 0); Point p3pt2(3 * cos(2 * M_PI / 5), 3 * sin(2 * M_PI / 5)); Point p3pt3(3 * cos(4 * M_PI / 5), 3 * sin(4 * M_PI / 5)); Point p3pt4(3 * cos(6 * M_PI / 5), 3 * sin(6 * M_PI / 5)); Point p3pt5(3 * cos(8 * M_PI / 5), 3 * sin(8 * M_PI / 5));
    Pentagon pent1(p1pt1, p1pt2, p1pt3, p1pt4, p1pt5);
    Pentagon pent2(p2pt1, p2pt2, p2pt3, p2pt4, p2pt5);
    Pentagon pent3(p3pt1, p3pt2, p3pt3, p3pt4, p3pt5);
    std::cout << "Pentagon 1:\n" << &pent1;
    std::cout << "Pentagon 2:\n" << &pent2;
    std::cout << "Pentagon 3:\n" << &pent3;
    std::cout << "\nPentagon 2 copy to Pentagon 1...\n\n";
    pent1 = pent2;
    std::cout << "Pentagon 1:\n" << &pent1;
    std::cout << "Pentagon 2:\n" << &pent2;
    std::cout << "\nPentagon 1 move to Pentagon 3...\n\n";
    pent3 = std::move(pent1);
    std::cout << "Pentagon 1:\n" << &pent1;
    std::cout << "Pentagon 3:\n" << &pent3;
    std::cout << "\nPentagon 2 compare with Pentagon 3...\n\n";
    std::cout << "Pentagon 2:\n" << &pent2;
    std::cout << "Pentagon 3:\n" << &pent3;
    bool eq = (pent2 == pent3);
    std::cout << "Is Pentagon 2 equal with Pentagon 3? -> " << eq << "\n\n";

    Point h1pt1(2 * cos(2 * M_PI / 6), 2 * sin(2 * M_PI / 6)); Point h1pt2(2 * cos(4 * M_PI / 6), 2 * sin(4 * M_PI / 6)); Point h1pt3(2 * cos(6 * M_PI / 6), 2 * sin(6 * M_PI / 6)); Point h1pt4(2 * cos(8 * M_PI / 6), 2 * sin(8 * M_PI / 6)); Point h1pt5(2 * cos(10 * M_PI / 6), 2 * sin(10 * M_PI / 6)); Point h1pt6(2 * cos(12 * M_PI / 6), 2 * sin(12 * M_PI / 6));
    Point h2pt1(cos(2 * M_PI / 6), sin(2 * M_PI / 6)); Point h2pt2(cos(4 * M_PI / 6), sin(4 * M_PI / 6)); Point h2pt3(cos(6 * M_PI / 6), sin(6 * M_PI / 6)); Point h2pt4(cos(8 * M_PI / 6), sin(8 * M_PI / 6)); Point h2pt5(cos(10 * M_PI / 6), sin(10 * M_PI / 6)); Point h2pt6(cos(12 * M_PI / 6), sin(12 * M_PI / 6));
    Point h3pt1(3 * cos(2 * M_PI / 6), 3 * sin(2 * M_PI / 6)); Point h3pt2(3 * cos(4 * M_PI / 6), 3 * sin(4 * M_PI / 6)); Point h3pt3(3 * cos(6 * M_PI / 6), 3 * sin(6 * M_PI / 6)); Point h3pt4(3 * cos(8 * M_PI / 6), 3 * sin(8 * M_PI / 6)); Point h3pt5(3 * cos(10 * M_PI / 6), 3 * sin(10 * M_PI / 6)); Point h3pt6(3 * cos(12 * M_PI / 6), 3 * sin(12 * M_PI / 6)); 
    Hexagon hex1(h1pt1, h1pt2, h1pt3, h1pt4, h1pt5, h1pt6);
    Hexagon hex2(h2pt1, h2pt2, h2pt3, h2pt4, h2pt5, h2pt6);
    Hexagon hex3(h3pt1, h3pt2, h3pt3, h3pt4, h3pt5, h3pt6);
    std::cout << "Hexagon 1:\n" << &hex1;
    std::cout << "Hexagon 2:\n" << &hex2;
    std::cout << "Hexagon 3:\n" << &hex3;
    std::cout << "\nHexagon 2 copy to Hexagon 1...\n\n";
    hex1 = hex2;
    std::cout << "Hexagon 1:\n" << &hex1;
    std::cout << "Hexagon 2:\n" << &hex2;
    std::cout << "\nHexagon 1 move to Hexagon 3...\n\n";
    hex3 = std::move(hex1);
    std::cout << "Hexagon 1:\n" << &hex1;
    std::cout << "Hexagon 3:\n" << &hex3;
    std::cout << "\nHexagon 2 compare with Hexagon 3...\n\n";
    std::cout << "Hexagon 2:\n" << &hex2;
    std::cout << "Hexagon 3:\n" << &hex3;
    eq = (hex2 == hex3);
    std::cout << "Is Hexagon 2 equal with Hexagon 3? -> " << eq << "\n\n";

    Point o1pt1(cos(0), sin(0)); Point o1pt2(cos(M_PI / 4), sin(M_PI / 4)); Point o1pt3(cos(M_PI / 2), sin(M_PI / 2)); Point o1pt4(cos(3 * M_PI / 4), sin(3 * M_PI / 4)); Point o1pt5(cos(M_PI), sin(M_PI)); Point o1pt6(cos(5 * M_PI / 4), sin(5 * M_PI / 4)); Point o1pt7(cos(3 * M_PI / 2), sin(3 * M_PI / 2)); Point o1pt8(cos(7 * M_PI / 4), sin(7 * M_PI / 4));
    Point o2pt1(2 * cos(0), 2 * sin(0)); Point o2pt2(2 * cos(M_PI / 4), 2 * sin(M_PI / 4)); Point o2pt3(2 * cos(M_PI / 2), 2 * sin(M_PI / 2)); Point o2pt4(2 * cos(3 * M_PI / 4), 2 * sin(3 * M_PI / 4)); Point o2pt5(2 * cos(M_PI), 2 * sin(M_PI)); Point o2pt6(2 * cos(5 * M_PI / 4), 2 * sin(5 * M_PI / 4)); Point o2pt7(2 * cos(3 * M_PI / 2), 2 * sin(3 * M_PI / 2)); Point o2pt8(2 * cos(7 * M_PI / 4), 2 * sin(7 * M_PI / 4));
    Point o3pt1(3 * cos(0), 3 * sin(0)); Point o3pt2(3 * cos(M_PI / 4), 3 * sin(M_PI / 4)); Point o3pt3(3 * cos(M_PI / 2), 3 * sin(M_PI / 2)); Point o3pt4(3 * cos(3 * M_PI / 4), 3 * sin(3 * M_PI / 4)); Point o3pt5(3 * cos(M_PI), 3 * sin(M_PI)); Point o3pt6(3 * cos(5 * M_PI / 4), 3 * sin(5 * M_PI / 4)); Point o3pt7(3 * cos(3 * M_PI / 2), 3 * sin(3 * M_PI / 2)); Point o3pt8(3 * cos(7 * M_PI / 4), 3 * sin(7 * M_PI / 4));
    Octagon oct1(o1pt1, o1pt2, o1pt3, o1pt4, o1pt5, o1pt6, o1pt7, o1pt8);
    Octagon oct2(o2pt1, o2pt2, o2pt3, o2pt4, o2pt5, o2pt6, o2pt7, o2pt8);
    Octagon oct3(o3pt1, o3pt2, o3pt3, o3pt4, o3pt5, o3pt6, o3pt7, o3pt8);
    std::cout << "Octagon 1:\n" << &oct1;
    std::cout << "Octagon 2:\n" << &oct2;
    std::cout << "Octagon 3:\n" << &oct3;
    std::cout << "\nOctagon 2 copy to Octagon 1...\n\n";
    oct1 = oct2;
    std::cout << "Octagon 1:\n" << &oct1;
    std::cout << "Octagon 2:\n" << &oct2;
    std::cout << "\nOctagon 1 move to Octagon 3...\n\n";
    oct3 = std::move(oct1);
    std::cout << "Octagon 1:\n" << &oct1;
    std::cout << "Octagon 3:\n" << &oct3;
    std::cout << "\nOctagon 2 compare with Octagon 3...\n\n";
    std::cout << "Octagon 2:\n" << &oct2;
    std::cout << "Octagon 3:\n" << &oct3;
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
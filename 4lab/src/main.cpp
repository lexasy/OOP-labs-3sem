#include "includes/figure_array.hpp"

int main() {
    Pentagon<int> pent; std::cin >> pent;
    Figure_array<std::shared_ptr<Figure<int>>> array; array.append_figure(std::make_shared<Pentagon<int>>(pent.points_array_pointer_getter()[0], pent.points_array_pointer_getter()[1], pent.points_array_pointer_getter()[2], pent.points_array_pointer_getter()[3], pent.points_array_pointer_getter()[4]));
    std::cout << *array[0] << "\n";
}
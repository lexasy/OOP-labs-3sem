#include "twelwe.h"

int main() {
    Twelwe newNumber;
    newNumber.read_number();
    newNumber.print_number();
    std::cout << newNumber.from12to10(newNumber.buff) << "\n";
    return 0;
}
#include "twelwe.h"

void parse(std::string input) {
    
}

int main() {
    Twelwe newNumber;
    newNumber.read_number();
    newNumber.print_number();
    std::cout << newNumber.from12to10() << "\n";
    newNumber.from10to12(123322);
    newNumber.print_number();
    return 0;
}
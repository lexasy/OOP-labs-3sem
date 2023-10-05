#include "twelwe.h"

int main() {
    // Contructors testing
    std::cout << "Constructors testing...\n";
    Twelwe num1(5, '7'); std::cout << "\n";
    std::cout << "[1]Fill-array constructor: ";
    num1.print(std::cout); std::cout << "\n";
    Twelwe num2(5, 'A');
    std::cout << "[2]Fill-array constructor: ";
    num2.print(std::cout); std::cout << "\n";
    std::cout << "\n";

    Twelwe num3 {'1', '3', 'A', 'A', '2', 'B', '0'};
    std::cout << "[3]Initializer list constructor: ";
    num3.print(std::cout); std::cout << "\n";
    Twelwe num4 {'0', '0', '0', '0'};
    std::cout << "[4]Initializer list constructor: ";
    num4.print(std::cout); std::cout << "\n";
    Twelwe num5 {'0', 'A', 'A', 'B', 'B'};
    std::cout << "[5]Initializer list constructor: ";
    num5.print(std::cout); std::cout << "\n";
    std::cout << "\n";

    Twelwe num6("123AB");
    std::cout << "[6]Copy string constructor: ";
    num6.print(std::cout); std::cout << "\n";
    Twelwe num7("0000");
    std::cout << "[7]Copy string constructor: ";
    num7.print(std::cout); std::cout << "\n";
    Twelwe num8("");
    std::cout << "[8]Copy string constructor: ";
    num8.print(std::cout); std::cout << "\n";
    std::cout << "\n";

    Twelwe num9(num1);
    std::cout << "[1->9]Copy constructor: ";
    num9.print(std::cout); std::cout << "\n";
    Twelwe num10(num3);
    std::cout << "[3->10]Copy constructor: ";
    num10.print(std::cout); std::cout << "\n";
    Twelwe num11(num6);
    std::cout << "[6->11]Copy constructor: ";
    num11.print(std::cout); std::cout << "\n";
    std::cout << "\n";

    Twelwe num12(std::move(num2));
    std::cout << "[2->12]Move constructor: ";
    num12.print(std::cout); std::cout << "\n";
    Twelwe num13(std::move(num5));
    std::cout << "[5->13]Move constructor: ";
    num13.print(std::cout); std::cout << "\n";
    Twelwe num14(std::move(num8));
    std::cout << "[8->14]Move constructor: ";
    num14.print(std::cout); std::cout << "\n";
    std::cout << "\n";

    // Methods testing
    std::cout << "Methods testing...\n\n";
    std::cout << "[1+3]Add method: ";
    Twelwe num15(num1.add(num3));
    num15.print(std::cout); std::cout << "\n";
    std::cout << "[4+14]Add method: ";
    Twelwe num16(num4.add(num14));
    num16.print(std::cout); std::cout << "\n";
    std::cout << "[6+11]Add method: ";
    Twelwe num17(num6.add(num11));
    num17.print(std::cout); std::cout << "\n";
    std::cout << "\n";

    std::cout << "[11-14]Substraction method: ";
    try {
        Twelwe num18(num11.substraction(num14));
        num18.print(std::cout); std::cout << "\n";
    } catch(const std::string& error_message) {
        std::cout << error_message << "\n";
    }
    std::cout << "[10-13]Substraction method: ";
    try {
        Twelwe num19(num10.substraction(num13));
        num19.print(std::cout); std::cout << "\n";
    } catch(const std::string& error_message) {
        std::cout << error_message << "\n";
    }
    std::cout << "[9-12]Substraction method: ";
    try {
        Twelwe num20(num9.substraction(num12));
        num20.print(std::cout); std::cout << "\n";
    } catch(const std::string& error_message) {
        std::cout << error_message << "\n";
    }
    std::cout << "\n";

    Twelwe num21("123AB"); Twelwe num22("0"); Twelwe num23("AABAB"); Twelwe num24("12AB32AA"); Twelwe num25("123AB");

    std::cout << "[21>22]Relation method: "; num21.print(std::cout); std::cout << " > "; num22.print(std::cout);
    std::cout << " -> " << num21.more(num22) << "\n";
    std::cout << "[22>23]Relation method: "; num22.print(std::cout); std::cout << " > "; num23.print(std::cout);
    std::cout << " -> " << num22.more(num23) << "\n";
    std::cout << "[21>25]Relation method: "; num21.print(std::cout); std::cout << " > "; num25.print(std::cout);
    std::cout << " -> " << num21.more(num25) << "\n";
    std::cout << "\n";

    std::cout << "[21<24]Relation method: "; num21.print(std::cout); std::cout << " < "; num24.print(std::cout);
    std::cout << " -> " << num21.less(num24) << "\n";
    std::cout << "[24<23]Relation method: "; num24.print(std::cout); std::cout << " < "; num23.print(std::cout);
    std::cout << " -> " << num24.less(num23) << "\n";
    std::cout << "[21<25]Relation method: "; num21.print(std::cout); std::cout << " < "; num25.print(std::cout);
    std::cout << " -> " << num21.less(num25) << "\n";
    std::cout << "\n";

    std::cout << "[21==22]Relation method: "; num21.print(std::cout); std::cout << " == "; num22.print(std::cout);
    std::cout << " -> " << num21.equals(num22) << "\n";
    std::cout << "[21==25]Relation method: "; num21.print(std::cout); std::cout << " == "; num25.print(std::cout);
    std::cout << " -> " << num21.equals(num25) << "\n";
    std::cout << "[23==24]Relation method: "; num23.print(std::cout); std::cout << " == "; num24.print(std::cout);
    std::cout << " -> " << num23.equals(num24) << "\n";
}
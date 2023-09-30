#include "twelwe.h"

void parse(std::string input) {
    int idx = 0; Twelwe num1; Twelwe num2; std::string strNum1; std::string strNum2; char op;
    while (input[idx] >= '0' && input[idx] <= '9' || input[idx] >= 'A' && input[idx] <= 'Z') {
        strNum1 += input[idx];
        idx++;
    }
    while (input[idx] == 32) { // 32 == space
        idx++;
    }
    op = input[idx]; idx++;
    while (input[idx] == 32) { // 32 == space
        idx++;
    }
    while (input[idx] >= '0' && input[idx] <= '9' || input[idx] >= 'A' && input[idx] <= 'Z') {
        strNum2 += input[idx];
        idx++;
    }
    if (op == '+') {
        num1.read_number(strNum1); num2.read_number(strNum2);
        Twelwe result = addition(num1, num2);
        result.print_number();
    } else if (op == '-') {
        Twelwe result;
        num1.read_number(strNum1); num2.read_number(strNum2);
        try {
            result = subtraction(num1, num2);
        } catch(const std::string& error_message) {
            std::cout << error_message << "\n";
            exit(-1);
        }
        result.print_number();
    } else if (op == '*') {
        num1.read_number(strNum1); num2.read_number(strNum2);
        Twelwe result = multiplication(num1, num2);
        result.print_number();
    } else if (op == '/') {
        Twelwe result;
        num1.read_number(strNum1); num2.read_number(strNum2);
        try {
            result = division(num1, num2);
        } catch(const std::string& error_message) {
            std::cout << error_message << "\n";
            exit(-1);
        }
        result.print_number();
    } else if (op == '^') {
        num1.read_number(strNum1); int powr = std::stoi(strNum2);
        Twelwe result = mpower(num1, powr);
        result.print_number();
    } else if (op == '>') {
        if (std::stoi(strNum2) == 10) {
            num1.read_number(strNum1);
            int result = num1.from12to10();
            std::cout << result << "\n";
        } else if (std::stoi(strNum2) == 12) {
            for (int j = 0; j < strNum1.length(); j++) {
                if (strNum1[j] >= '0' && strNum1[j] <= '9') {
                    continue;
                } else {
                    std::cout << "Your number isn't a decimal!\n";
                    exit(-1);
                }
            }
            u_int64_t inum1 = std::stoi(strNum1);
            Twelwe result;
            result.from10to12(inum1);
            result.print_number();
        } else {
            std::cout << "The system is invalid!\n";
            exit(-1);
        }
    } else {
        std::cout << "Incorrect operator!\n";
        exit(-1);
    }
}

int main() {
    std::string input; getline(std::cin, input);
    parse(input);
    return 0;
}
#include "twelwe.h"

void check_num(std::string& num) {
    for (int i = 0; i < num.size(); i++) {
        if ((num[i] < '0' || num[i] > '9') && (num[i] != 'A' && num[i] != 'B')) {
            std::cout << "Incorrect number!\n";
            exit(-1);
        }
    }
}

void parse(std::string& input) {
    int idx = 0; std::string strNum1; std::string strNum2; char op;
    while (input[idx] >= '0' && input[idx] <= '9' || input[idx] >= 'A' && input[idx] <= 'Z') {
        strNum1 += input[idx];
        idx++;
    }
    check_num(strNum1);
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
    check_num(strNum2);
    if (op == '+') {
        Twelwe num1 = Twelwe(strNum1); Twelwe num2 = Twelwe(strNum2);
        Twelwe result = Twelwe(addition(num1, num2));
        result.print_number(std::cout);
    } else if (op == '-') {
        Twelwe num1 = Twelwe(strNum1); Twelwe num2 = Twelwe(strNum2);
        try {
            Twelwe result = Twelwe(subtraction(num1, num2));
            result.print_number(std::cout);
        } catch(const std::string& error_message) {
            std::cout << error_message << "\n";
            exit(-1);
        }
    } else if (op == '*') {
        Twelwe num1 = Twelwe(strNum1); Twelwe num2 = Twelwe(strNum2);
        Twelwe result = Twelwe(multiplication(num1, num2));
        result.print_number(std::cout);
    } else if (op == '/') {
        Twelwe num1 = Twelwe(strNum1); Twelwe num2 = Twelwe(strNum2);
        try {
            Twelwe result = Twelwe(division(num1, num2));
            result.print_number(std::cout);
        } catch(const std::string& error_message) {
            std::cout << error_message << "\n";
            exit(-1);
        }
    } else if (op == '>') {
        if (std::stoi(strNum2) == 10) {
            Twelwe num1 = Twelwe(strNum1);
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
            result.print_number(std::cout);
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
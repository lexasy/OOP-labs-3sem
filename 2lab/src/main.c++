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
    int idx = 0; std::string strNum1; std::string strNum2; char op; int op_flag = 0;
    while (input[idx] >= '0' && input[idx] <= '9' || input[idx] >= 'A' && input[idx] <= 'Z' || input[idx] >= 'a' && input[idx] <= 'z')  {
        strNum1 += input[idx];
        idx++;
    }
    check_num(strNum1);
    while (input[idx] == 32) { // 32 == space
        idx++;
    }
    op = input[idx]; idx++;
    if (input[idx] == '>') {
        op_flag = 1; idx++;
    }
    while (input[idx] == 32) { // 32 == space
        idx++;
    }
    while (idx < input.length()) {
        strNum2 += input[idx];
        idx++;
    }
    check_num(strNum2);
    if (strNum1.length() == 0 || strNum2.length() == 0) {
        std::cout << "Incorrect input!\n";
        exit(-1);
    }
    if (op == '+') {
        Twelwe num1 = Twelwe(strNum1); Twelwe num2 = Twelwe(strNum2);
        Twelwe result = Twelwe(addition(num1, num2));
        result.print_number(std::cout);
    } else if (op == '-' && op_flag == 0) {
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
    } else if (op == '-' && op_flag == 1) {
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
    } else if (op == '<') {
        Twelwe num1 = Twelwe(strNum1); Twelwe num2 = Twelwe(strNum2);
        if (num1.from12to10() < num2.from12to10()) {
            std::cout << "True\n";
        } else {
            std::cout << "False\n";
        }
    } else if (op == '>') {
        Twelwe num1 = Twelwe(strNum1); Twelwe num2 = Twelwe(strNum2);
        if (num1.from12to10() > num2.from12to10()) {
            std::cout << "True\n";
        } else {
            std::cout << "False\n";
        }
    } else if (op == '=') {
        Twelwe num1 = Twelwe(strNum1); Twelwe num2 = Twelwe(strNum2);
        if (num1.from12to10() == num2.from12to10()) {
            std::cout << "True\n";
        } else {
            std::cout << "False\n";
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
#pragma once

#include <iostream>
#include <string>
#include <math.h>
#include <vector>

class Twelwe {
    public:
        void read_number();
        void print_number();
        u_int64_t from12to10();
        void from10to12(u_int64_t number);
    private:
        std::vector<u_char> buff;
        std::vector<u_char> saveNumber(std::string numStr, std::vector<u_char> numBuff);
};

Twelwe addition(Twelwe num1, Twelwe num2);
Twelwe subtraction(Twelwe num1, Twelwe num2);
Twelwe multiplication(Twelwe num1, Twelwe num2);
Twelwe division(Twelwe num1, Twelwe num2);
void mpower(Twelwe num, int powr);
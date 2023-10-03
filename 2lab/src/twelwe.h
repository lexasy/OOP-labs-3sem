#pragma once

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include "dyn_array.h"

class Twelwe {
    public:
        void read_number(std::string s);
        void print_number();
        std::string return_number();
        u_int64_t from12to10();
        void from10to12(u_int64_t number);
    private:
        uchar_vector *buff;
        uchar_vector *saveNumber(std::string numStr, uchar_vector *numBuff);
};

Twelwe addition(Twelwe num1, Twelwe num2);
Twelwe subtraction(Twelwe num1, Twelwe num2);
Twelwe multiplication(Twelwe num1, Twelwe num2);
Twelwe division(Twelwe num1, Twelwe num2);
Twelwe mpower(Twelwe num, int powr);

// Suits for Google tests

// std::string straddition(std::string num1, std::string num2);
// std::string strsubtraction(std::string num1, std::string num2);
// std::string strmultiplication(std::string num1, std::string num2);
// std::string strdivision(std::string num1, std::string num2);
// std::string strmpower(std::string num, int powr);
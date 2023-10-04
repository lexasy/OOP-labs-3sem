#pragma once

#include <iostream>
#include <string>
#include <math.h>
#include "dyn_array.h"

class Twelwe {
    public:
        Twelwe(const Twelwe& other); // Copy constructor
        Twelwe(); // Default constructor
        Twelwe(const std::string& numStr); // Copy string constructor
        std::ostream& print_number(std::ostream& os);
        u_int64_t from12to10();
        void from10to12(u_int64_t number);
        bool is_equals(const Twelwe& other);
        virtual ~Twelwe() noexcept; // Destructor
    private:
        uchar_vector *buff;
};

void check_num(std::string& num);

Twelwe addition(Twelwe& num1, Twelwe& num2);
Twelwe subtraction(Twelwe& num1, Twelwe& num2);
Twelwe multiplication(Twelwe& num1, Twelwe& num2);
Twelwe division(Twelwe& num1, Twelwe& num2);


// Suits for Google tests

// std::string straddition(std::string num1, std::string num2);
// std::string strsubtraction(std::string num1, std::string num2);
// std::string strmultiplication(std::string num1, std::string num2);
// std::string strdivision(std::string num1, std::string num2);
// std::string strmpower(std::string num, int powr);
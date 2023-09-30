#pragma once

#include <iostream>
#include <string>
#include <math.h>
#include <vector>

class Twelwe {
    public:
        void read_number();
        void print_number();
    private:
        std::vector<u_char> buff;
        std::vector<u_char> saveNumber(std::string numStr, std::vector<u_char> numBuff);
        u_int64_t from12to10(std::vector<u_char> numBuff);
        std::vector<u_char> from10to12(u_int64_t number);
};
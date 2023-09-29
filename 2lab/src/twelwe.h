#pragma once

#include <iostream>
#include <string>
#include <math.h>
#include <vector>

class Twelwe {
    public:
        void read_number();
        void print_number();
        u_int64_t from12to10(std::vector<u_char> numBuff);
        std::vector<u_char> buff;
    private:
        std::string s;
        std::vector<u_char> saveNumber(std::string strNum, std::vector<u_char> numBuff);
};
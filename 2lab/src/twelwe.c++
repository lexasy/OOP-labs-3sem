#include "twelwe.h"

std::vector<u_char> Twelwe::saveNumber(std::string numStr, std::vector<u_char> numBuff) {
    for (int i = 0; i < numStr.length(); i++) {
        if (numStr[i] < '0' || numStr[i] > '9' && (numStr[i] != 'A' && numStr[i] != 'B')) { // 12-ричная система
            throw std::string{"Incorrect number!"};
        }
        numBuff.push_back(numStr[i]);
    }
    std::vector<u_char> numBuffr;
    for (int i = numBuff.size() - 1; i >= 0; --i) {
        numBuffr.push_back(numBuff[i]);
    }
    return numBuffr;
}

void Twelwe::read_number(std::string s) {
    try {
        buff = saveNumber(s, buff);
    } catch (const std::string& error_message) {
        std::cout << error_message << std::endl;
        exit(-1);
    }
}

void Twelwe::print_number() {
    for (int i = 0; i < buff.size(); i++) {
        std::cout << buff[buff.size() - 1 - i];
    }
    std::cout << "\n";
}

std::string Twelwe::return_number() {
    std::string result;
    for (int i = 0; i < buff.size(); i++) {
        result += buff[buff.size() - 1 - i];
    }
    return result;
}

u_int64_t Twelwe::from12to10() {  // not destruct foo
    u_int64_t result = 0; u_int64_t cur;
    for (int i = 0; i < buff.size(); i++) {
        if (buff[i] >= '0' && buff[i] <= '9') {
            cur = buff[i] - '0';
        } else {
            cur = buff[i] - 'A' + 10;
        }
        result += pow(12, i) * cur;
    }
    return result;
}

void Twelwe::from10to12(u_int64_t number) {  // destruct foo
    u_int64_t cur; buff.clear();
    if (number == 0) {
        buff.push_back('0');
    }
    while (number > 0) {
        cur = number % 12;
        if (cur < 10) {
            buff.push_back(cur + '0');
        } else {
            buff.push_back(cur - 10 + 'A');
        }
        number /= 12;
    }
}

Twelwe addition(Twelwe num1, Twelwe num2) {
    Twelwe result;
    result.from10to12(num1.from12to10() + num2.from12to10());
    return result;
}

Twelwe subtraction(Twelwe num1, Twelwe num2) {
    if (num1.from12to10() < num2.from12to10()) {
        throw std::string{"Can't use negative numbers!"};
    }
    Twelwe result;
    result.from10to12(num1.from12to10() - num2.from12to10());
    return result;
}

Twelwe multiplication(Twelwe num1, Twelwe num2) {
    Twelwe result;
    result.from10to12(num1.from12to10() * num2.from12to10());
    return result;
}

Twelwe division(Twelwe num1, Twelwe num2) {
    if (num2.from12to10() == 0) {
        throw std::string{"Division by zero!"};
    }
    Twelwe result;
    result.from10to12(num1.from12to10() / num2.from12to10());
    return result;
}

Twelwe mpower(Twelwe num, int powr) {
    Twelwe result;
    u_int64_t res10 = pow(num.from12to10(), powr);
    result.from10to12(res10);
    return result;
}

// Suits for Google tests

std::string straddition(std::string num1, std::string num2) {
    Twelwe result; Twelwe tnum1; Twelwe tnum2;
    tnum1.read_number(num1); tnum2.read_number(num2);
    result.from10to12(tnum1.from12to10() + tnum2.from12to10());
    return result.return_number();
}

std::string strsubtraction(std::string num1, std::string num2) {
    Twelwe result; Twelwe tnum1; Twelwe tnum2;
    tnum1.read_number(num1); tnum2.read_number(num2);
    if (tnum1.from12to10() < tnum2.from12to10()) {
        return std::string{"Can't use negative numbers!"};
    }
    result.from10to12(tnum1.from12to10() - tnum2.from12to10());
    return result.return_number();
}

std::string strmultiplication(std::string num1, std::string num2) {
    Twelwe result; Twelwe tnum1; Twelwe tnum2;
    tnum1.read_number(num1); tnum2.read_number(num2);
    result.from10to12(tnum1.from12to10() * tnum2.from12to10());
    return result.return_number();
}

std::string strdivision(std::string num1, std::string num2) {
    Twelwe result; Twelwe tnum1; Twelwe tnum2;
    tnum1.read_number(num1); tnum2.read_number(num2);
    if (tnum2.from12to10() == 0) {
        return std::string{"Division by zero!"};
    }
    result.from10to12(tnum1.from12to10() / tnum2.from12to10());
    return result.return_number();
}

std::string strmpower(std::string num1, int powr) {
    Twelwe result; Twelwe tnum1;
    tnum1.read_number(num1);
    u_int64_t res10 = pow(tnum1.from12to10(), powr);
    result.from10to12(res10);
    return result.return_number();
}
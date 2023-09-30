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

void Twelwe::read_number() {
    std::string s;
    std::cout << "Your number: "; getline(std::cin, s);
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
    if (num1.from12to10() > num2.from12to10()) {
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
    Twelwe result;
    result.from10to12(num1.from12to10() / num2.from12to10());
    return result;
}

void mpower(Twelwe num, int powr) {
    num.from10to12(pow(num.from12to10(), powr));
}


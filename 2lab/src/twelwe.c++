#include "twelwe.h"

std::vector<u_char> Twelwe::saveNumber(std::string numStr, std::vector<u_char> numBuff) {
    for (int i = 0; i < numStr.length(); i++) {
        if (numStr[i] < '0' || numStr[i] > '9' && (numStr[i] != 'A' && numStr[i] != 'B')) { // 12-ричная система
            throw std::string{"Incorrect number!"};
            break;
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
        read_number();
    }
}

void Twelwe::print_number() {
    for (int i = 0; i < buff.size(); i++) {
        std::cout << buff[buff.size() - 1 - i];
    }
    std::cout << "\n";
}

u_int64_t Twelwe::from12to10(std::vector<u_char> numBuff) {
    u_int64_t result = 0; u_int64_t cur;
    for (int i = 0; i < numBuff.size(); i++) {
        if (numBuff[i] >= '0' && numBuff[i] <= '9') {
            cur = (int)numBuff[i] - '0';
        } else {
            cur = (int)numBuff[i] - 'A' + 10;
        }
        result += pow(12, i) * cur;
    }
    return result;
}

std::vector<u_char> Twelwe::from10to12(u_int64_t number) {
    std::vector<u_char> numBuff; int cur;
    while (number > 0) {
        cur = number % 12;
        if (cur < 10) {
            numBuff.push_back(cur + '0');
        } else {
            numBuff.push_back(cur - 10 + 'A');
        }
        number /= 12;
    }
    return numBuff;
}


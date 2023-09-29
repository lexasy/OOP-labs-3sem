#include "twelwe.h"

std::vector<u_char> Twelwe::saveNumber(std::string strNum, std::vector<u_char> numBuff) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9' && (s[i] != 'A' && s[i] != 'B')) { // 12-ричная система
            throw std::string{"Incorrect number!"};
            break;
        }
        numBuff.push_back(s[i]);
    }
    std::vector<u_char> numBuffr;
    for (int i = numBuff.size() - 1; i >= 0; --i) {
        numBuffr.push_back(numBuff[i]);
    }
    numBuff = numBuffr;
    return numBuff;
}

void Twelwe::read_number() {
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


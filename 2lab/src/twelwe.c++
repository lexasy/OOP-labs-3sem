#include "twelwe.h"

Twelwe::Twelwe() {
    buff = create_vector();
}

Twelwe::Twelwe(const Twelwe& other) {
    buff = create_vector();
    int sz = get_size(other.buff);
    for (int i = sz; i < sz; i++) {
        push_back(buff, get_elem(other.buff, i));
    }
}

Twelwe::Twelwe(const std::string& numStr) {
    int sz = numStr.size();
    uchar_vector *tmp = create_vector();
    buff = create_vector();
    for (int i = 0; i < sz; i++) {
        push_back(tmp, numStr[i]);
    }
    for (int i = 0; i < sz; i++) {
        push_back(buff, pop_back(tmp));
    }
    destroy(tmp);
}

Twelwe::~Twelwe() noexcept {
    destroy(buff);
}

std::ostream& Twelwe::print_number(std::ostream& os) {
    for (int i = 0; i < get_size(buff); i++) {
        os << get_elem(buff, get_size(buff) - 1 - i);
    }
    os << "\n";
    return os;
}

u_int64_t Twelwe::from12to10() {  // not destruct foo
    u_int64_t result = 0; u_int64_t cur;
    for (int i = 0; i < get_size(buff); i++) {
        if (get_elem(buff, i) >= '0' && get_elem(buff, i) <= '9') {
            cur = get_elem(buff, i) - '0';
        } else {
            cur = get_elem(buff, i) - 'A' + 10;
        }
        result += pow(12, i) * cur;
    }
    return result;
}

void Twelwe::from10to12(u_int64_t number) {  // destruct foo
    u_int64_t cur;
    if (get_size(buff)) {
        destroy(buff);
        buff = create_vector();
    }
    if (number == 0) {
        push_back(buff, '0');
    }
    while (number > 0) {
        cur = number % 12;
        if (cur < 10) {
            push_back(buff, cur + '0');
        } else {
            push_back(buff, cur - 10 + 'A');
        }
        number /= 12;
    }
}

Twelwe addition(Twelwe& num1, Twelwe& num2) {
    Twelwe result;
    result.from10to12(num1.from12to10() + num2.from12to10());
    return result;
}

Twelwe subtraction(Twelwe& num1, Twelwe& num2) {
    Twelwe result;
    if (num1.from12to10() < num2.from12to10()) {
        throw std::string{"Can't use negative numbers!"};
    }
    result.from10to12(num1.from12to10() - num2.from12to10());
    return result;
}

Twelwe multiplication(Twelwe& num1, Twelwe& num2) {
    Twelwe result;
    result.from10to12(num1.from12to10() * num2.from12to10());
    return result;
}

Twelwe division(Twelwe& num1, Twelwe& num2) {
    if (num2.from12to10() == 0) {
        throw std::string{"Division by zero!"};
    }
    Twelwe result;
    result.from10to12(num1.from12to10() / num2.from12to10());
    return result;
}

// Suits for Google tests

// std::string straddition(std::string num1, std::string num2) {
//     Twelwe result; Twelwe tnum1; Twelwe tnum2;
//     tnum1.read_number(num1); tnum2.read_number(num2);
//     result.from10to12(tnum1.from12to10() + tnum2.from12to10());
//     return result.return_number();
// }

// std::string strsubtraction(std::string num1, std::string num2) {
//     Twelwe result; Twelwe tnum1; Twelwe tnum2;
//     tnum1.read_number(num1); tnum2.read_number(num2);
//     if (tnum1.from12to10() < tnum2.from12to10()) {
//         return std::string{"Can't use negative numbers!"};
//     }
//     result.from10to12(tnum1.from12to10() - tnum2.from12to10());
//     return result.return_number();
// }

// std::string strmultiplication(std::string num1, std::string num2) {
//     Twelwe result; Twelwe tnum1; Twelwe tnum2;
//     tnum1.read_number(num1); tnum2.read_number(num2);
//     result.from10to12(tnum1.from12to10() * tnum2.from12to10());
//     return result.return_number();
// }

// std::string strdivision(std::string num1, std::string num2) {
//     Twelwe result; Twelwe tnum1; Twelwe tnum2;
//     tnum1.read_number(num1); tnum2.read_number(num2);
//     if (tnum2.from12to10() == 0) {
//         return std::string{"Division by zero!"};
//     }
//     result.from10to12(tnum1.from12to10() / tnum2.from12to10());
//     return result.return_number();
// }

// std::string strmpower(std::string num1, int powr) {
//     Twelwe result; Twelwe tnum1;
//     tnum1.read_number(num1);
//     u_int64_t res10 = pow(tnum1.from12to10(), powr);
//     result.from10to12(res10);
//     return result.return_number();
// }
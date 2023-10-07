#include "twelwe.h"

Twelwe::Twelwe() : _size(0), _array{nullptr} {} // Default constructor

Twelwe::Twelwe(const size_t& n, u_char t) { // Fill-array constructor
    if (t >= '0' && t <= '9' || t == 'A' || t == 'B') {
        _array = new u_char[n];
        for (size_t i = 0; i < n; ++i)
            _array[i] = t;
        _size = n;
    }
}

Twelwe::Twelwe(const std::initializer_list<u_char>& t) { // Initializer list constructor
    _array = new u_char[t.size()];
    size_t i{0};
    int cnt = 0;
    for (auto& c : t) {
        if (c >= '0' && c <= '9' || c == 'A' || c == 'B') {
            _array[i++] = c;
        } else {
            cnt++;
        }
    }
    _size = t.size() - cnt;
    std::reverse(_array, _array + _size);
}

Twelwe::Twelwe(const std::string& t) { // Copy string constructor
    int cnt = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] >= '0' && t[i] <= '9' || t[i] == 'A' || t[i] == 'B') {
            continue;
        } else {
            cnt++;
        }
    }
    _array = new u_char[t.size() - cnt];
    _size  = t.size() - cnt;
    for (size_t i{0}; i<_size; ++i){
        if (t[i] >= '0' && t[i] <= '9' || t[i] == 'A' || t[i] == 'B') {
            _array[i] = t[i];
        } else {
            continue; --i;
        }
    } 
    std::reverse(_array, _array + _size);
}

Twelwe::Twelwe(const Twelwe& other) { // Copy constructor
    _size  = other._size;
    _array = new unsigned char[_size];

    for(size_t i{0}; i<_size; ++i) _array[i] = other._array[i];
}

Twelwe::Twelwe(Twelwe&& other) noexcept { // Move constructor
    _size = other._size;
    _array = other._array;
    other._size = 0;
    other._array = nullptr;
}

Twelwe Twelwe::rmvZero() const {
    if (_size) {
        int count = 0;
        for (int i = _size - 1; i >= 0; i--) {
            if (_array[i] != '0') {
                break;
            } else {
                count++;
            }
        }
        if (count == _size) {
            count--;
        }
        Twelwe res(_size - count, '0');
        for (int i = 0; i < res._size; i++) {
            res._array[i] = _array[i];
        }
        return res;
    }
    return *this;
}

Twelwe Twelwe::add(const Twelwe& other) { // this + other
    Twelwe old(this->rmvZero()); Twelwe newn(other.rmvZero());
    size_t res_size = 0;
    if (_size + other._size) {
        res_size = std::max(old._size, newn._size) + 1;
    }
    Twelwe res(res_size, '0');
    int remainder = 0; u_char btw;
    for (int i = 0; i < res_size; i++) {
        btw = from_i_to_c((i < old._size ? from_c_to_i(old._array[i]) : 0) + (i < newn._size ? from_c_to_i(newn._array[i]) : 0) + remainder);
        res._array[i] = from_i_to_c(from_c_to_i(btw) % SYSTEM);
        remainder = from_c_to_i(btw) / SYSTEM;
    }
    return res.rmvZero();
}

Twelwe Twelwe::substraction(const Twelwe& other) { // this - other
    Twelwe old(this->rmvZero()); Twelwe newn(other.rmvZero());
    if (old.less(newn)) {
        throw std::string{"Can't use negative numbers!"};
    }
    if (old._size && newn._size) {
        int flag = 0; int btw;
        for (int i = 0; i < old._size; i++) {
            btw = from_c_to_i(old._array[i]) - from_c_to_i(i < newn._size ? newn._array[i] : '0') - flag;
            flag = btw < 0 ? 1 : 0;
            if (flag) {
                old._array[i] = from_i_to_c(btw + SYSTEM);
            } else {
                old._array[i] = from_i_to_c(btw);
            }
        }
    }
    return old.rmvZero();
}

bool Twelwe::equals(const Twelwe& other) const { // this == other?
    Twelwe old(this->rmvZero()); Twelwe newn(other.rmvZero());
    if (old._size == newn._size) {
        for (int i = 0; i < old._size; i++) {
            if (old._array[i] == newn._array[i]) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Twelwe::more(const Twelwe& other) const { // this > other?
    Twelwe old(this->rmvZero()); Twelwe newn(other.rmvZero());
    if (old._size > newn._size) {
        return true;
    } else if (old._size == newn._size && !old.equals(newn)) {
        for (int i = 0; i < old._size; i++) {
            if (old._array[i] < newn._array[i]) {
                return false;
            } else {
                continue;
            }
        }
        return true;
    }
    return false;
}

bool Twelwe::less(const Twelwe& other) const { // this < other?
    Twelwe old(this->rmvZero()); Twelwe newn(other.rmvZero());
    if (!old.equals(newn) && !old.more(newn)) {
        return true;
    }
    return false;
}

std::ostream& Twelwe::print(std::ostream& os) const { // this -> std::cout
    Twelwe old(this->rmvZero());
    if (old._size) {
        for (int i = old._size - 1; i >= 0; i--) {
            os << old._array[i];
        }
    }
    return os;
}

u_char *Twelwe::GetArrayPointer() const { // Array pointer getter
    return this->_array;
}

size_t Twelwe::GetArraySize() const { // Array size getter
    return this->_size;
}

Twelwe Twelwe::operator+(const Twelwe& other) {
    Twelwe curr(*this);
    return curr.add(other);
}

// Operators reboot
Twelwe Twelwe::operator-(const Twelwe& other) {
    Twelwe curr(*this);
    return curr.substraction(other);
}

bool Twelwe::operator<(const Twelwe& other) {
    Twelwe curr(*this);
    return curr.less(other);
}

bool Twelwe::operator>(const Twelwe& other) {
    Twelwe curr(*this);
    return curr.more(other);
}

bool Twelwe::operator==(const Twelwe& other) {
    Twelwe curr(*this);
    return curr.equals(other);
}

Twelwe::~Twelwe() noexcept { // Destructor
    if (_size)
    {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}

u_char from_i_to_c(int n) { // int -> unsigned char
    return n < 10 ? '0' + n : 'A' + n - 10;
}

int from_c_to_i(u_char c) { // unsigned char -> int
    return c >= '0' && c <= '9' ? c - 48 : c - 55;
}
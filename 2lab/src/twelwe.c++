#include "twelwe.h"

Twelwe::Twelwe() : _size(0), _array{nullptr} {} // Default constructor

Twelwe::Twelwe(const size_t& n, u_char t) { // Fill-array constructor
    _array = new u_char[n];
    for (size_t i = 0; i < n; ++i)
        _array[i] = t;
    _size = n;
}

Twelwe::Twelwe(const std::initializer_list<u_char>& t) { // Initializer list constructor
    _array = new u_char[t.size()];
    size_t i{0};
    for (auto& c : t)
        _array[i++] = c;
    _size = t.size();
}

Twelwe::Twelwe(const std::string& t) { // Copy string constructor
    _array = new u_char[t.size()];
    _size  = t.size();
    for (size_t i{0}; i<_size; ++i) _array[i] = t[i];
}

Twelwe::Twelwe(const Twelwe& other) { // Copy constructor
    _size  = other._size;
    _array = new unsigned char[_size];

    for(size_t i{0}; i<_size; ++i) _array[i] = other._array[i];
}

Twelwe::Twelwe(Twelwe&& other) { // Move constructor
    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
}

Twelwe Twelwe::add(const Twelwe& other) {

}

Twelwe::~Twelwe() noexcept {
    if (_size > 0)
    {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}

u_char from_c_to_i(int n) { // int -> unsigned char
    return n < 10 ? '0' + n : 'A' + n - 10;
}

int from_i_to_c(u_char c) { // unsigned char -> int
    return c >= '0' && c <= '9' ? c - 48 : c - 55;
}
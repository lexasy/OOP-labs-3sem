#pragma once

#include <iostream>
#include <string>
#include <algorithm>

#define SYSTEM 12

class Twelwe {
    public:
        // Constructors
        Twelwe();
        Twelwe(const size_t & n, u_char t = 0);
        Twelwe(const std::initializer_list<u_char>& t);
        Twelwe(const std::string& t);
        Twelwe(const Twelwe& other);
        Twelwe(Twelwe&& other) noexcept;

        // Methods
        Twelwe add(const Twelwe& other);
        Twelwe substraction(const Twelwe& other);
        bool equals(const Twelwe& other) const;
        bool more(const Twelwe& other) const;
        bool less(const Twelwe& other) const;
        std::ostream& print(std::ostream& os) const;

        // Destructor
        virtual ~Twelwe() noexcept;
    private:
        // Class elements
        size_t _size;
        u_char *_array;

        // "Service" method
        Twelwe rmvZero() const; 
};

// Transition types functions
int from_c_to_i(u_char c);
u_char from_i_to_c(int n);
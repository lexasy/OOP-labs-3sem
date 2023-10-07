#pragma once

#include <iostream>
#include <string>
#include <algorithm>

#define SYSTEM 12

class Twelwe {
    public:
        // Default onstructor
        Twelwe();
        // Fill-array constructor
        Twelwe(const size_t& n, u_char t = 0);
        // Initializer list constructor
        Twelwe(const std::initializer_list<u_char>& t);
        // Copy string constructor
        Twelwe(const std::string& t);
        // Copy constructor
        Twelwe(const Twelwe& other);
        // Move  constructor
        Twelwe(Twelwe&& other) noexcept;

        // Addition method
        Twelwe add(const Twelwe& other);
        // Substraction method
        Twelwe substraction(const Twelwe& other);
        // Equality method
        bool equals(const Twelwe& other) const;
        // Greater relation method
        bool more(const Twelwe& other) const;
        // Lesser relation method
        bool less(const Twelwe& other) const;
        // Print method
        std::ostream& print(std::ostream& os) const;

        // Operator + reboot
        Twelwe operator+(const Twelwe& other);
        // Operator - reboot
        Twelwe operator-(const Twelwe& other);
        // Operator == reboot
        bool operator==(const Twelwe& other);
        // Operator > reboot
        bool operator>(const Twelwe& other);
        // Operator < reboot
        bool operator<(const Twelwe& other);

        // Array pointer getter
        u_char *GetArrayPointer() const;
        // Array size getter
        size_t GetArraySize() const;

        // Destructor
        virtual ~Twelwe() noexcept;
    private:
        // Class elements
        size_t _size;
        u_char *_array;

        // Lead zero cleaner method
        Twelwe rmvZero() const; 
};

// From char to int function
int from_c_to_i(u_char c);
// From int to char function
u_char from_i_to_c(int n);
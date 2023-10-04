#pragma once

#include <iostream>
#include <string>

class Twelwe {
    public:
        Twelwe();
        Twelwe(const size_t & n, u_char t = 0);
        Twelwe(const std::initializer_list<u_char>& t);
        Twelwe(const std::string& t);
        Twelwe(const Twelwe& other);
        Twelwe(Twelwe&& other) noexcept;

        Twelwe add(const Twelwe& other);
        Twelwe remove(const Twelwe& other);
        bool equals(const Twelwe& other) const;
        bool more(const Twelwe& other) const;
        bool less(const Twelwe& other) const;
        std::ostream& print(std::ostream& os) const;

        virtual ~Twelwe() noexcept;
    private:
        size_t _size;
        u_char *_array;  
};

int from_c_to_i(u_char c);
u_char from_i_to_c(int n);
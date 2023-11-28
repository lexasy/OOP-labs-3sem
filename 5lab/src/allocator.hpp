#pragma once

#include <deque>

namespace my_nsp {
    // Custom allocator class
    template <class T, std::size_t BLOCK_SIZE>
    class Allocator {
    private:
        // Deque with pointers on free blocks in memory
        std::deque<T *> _free_blocks;
        // Memory for allocate
        T *_used_blocks;
    public:
        using value_type = T;
        using pointer = T *;
        using const_pointer = const T *;
        using size_type = std::size_t;
        // Default constructor
        Allocator() : _free_blocks(), _used_blocks(nullptr) {
            static_assert(BLOCK_SIZE > 0);
        }
        // Destructor
        ~Allocator() {
            delete[] _used_blocks;
        }
        // Rebind costruction
        template <typename U>
        struct rebind {
            using other = Allocator<U, BLOCK_SIZE>;
        };
        // Allocate method, returns pointer on free memory with size n
        T* allocate(const std::size_t& n) {
            if (_used_blocks == nullptr) {
                _used_blocks = new T[BLOCK_SIZE];
                for (std::size_t i = 0; i < BLOCK_SIZE; i++) {
                    _free_blocks.push_back(&_used_blocks[i]);
                }
            }
            if (_free_blocks.size() < n) {
                throw std::bad_alloc();
            } else {
                T *ptr = nullptr;
                for (std::size_t i = 0; i < n; i++) {
                    ptr = _free_blocks.back();
                    _free_blocks.pop_back();
                }
                return ptr;
            }
        }
        // Deallocate method, which make free ptr
        void deallocate(T *ptr, std::size_t) {
            _free_blocks.push_back(ptr);
        }
        // Constructor of new element
        template <typename U, typename... Args>
        void construct(U *p, Args &&...args) {
            new (p) U(std::forward<Args>(args)...);
        }
        // Destructor of element
        void destroy(pointer p) {
            p->~T();
        }
    };
}
// Allocator equation operator
template <class T, class U, std::size_t BLOCK_SIZE>
constexpr bool operator==(const my_nsp::Allocator<T, BLOCK_SIZE> &lhs, const my_nsp::Allocator<U, BLOCK_SIZE> &rhs) {
    return true;
}
// Allocator non-equation operator
template <class T, class U, std::size_t BLOCK_SIZE>
constexpr bool operator!=(const my_nsp::Allocator<T, BLOCK_SIZE> &lhs, const my_nsp::Allocator<U, BLOCK_SIZE> &rhs) {
    return false;
}
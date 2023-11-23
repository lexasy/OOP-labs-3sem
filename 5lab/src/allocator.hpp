#pragma once

#include <deque>

namespace my_nsp {
    template <class T, std::size_t BLOCK_SIZE>
    class Allocator {
    private:
        std::deque<T *> _deque;
        T *_buffer;        
    public:
        using value_type = T;
        using pointer = T *;
        using const_pointer = const T *;
        using size_type = std::size_t;

        Allocator() : _deque(), _buffer(nullptr) {
            static_assert(BLOCK_SIZE > 0);
        }

        ~Allocator() {
            delete[] _buffer;
        }

        template <typename U>
        struct rebind {
            using other = Allocator<U, BLOCK_SIZE>;
        };

        T* allocate(const std::size_t& n) {
            if (_buffer == nullptr) {
                _buffer = new T[BLOCK_SIZE];
                for (std::size_t i = 0; i < BLOCK_SIZE; i++) {
                    _deque.push_back(&_buffer[i]);
                }
            }
            if (_deque.size() < n) {
                throw std::bad_alloc();
            } else {
                T *ptr = nullptr;
                for (std::size_t i = 0; i < n; i++) {
                    ptr = _deque.back();
                    _deque.pop_back();
                }
                return ptr;
            }
        }

        void deallocate(T *, std::size_t) {};

        template <typename U, typename... Args>
        void construct(U *p, Args &&...args) {
            new (p) U(std::forward<Args>(args)...);
        }

        void destroy(pointer p) {
            p->~T();
        }
    };
}

template <class T, class U, std::size_t BLOCK_SIZE>
constexpr bool operator==(const my_nsp::Allocator<T, BLOCK_SIZE> &lhs, const my_nsp::Allocator<U, BLOCK_SIZE> &rhs) {
    return true;
}

template <class T, class U, std::size_t BLOCK_SIZE>
constexpr bool operator!=(const my_nsp::Allocator<T, BLOCK_SIZE> &lhs, const my_nsp::Allocator<U, BLOCK_SIZE> &rhs) {
    return false;
}
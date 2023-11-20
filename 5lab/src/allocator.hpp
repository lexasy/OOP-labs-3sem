#pragma once

#include <deque>
#include <memory>

template <class T, size_t BLOCK_SIZE>
class allocator {
private:
    std::deque<std::unique_ptr<T>> _deque;
    std::unique_ptr<T> _buffer = nullptr;
public:
    using value_type = T;
    using pointer = std::unique_ptr<T>;
    using const_pointer = const std::unique_ptr<T>;
    using size_type = std::size_t;

    allocator() : _buffer{}, _free_index(0) {
        static_assert(BLOCK_SIZE > 0);
    }

    template <typename U>
    struct rebind {
        using other = allocator<U, BLOCK_SIZE>;
    };

    std::unique_ptr<T> allocate(size_t n) {
        if (!_buffer) {
            _buffer = new T[BLOCK_SIZE];
            for (size_t i = BLOCK_SIZE - 1; i >= 0; --i) {
                _deque.push_back(std::make_unique(_buffer[i]));
            }
        }
        if (_deque.size() < n) {
            throw std::bad_alloc();
        } else {
            std::unique_ptr<T> p = *(_deque.begin());
            for (size_t i = 0; i < n; i++) {
                _deque.pop_front();
            }
            return p;
        }
    }
    ~allocator() = default;
};
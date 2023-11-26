#pragma once

#include <stdexcept>
#include <memory>

#define DEFAULT 1

namespace my_nsp {
    template <class T, class Allocator>
    class Dynamic_array {
    private:
        class Array_item {
            T value;
            bool free;
        public:
            Array_item() : value(0), free(false) {};
            friend Dynamic_array;
        };
        using ALLOCATOR = typename Allocator::template rebind<Array_item>::other;
        ALLOCATOR allocator;
        Array_item *_buffer;
        std::size_t _size;
        std::size_t _capacity;
        void expand() {
            Array_item *new_buffer = allocator.allocate(_capacity);
            for (std::size_t i = 0; i < _size; i++) {
                new_buffer[i] = _buffer[i];
                _buffer[i].value = 0;
            }
            _buffer = new_buffer;
            _capacity *= 2;
        }
    public:
        Dynamic_array() {
            _buffer = allocator.allocate(DEFAULT);
            _size = 0;
            _capacity = DEFAULT;
        }
        class Iterator {
        private:
            std::size_t _size;
            std::size_t _idx;
            Array_item *_array;
        public:
            using iterator_category = std::forward_iterator_tag;
            using difference_type = std::ptrdiff_t;
            using value_type = T;
            using pointer = T *;
            using reference = T&;
            using const_reference = const T&;
            Iterator() : _array(nullptr), _idx(0), _size(0) {};
            Iterator(Array_item *arr, std::size_t i, std::size_t sz) : _array(arr), _idx(i), _size(sz) {};
            Iterator(const Iterator& other) : _array(other._array), _idx(other._idx), _size(other._size) {};
            Iterator& operator++() {
                if (_size <= _idx) {
                    throw std::logic_error("Out of bound"); 
                }
                this->_idx++;
                return *this;
            }
            bool operator==(const Iterator& other) {
                return (other._array == this->_array) && (other._idx == this->_idx);
            }
            bool operator!=(const Iterator& other) {
                return (other._idx != this->_idx) || (other._array != this->_array);
            }
            T& operator*() {
                return this->_array[this->_idx].value;
            }
            T& operator->() {
                return this->_array[this->_idx].value;
            }
        };
        using const_pointer = const T *;
        using const_reference = const T&;
        using iterator = Iterator;
        using pointer = T *;
        using reference = T&;
        using size_type = std::size_t;
        using value_type = T;
        iterator begin() {
            return Iterator(this->_buffer, 0, this->_size);
        }
        iterator end() {
            return Iterator(this->_buffer, this->_size, this->_size);
        }
        void pop_back() {
            allocator.deallocate(&(this->_buffer[this->_size]), DEFAULT);
            this->_buffer[this->_size].free = true;
            this->_size--;
        }
        void push_back(T value) {
            if (_size == _capacity) {
                expand();
            }
            this->_buffer[this->_size++].value = value;
        }
        std::size_t size() {
            return this->_size;
        }
        std::size_t capacity() {
            return this->_capacity;
        }
        T& operator[](std::size_t idx) {
            if (idx >= _size) {
                throw std::exception();
            }
            return this->_buffer[idx].value;
        }
    };
}
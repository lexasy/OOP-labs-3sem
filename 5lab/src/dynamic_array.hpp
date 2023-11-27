#pragma once

#include <stdexcept>
#include <memory>
#include <iostream>

#define DEFAULT 1

namespace my_nsp {
    template <class T, class Allocator>
    class Dynamic_array {
    private:
        Allocator allocator;
        T *_buffer;
        std::size_t _size;
        std::size_t _capacity;
        void expand() {
            T *new_buffer = allocator.allocate(_capacity);
            for (std::size_t i = 0; i < _size; i++) {
                new_buffer[i] = _buffer[i];
            }
            _buffer = new_buffer;
            _capacity *= 2;
        }
        void shrink() {
            for (std::size_t i = 0; i < _size; i++) {
                _buffer[i + _size] = _buffer[i];
                allocator.deallocate(&_buffer[i], DEFAULT);
            }
            _buffer += _size;
            _capacity /= 2;
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
            T *_array;
        public:
            friend Dynamic_array;
            using iterator_category = std::forward_iterator_tag;
            using difference_type = std::ptrdiff_t;
            using value_type = T;
            using pointer = T *;
            using const_pointer = const T *;
            using reference = T&;
            using const_reference = const T&;
            Iterator() : _array(nullptr), _idx(0), _size(0) {};
            Iterator(T *arr, std::size_t i, std::size_t sz) : _array(arr), _idx(i), _size(sz) {};
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
                return this->_array[this->_idx];
            }
            T& operator->() {
                return this->_array[this->_idx];
            }
        };
        class Const_Iterator {
        private:
            std::size_t _size;
            std::size_t _idx;
            T const *_array;
        public:
            friend Dynamic_array;
            using iterator_category = std::forward_iterator_tag;
            using difference_type = std::ptrdiff_t;
            using value_type = T;
            using const_pointer = const T *;
            using const_reference = const T&;
            Const_Iterator() : _array(nullptr), _idx(0), _size(0) {};
            Const_Iterator(T const *arr, std::size_t i, std::size_t sz) : _array(arr), _idx(i), _size(sz) {};
            Const_Iterator(const Const_Iterator& other) : _array(other._array), _idx(other._idx), _size(other._size) {};
            Const_Iterator& operator++() {
                if (_size <= _idx) {
                    throw std::logic_error("Out of bound"); 
                }
                this->_idx++;
                return *this;
            }
            bool operator==(const Const_Iterator& other) {
                return (other._array == this->_array) && (other._idx == this->_idx);
            }
            bool operator!=(const Const_Iterator& other) {
                return (other._idx != this->_idx) || (other._array != this->_array);
            }
            T& operator*() {
                return this->_array[this->_idx];
            }
            T& operator->() {
                return this->_array[this->_idx];
            }
        };
        using const_pointer = const T *;
        using const_reference = const T&;
        using iterator = Iterator;
        using const_iterator = Const_Iterator;
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
        const_iterator cbegin() {
            return Const_Iterator(this->_buffer, 0, this->_size);
        }
        const_iterator cend() {
            return Const_Iterator(this->_buffer, this->_size, this->_size);
        }
        iterator insert(iterator position, T value) {
            if (_size == _capacity) {
                expand();
            }
            _buffer = allocator.allocate(DEFAULT);
            for (std::size_t i = 0; i <= position._idx; i++) {
                _buffer[i] = _buffer[i + 1];
            }
            _buffer[position._idx] = value;
            position._size++;
            _size++;
            return position;
        }
        iterator erase(iterator position) {
            for (std::size_t i = position._idx; i > 0; i--) {
                _buffer[i] = _buffer[i - 1];
            }
            allocator.deallocate(&_buffer[0], DEFAULT);
            _buffer++;
            _size--;
            if (_size <= _capacity / 2) {
                shrink();
            }
            position._array = _buffer;
            position._size = _size;
            return position;
        }
        // void shrink_to_fit() {

        // }
        void pop_back() {
            this->_size--;
            if (this->_size <= this->_capacity / 2) {
                shrink();
            }
        }
        void push_back(T value) {
            if (_size == _capacity) {
                expand();
            }
            this->_buffer[this->_size++] = value;
        }
        template <class... Types>
        iterator emplace(iterator position, Types&&... args) {
            if (_size == _capacity) {
                expand();
            }
            _buffer = allocator.allocate(DEFAULT);
            for (std::size_t i = 0; i <= position._idx; i++) {
                _buffer[i] = _buffer[i + 1];
            }
            _buffer[position._idx] = T(std::forward<Types>(args)...);
            position._size++;
            _size++;
            return position;
        }
        template <class... Types>
        void emplace_back(Types&&... args) {
            if (_size == _capacity) {
                expand();
            }
            this->_buffer[this->_size++] = T(std::forward<Types>(args)...);
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
            return this->_buffer[idx];
        }
        void operator=(const Dynamic_array<T, Allocator>& other) {
            return;
        }
    };
}

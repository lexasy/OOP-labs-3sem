#pragma once

#include <stdexcept>

#define DEFAULT 1

namespace my_nsp {
    // Dynamic array container
    template <class T, class Allocator>
    class Dynamic_array {
    private:
        // Allocator of container
        Allocator allocator;
        // Buffer of container
        T *_buffer;
        // Size of container
        std::size_t _size;
        // Capacity of container
        std::size_t _capacity;
        // Buffer expand method
        void expand() {
            T *new_buffer = allocator.allocate(_capacity);
            for (std::size_t i = 0; i < _size; i++) {
                new_buffer[i] = _buffer[i];
            }
            _buffer = new_buffer;
            _capacity *= 2;
        }
        // Buffer shrink method
        void shrink() {
            for (std::size_t i = 0; i < _size; i++) {
                _buffer[i + _size] = _buffer[i];
                allocator.deallocate(&_buffer[i], DEFAULT);
            }
            _buffer += _size;
            _capacity /= 2;
        }
    public:
        // Default constructor
        Dynamic_array() {
            _buffer = allocator.allocate(DEFAULT);
            _size = 0;
            _capacity = DEFAULT;
        }
        // Initializer list constructor
        Dynamic_array(const std::initializer_list<T>& arr) {
            _buffer = allocator.allocate(DEFAULT);
            _size = 0;
            _capacity = DEFAULT;
            for (auto& c : arr) {
                this->push_back(c);
            }
        }
        // Non constant iterator
        class Iterator {
        private:
            // Size of container under iterator
            std::size_t _size;
            // Index of iterator in buffer
            std::size_t _idx;
            // Buffer of container under iterator
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
            // Default constuctor
            Iterator() : _array(nullptr), _idx(0), _size(0) {};
            // Fields values constructor
            Iterator(T *arr, std::size_t i, std::size_t sz) : _array(arr), _idx(i), _size(sz) {};
            // Copy constructor
            Iterator(const Iterator& other) : _array(other._array), _idx(other._idx), _size(other._size) {};
            // Increment of iterator
            Iterator& operator++() {
                if (_size <= _idx) {
                    throw std::logic_error("Out of bound"); 
                }
                this->_idx++;
                return *this;
            }
            // Iterator increment
            Iterator& Iterator::operator++(int) {
                if (_size <= _idx) {
                    throw std::logic_error("Out of bound"); 
                }
                this->_idx++;
                return *this;
            }
            // Iterator equation operator
            bool operator==(const Iterator& other) {
                return (other._array == this->_array) && (other._idx == this->_idx);
            }
            // Iterator not-eqation operator
            bool operator!=(const Iterator& other) {
                return (other._idx != this->_idx) || (other._array != this->_array);
            }
            // Dereferencing of iterator
            T& operator*() {
                if (this->_idx >= _size) {
                    throw std::logic_error("Out of bound"); 
                }
                return this->_array[this->_idx];
            }
            // Deferencing of iterator
            T& operator->() {
                if (this->_idx >= _size) {
                    throw std::logic_error("Out of bound"); 
                }
                return this->_array[this->_idx];
            }
        };
        // Constant iterator
        class Const_Iterator {
        private:
            // Size of container inder iterator
            std::size_t _size;
            // Index of iterator in buffer
            std::size_t _idx;
            // Buffer of container under iterator
            T const *_array;
        public:
            friend Dynamic_array;
            using iterator_category = std::forward_iterator_tag;
            using difference_type = std::ptrdiff_t;
            using value_type = T;
            using const_pointer = const T *;
            using const_reference = const T&;
            // Default constructor
            Const_Iterator() : _array(nullptr), _idx(0), _size(0) {};
            // Fields values constructor
            Const_Iterator(T const *arr, std::size_t i, std::size_t sz) : _array(arr), _idx(i), _size(sz) {};
            // Copy constructor
            Const_Iterator(const Const_Iterator& other) : _array(other._array), _idx(other._idx), _size(other._size) {};
            // Iterator increment
            Const_Iterator& operator++() {
                if (_size <= _idx) {
                    throw std::logic_error("Out of bound"); 
                }
                this->_idx++;
                return *this;
            }
            // Iterator increment
            Const_Iterator& Const_Iterator::operator++(int) {
                if (_size <= _idx) {
                    throw std::logic_error("Out of bound"); 
                }
                this->_idx++;
                return *this;
            }
            // Iterator equation operator
            bool operator==(const Const_Iterator& other) {
                return (other._array == this->_array) && (other._idx == this->_idx);
            }
            // Iterator non-equation operator
            bool operator!=(const Const_Iterator& other) {
                return (other._idx != this->_idx) || (other._array != this->_array);
            }
            // Deferencing of iterator
            const T& operator*() {
                if (this->_idx >= _size) {
                    throw std::logic_error("Out of bound"); 
                }
                return this->_array[this->_idx];
            }
            // Deferencing of iterator
            const T& operator->() {
                if (this->_idx >= _size) {
                    throw std::logic_error("Out of bound"); 
                }
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
        // Returns an iterator to the first element in the vector
        iterator begin() {
            return Iterator(this->_buffer, 0, this->_size);
        }
        // Returns an iterator that points to the element after the last element
        iterator end() {
            return Iterator(this->_buffer, this->_size, this->_size);
        }
        // Returns a const iterator that addresses the first element in the range
        const_iterator cbegin() {
            return Const_Iterator(this->_buffer, 0, this->_size);
        }
        // Returns a const iterator that points to the element after the last element
        const_iterator cend() {
            return Const_Iterator(this->_buffer, this->_size, this->_size);
        }
        // Inserts an element at a specified position
        iterator insert(iterator position, T value) {
            if (_size == _capacity) {
                expand();
            }
            for (std::size_t i = _size - 1; i >= position._idx; i--) {
                _buffer[i + 1] = _buffer[i];
                if (i == position._idx) {
                    break;
                }
            }
            _buffer[position._idx] = value;
            _size++; position._size++;
            return position;
        }
        // Removes an element from specified position
        iterator erase(iterator position) {
            for (std::size_t i = position._idx; i < _size; i++) {
                _buffer[i] = _buffer[i + 1];
            }
            _size--; position._size = _size;
            if (_size <= _capacity / 2) {
                shrink();
            }
            position._array = _buffer;
            return position;
        }
        // Removes the element at the end of the vector
        void pop_back() {
            this->_size--;
            if (this->_size <= this->_capacity / 2) {
                shrink();
            }
        }
        // Adds an element to the end of the vector
        void push_back(T value) {
            if (_size == _capacity) {
                expand();
            }
            this->_buffer[this->_size++] = value;
        }
        // Inserts an in-place constructed element into a vector at the specified position
        template <class... Types>
        iterator emplace(iterator position, Types&&... args) {
            if (_size == _capacity) {
                expand();
            }
            for (std::size_t i = _size - 1; i >= position._idx; i--) {
                _buffer[i + 1] = _buffer[i];
                if (i == position._idx) {
                    break;
                }
            }
            _buffer[position._idx] = T(std::forward<Types>(args)...);
            _size++; position._size++;
            return position;
        }
        // Adds a constructed element to the end of the vector
        template <class... Types>
        void emplace_back(Types&&... args) {
            if (_size == _capacity) {
                expand();
            }
            this->_buffer[this->_size++] = T(std::forward<Types>(args)...);
        }
        // Returns the number of elements in a vector
        std::size_t size() {
            return this->_size;
        }
        // Returns the number of elements a vector can contain without allocating more storage space
        std::size_t capacity() {
            return this->_capacity;
        }
        // Removes vector elements
        void clear() {
            std::size_t init_size = _size;
            for (std::size_t _ = 0; _ < init_size; _++) {
                this->pop_back();
            }
        }
        // Checks if a vector is empty
        bool empty() {
            return _size == 0;
        }
        // Returns a copy of the allocator object used to construct the vector
        Allocator get_allocator() const {
            return allocator;
        }
        // Returns a reference to the element at the specified location in the vector
        reference at(size_type position) {
            if (position >= _size) {
                throw std::logic_error("Out of bound exception");
            }
            return _buffer[position];
        }
        // Returns a pointer to the first element in a vector
        pointer data() {
            return _buffer;
        }
        // Returns a reference to the vector element at the specified position
        T& operator[](std::size_t idx) {
            if (idx >= _size) {
                throw std::exception();
            }
            return this->_buffer[idx];
        }
        // Replaces the elements of a vector with a copy of another vector
        void operator=(const Dynamic_array<T, Allocator>& other) {
            return;
        }
    };
}

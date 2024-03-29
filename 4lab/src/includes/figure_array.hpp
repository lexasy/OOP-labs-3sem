#include "pentagon.hpp"
#include "hexagon.hpp"
#include "octagon.hpp"

#define CAPACITY 10

template <class T>
concept Arrayable = std::is_default_constructible<T>::value;

// Dynamic array of <T>
template <Arrayable T>
class Figure_array {
public:
    // Default constructor
    Figure_array() {
        this->array = std::shared_ptr<T[]>(new T[CAPACITY]);
        this->size = 0; this->capacity = CAPACITY;
    }
    // Overloaded [] array operator
    T operator[](size_t idx) {
        return this->array[idx];
    }
    // Append method
    void append_figure(T fig) {
        if (this->size == this->capacity) {
            this->expand();
        }
        this->array[this->size] = fig;
        this->size++;
    }
    // Remove method
    void rmv_figure(size_t idx) {
        this->array[idx] = nullptr;
        for (size_t i = idx; i < this->size - 1; i++) {
            this->array[i] = this->array[i + 1];
        }
        this->array[this->size - 1] = nullptr;
        this->size--;
    }
    // Size of array
    size_t size;
    // Destructor
    ~Figure_array() {
        this->size = 0; this->capacity = 0;
    }
private:
    // Array
    std::shared_ptr<T[]> array;
    // Capacity of array
    size_t capacity;
    // Array expander
    void expand() {
        std::shared_ptr<T[]> new_array = std::shared_ptr<T[]>(new T[this->capacity + CAPACITY]);
        for (size_t i = 0; i < this->size; i++) {
            new_array[i] = this->array[i];
        }
        this->array = new_array; this->capacity += CAPACITY;
    }
};


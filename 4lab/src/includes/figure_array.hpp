#include "pentagon.hpp"
#include "hexagon.hpp"
#include "octagon.hpp"

#define CAPACITY 10

template <class T>
concept Arrayable = std::is_default_constructible<T>::value;

template <Arrayable T>
class Figure_array {
public:
    Figure_array() {
        this->array = std::shared_ptr<T[]>(new T[CAPACITY]);
        this->size = 0; this->capacity = CAPACITY;
    }
    T operator[](size_t idx) {
        return this->array[idx];
    }
    void append_figure(T fig) {
        if (this->size == this->capacity) {
            this->expand();
        }
        this->array[this->size] = fig;
        this->size++;
    }
    void rmv_figure(size_t idx) {
        this->array[idx] = nullptr;
        for (size_t i = idx; i < this->size - 1; i++) {
            this->array[i] = this->array[i + 1];
        }
        this->array[this->size - 1] = nullptr;
        this->size--;
    }
    std::shared_ptr<T[]> array;
    size_t size;
    ~Figure_array() {
        this->size = 0; this->capacity = 0;
    }
private:
    size_t capacity;
    void expand() {
        std::shared_ptr<T[]> new_array = std::shared_ptr<T[]>(new T[this->capacity + CAPACITY]);
        for (size_t i = 0; i < this->size; i++) {
            new_array[i] = this->array[i];
        }
        this->array = new_array; this->capacity += CAPACITY;
    }
};


#include "../includes/figure_array.hpp"

Figure_array *create_array() {
    Figure_array *arr = new Figure_array;
    arr->array = new Figure*[CAPACITY];
    arr->size = 0; arr->capacity = CAPACITY;
    return arr;
}

// Array expander
static void expand(Figure_array *arr) {
    Figure **new_array = new Figure*[arr->capacity + CAPACITY];
    for (int i = 0; i < arr->size; i++) {
        new_array[i] = arr->array[i];
    }
    delete[] arr->array;
    arr->array = new_array;
    arr->capacity += CAPACITY;
}

void append_figure(Figure_array *arr, Figure *fig) {
    if (arr->size == arr->capacity) {
        expand(arr);
    }
    arr->array[arr->size] = fig;
    arr->size++;
}

Figure **rmv_figure(Figure_array *arr, int idx) {
    Figure **new_array = new Figure*[arr->capacity]; int flag = 0;
    for (int i = 0; i < arr->size; i++) {
        if (i == idx) {
            flag = 1; continue;
        }
        new_array[i - flag] = arr->array[i];
    }
    delete[] arr->array;
    return new_array;
}

void destroy_array(Figure_array *arr) {
    arr->capacity = 0; arr->size = 0;
    delete[] arr->array;
    arr->array = nullptr;
    delete[] arr;
    arr = nullptr;
}
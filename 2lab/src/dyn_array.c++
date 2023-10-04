#include "dyn_array.h"

static bool increase_buffer(uchar_vector *v) {
    int new_cap = v->cap * 2;
    if (new_cap < MIN_CAPACITY) {
        new_cap = MIN_CAPACITY;
    }
    u_char *tmp = new u_char[new_cap];
    for (int i = 0; i < v->size; i++) {
        tmp[i] = get_elem(v, i);
    }
    u_char *old_buff = v->buf;
    v->buf = tmp;
    delete(old_buff);
    v->cap = new_cap;
    return true;
}

uchar_vector *create_vector() {
    uchar_vector *tmp = new uchar_vector;
    tmp->buf = new u_char[MIN_CAPACITY];
    tmp->cap = MIN_CAPACITY;
    tmp->head = 0;
    tmp->tail = 0;
    tmp->size = 0;
    return tmp;
}

int get_size(uchar_vector *v) {
    return v->size;
}

bool is_empty(uchar_vector *v) {
    return v->size == 0;
}

u_char get_elem(uchar_vector *v, int idx) {
    return v->buf[v->head + idx];
}

void set_elem(uchar_vector *v, int idx, u_char val) {
    v->buf[v->head + idx] = val;
}

bool push_back(uchar_vector *v, u_char val) {
    v->tail = v->head + v->size;
    if ((v->tail == v->cap) && (!increase_buffer(v))) {
        return false;
    }
    v->buf[v->tail] = val;
    v->size++;
    return true;
}

u_char pop_back(uchar_vector *v) {
    int res = v->buf[v->tail];
    v->buf[v->tail] = 0;
    v->tail--;
    v->size--;
    return res;
}

void destroy(uchar_vector *v) {
    if (v->size > 0) {
        v->size = 0;
        v->head = 0;
        v->tail = 0;
        delete[] v->buf;
    }
    v->cap = 0;
    v->buf = nullptr;
}

void print_vector(uchar_vector *v) {
    for (int i = 0; i < v->size; i++) {
        std::cout << v->buf[i] << " ";
    }
    printf("\n");
}
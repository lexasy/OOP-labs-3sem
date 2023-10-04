#pragma once

#include <iostream>

#define MIN_CAPACITY 10

typedef struct {
    u_char *buf;
    int cap;
    int size;
    int head;
    int tail;
} uchar_vector;

uchar_vector *create_vector();
int get_size(uchar_vector *v);
bool is_empty(uchar_vector *v);
u_char get_elem(uchar_vector *v, int idx);
void set_elem(uchar_vector *v, int idx, u_char val);
bool push_back(uchar_vector *v, u_char val);
u_char pop_back(uchar_vector *v);
void destroy(uchar_vector *v);
void print_vector(uchar_vector *v);
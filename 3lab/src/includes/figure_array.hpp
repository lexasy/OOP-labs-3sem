#include "pentagon.hpp"
#include "hexagon.hpp"
#include "octagon.hpp"

#define CAPACITY 10

typedef struct {
    Figure **array;
    int size; int capacity;
} Figure_array;

Figure_array *create_array();
void append_figure(Figure_array *arr, Figure *fig);
Figure **rmv_figure(Figure_array *arr, int idx);
void destroy_array(Figure_array *arr);
#include "pentagon.hpp"
#include "hexagon.hpp"
#include "octagon.hpp"

#define CAPACITY 10

// Dynamic array of figure points
typedef struct {
    // Array of figure pointers
    Figure **array;
    // Figure pointers array size
    int size;
    // Figure pointers array capacity
    int capacity;
} Figure_array;

// Array creator
Figure_array *create_array();
// Appends figure to the tail of figure array
void append_figure(Figure_array *arr, Figure *fig);
// Removes figure from figure array by index
Figure **rmv_figure(Figure_array *arr, int idx);
// Array destroyer
void destroy_array(Figure_array *arr);
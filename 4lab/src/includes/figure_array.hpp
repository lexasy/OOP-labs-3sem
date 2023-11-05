#include "pentagon.hpp"
#include "hexagon.hpp"
#include "octagon.hpp"

#define CAPACITY 10

template <Numeric T>
class Figure_array {
public:
    Figure_array();
    void append_figure(std::shared_ptr<Figure<T>> fig);
    void rmv_figure(size_t idx);
    std::shared_ptr<Figure<T>[]> array;
    size_t size;
    size_t capacity;
    ~Figure_array();
};


#include <deque>
#include <array>
#include <memory>
#include <map>
#include <iostream>

template <class T, std::size_t BLOCK_SIZE>
class Allocator {
private:
    std::deque<T> _used_blocks;
    std::deque<T *> _free_blocks;
    size_t _free_count;
public:
    static constexpr size_t max_count = BLOCK_SIZE;
    using value_type = T;
    using pointer = T *;
    using const_pointer = const T *;
    using size_type = std::size_t;
    Allocator() {
        _used_blocks.resize(max_count); _free_blocks.resize(max_count);
        _free_count = max_count;
        for (size_t i = 0; i < max_count; i++) {
            _free_blocks[i] = &_used_blocks[i];
        } 
    }
    ~Allocator() = default;
    template <class U>
    struct rebind{
        using other = Allocator<U, BLOCK_SIZE>;
    };
    T *allocate(std::size_t n) {
        T *result = nullptr;
        if (_free_count > 0) {
            result = _free_blocks[--_free_count];
        }
        return result;
    }
    void deallocate(T *ptr, std::size_t n) {
        _free_blocks[_free_count++] = ptr;
    }
};
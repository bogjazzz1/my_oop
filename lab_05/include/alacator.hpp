#ifndef ALACATOR_HPP_INCLUDED
#define ALACATOR_HPP_INCLUDED
#include <iostream>
#include <vector>
//#define DEBUG
namespace mai
{
template<class T>
class Allocator
{
private:
    std::vector<T> _used_blocks;
    std::vector<void *> _free_blocks;
    uint64_t _free_count;

public:
    static constexpr size_t max_count = 5000000;
    using value_type = T;
    using pointer = T *;
    using const_pointer = const T *;
    using size_type = std::size_t;

    Allocator()
    {
        _used_blocks.reserve(max_count);
        _free_blocks.reserve(max_count);

        for (uint64_t i = 0; i < max_count; i++)
            _free_blocks[i] = &(_used_blocks[i]);
        _free_count = max_count;
#ifdef DEBUG
        std::cout << "allocator: memory init" << std::endl;
#endif
    }

    ~Allocator()
    {
        _free_count = max_count;
        _used_blocks.clear();
        _free_blocks.clear();
#ifdef DEBUG
        if (_free_count < max_count)
            std::cout << "allocator: Memory leak?" << -_free_count + max_count << std::endl;

        else
            std::cout << "allocator: Memory freed" << std::endl;
#endif
    }

    template<class U>
    struct rebind {
        using other = Allocator<U>;
    };

    T *allocate(size_t n)
    {

        T *result = nullptr;
        /* while(_free_count<n){
                    std::cout << "allocator: No memory exception :-). Expanding" << std::endl;
                _free_count+=max_count;
                max_count*=2;

                _used_blocks.reserve(max_count);
                _free_blocks.reserve(max_count);

            for (uint64_t i = 0; i < max_count; i++)
                _free_blocks[i] = &(_used_blocks[i]);
            _free_count = max_count;
            }*/
        if (_free_count >= n) {
            _free_count -= n;
            result = (T *) _free_blocks[_free_count];


#ifdef DEBUG
            std::cout << "allocator: Allocate " << (max_count - _free_count) << " of " << max_count << " Address:" << result << std::endl;
#endif
        }
        else {
            std::cout << "allocator: No memory exception :-)." << std::endl;
            throw std::range_error("No memory exception :-)");
        }

        return result;
    }

    void deallocate(T *pointer, size_t n)
    {

#ifdef DEBUG

        std::cout << "allocator: Deallocate block " << n << std::endl;
#endif
    }
    template<typename U, typename... Args>
    void construct(U *p, Args &&...args)
    {
        new (p) U(std::forward<Args>(args)...);
    }

    void destroy(pointer p)
    {
        p->~T();
    }
};

template<class T, class U>
constexpr bool operator==(const Allocator<T> &lhs, const Allocator<U> &rhs)
{
    return true;
}

template<typename T, typename U, size_t BLOCK_COUNT>
constexpr bool operator!=(const Allocator<T> &lhs, const Allocator<U> &rhs)
{
    return false;
}
}// namespace mai


#endif// ALACATOR_HPP_INCLUDED

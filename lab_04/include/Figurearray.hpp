#ifndef FIGUREARRAY_HPP_INCLUDED
#define FIGUREARRAY_HPP_INCLUDED
#include <memory>

template<typename T>
class FigureArray
{
    size_t _size = 0;
    std::shared_ptr<T[]> _array = nullptr;

public:
    FigureArray() = default;
    FigureArray(size_t n);
    FigureArray(const FigureArray &other);
    FigureArray(FigureArray &&other) noexcept;
    FigureArray(const std::initializer_list<T> &t);
    ~FigureArray() = default;
    void erase(size_t index);
    size_t size() const;
    bool empty() const;
    T &operator[](size_t pos);
    const T &operator[](size_t pos) const;
};
#include "../src/FigureArray.cpp"
#endif// FIGUREARRAY_HPP_INCLUDED

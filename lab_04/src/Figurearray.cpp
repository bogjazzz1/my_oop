#include "../include/Figurearray.hpp"

template<typename T>
size_t FigureArray<T>::size() const
{
    return _size;
}


template<typename T>
FigureArray<T>::FigureArray(const std::initializer_list<T> &t)
{
    _array = std::shared_ptr<T[]>(new T[t.size()]);
    size_t i{0};
    for (auto &c: t)
        _array[i++] = c;
    _size = t.size();
}
template<typename T>
FigureArray<T>::FigureArray(size_t n)
{
    _array = std::shared_ptr<T[]>(new T[n]);
    size_t i{0};
    for (; i < n;)
        _array[i++] = T();
    _size = n;
}
template<typename T>
FigureArray<T>::FigureArray(const FigureArray<T> &other)
{
    _size = other._size;
    _array = std::shared_ptr<T[]>(new T[_size]);

    for (size_t i{0}; i < _size; ++i)
        _array[i] = other._array[i];
}

template<typename T>
FigureArray<T>::FigureArray(FigureArray<T> &&other) noexcept
{

    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
}
template<typename T>
void FigureArray<T>::erase(size_t index)
{
    if (index >= _size) {
        throw std::out_of_range("The requested position is outside the vector");
    }
    _array.get()[index].~T();
    for (size_t i = index; i < _size - 1; ++i) {
        _array[i] = _array[i + 1];
    }
    --_size;
}
template<typename T>
bool FigureArray<T>::empty() const
{
    return _size == 0;
}
template<typename T>
T &FigureArray<T>::operator[](size_t pos)
{
    if (pos > _size) {
        throw std::out_of_range("Out of range");
    }
    return _array[pos];
}
template<typename T>
const T &FigureArray<T>::operator[](size_t pos) const
{
    if (pos > _size) {
        throw std::out_of_range("Out of range");
    }
    return _array[pos];
}

#ifndef ITERATOR_HPP_INCLUDED
#define ITERATOR_HPP_INCLUDED
#include <memory>
template<typename T>
class Iterator
{
    T *pointer;
    size_t index = 0;
    size_t size = 0;

public:
    Iterator() = default;
    Iterator(T *_node, size_t i, size_t s);
    Iterator(const Iterator &other);
    Iterator &operator=(const Iterator &other);
    Iterator &operator++();
    bool operator==(Iterator b) const;
    bool operator>=(Iterator b) const;
    bool operator>(Iterator b) const;
    bool operator!=(Iterator b) const;
    size_t get_index() const;
    size_t get_size() const;
    ~Iterator() = default;
    T &operator*();
    T &operator->();
};

template<typename T>
Iterator<T>::Iterator(T *_node, size_t i, size_t s) : pointer(_node), index(i), size(s)
{}
template<typename T>
Iterator<T> &Iterator<T>::operator++()
{
    ++index;
    return *this;
}
template<typename T>
Iterator<T>::Iterator(const Iterator &other)
{
    pointer = other.pointer;
    index = other.index;
    size = other.size;
}
template<typename T>
Iterator<T> &Iterator<T>::operator=(const Iterator<T> &other)
{
    pointer = other.pointer;
    index = other.index;
    size = other.size;
    return *this;
}
template<typename T>
size_t Iterator<T>::get_index() const
{
    return index;
}
template<typename T>
size_t Iterator<T>::get_size() const
{
    return size;
}
template<typename T>
bool Iterator<T>::operator==(Iterator<T> b) const
{
    return (this->pointer == b.pointer) && (this->index == b.index);
}
template<typename T>
bool Iterator<T>::operator>=(Iterator<T> b) const
{
    return (this->pointer == b.pointer) && (this->index >= b.index);
}
template<typename T>
bool Iterator<T>::operator>(Iterator<T> b) const
{
    return (this->pointer == b.pointer) && (this->index > b.index);
}
template<typename T>
bool Iterator<T>::operator!=(Iterator<T> b) const
{
    return !((this->pointer == b.pointer) && (this->index == b.index));
}
template<typename T>
T &Iterator<T>::operator*()
{
    if (index >= size) {
        throw std::out_of_range("Outside the container");
    }
    return (pointer)[index];
}
template<typename T>
T &Iterator<T>::operator->()
{
    if (index >= size) {
        throw std::out_of_range("Outside the container");
    }
    return (pointer)[index];
}

#endif// ITERATOR_HPP_INCLUDED

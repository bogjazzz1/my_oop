#ifndef CONSTITERATOR_HPP_INCLUDED
#define CONSTITERATOR_HPP_INCLUDED
#include <memory>
template<typename T>
class Const_Iterator
{
    const T *pointer;
    size_t index = 0;
    size_t size = 0;

public:
    Const_Iterator() = default;
    Const_Iterator(const T *_node, size_t i, size_t s);
    Const_Iterator(const Const_Iterator &other);
    Const_Iterator &operator=(const Const_Iterator &other);
    Const_Iterator &operator++();
    bool operator==(Const_Iterator b) const;
    bool operator>=(Const_Iterator b) const;
    bool operator>(Const_Iterator b) const;
    bool operator!=(Const_Iterator b) const;
    size_t get_index() const;
    size_t get_size() const;
    ~Const_Iterator() = default;
    const T &operator*() const;
    const T &operator->() const;
};

template<typename T>
Const_Iterator<T>::Const_Iterator(const T *_node, size_t i, size_t s) : pointer(_node), index(i), size(s)
{}
template<typename T>
Const_Iterator<T> &Const_Iterator<T>::operator++()
{
    ++index;
    return *this;
}
template<typename T>
Const_Iterator<T>::Const_Iterator(const Const_Iterator &other)
{
    pointer = other.pointer;
    index = other.index;
    size = other.size;
}
template<typename T>
Const_Iterator<T> &Const_Iterator<T>::operator=(const Const_Iterator<T> &other)
{
    pointer = other.pointer;
    index = other.index;
    size = other.size;
    return *this;
}
template<typename T>
size_t Const_Iterator<T>::get_index() const
{
    return index;
}
template<typename T>
size_t Const_Iterator<T>::get_size() const
{
    return size;
}
template<typename T>
bool Const_Iterator<T>::operator==(Const_Iterator<T> b) const
{
    return (this->pointer == b.pointer) && (this->index == b.index);
}
template<typename T>
bool Const_Iterator<T>::operator>=(Const_Iterator<T> b) const
{
    return (this->pointer == b.pointer) && (this->index >= b.index);
}
template<typename T>
bool Const_Iterator<T>::operator>(Const_Iterator<T> b) const
{
    return (this->pointer == b.pointer) && (this->index > b.index);
}
template<typename T>
bool Const_Iterator<T>::operator!=(Const_Iterator<T> b) const
{
    return !((this->pointer == b.pointer) && (this->index == b.index));
}
template<typename T>
const T &Const_Iterator<T>::operator*() const
{
    if (index >= size) {
        throw std::out_of_range("Outside the container");
    }
    return (pointer)[index];
}
template<typename T>
const T &Const_Iterator<T>::operator->() const
{
    if (index >= size) {
        throw std::out_of_range("Outside the container");
    }
    return (pointer)[index];
}

#endif// ITERATOR_HPP_INCLUDED

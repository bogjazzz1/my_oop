#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED
#include <iostream>
template<typename T>
class Vector
{
    T *arr;
    size_t sz;
    size_t cap;

public:
    Vector();
    Vector(const Vector &copyd);
    Vector(std::initializer_list<T> init);
    void reserve(size_t n);
    void push_back(const T &value);
    void pop_back();
    bool empty();
    size_t size() const;
    size_t capacity() const;
    void erase(size_t index);
    T &operator[](size_t pos);
    const T &operator[](size_t pos) const;
    bool operator==(Vector &b);
    bool operator!=(Vector &b);
    ~Vector();
};
#include "../src/Vector.cpp"

#endif// VECTOR_HPP_INCLUDED

#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED
#include "constiterator.hpp"
#include "iterator.hpp"
#include <iostream>
#include <memory>
template<typename T, class Allocator = std::allocator<T>>
class Vector
{
    T *arr;
    size_t sz;
    size_t cap;
    Allocator alloc;

public:
    Vector();
    Vector(const Vector &copyd);
    Vector(std::initializer_list<T> init);
    Vector &operator=(const Vector &copyd);
    Vector(const size_t num, const T &value = T());
    void reserve(size_t n);
    void resize(size_t n, const T &value = T());
    void push_back(const T &value);
    template<typename... Args>
    void emplace_back(Args &&...args);
    void pop_back();
    T &at(size_t pos);
    const T &at(size_t pos) const;
    T &front();
    const T &front() const;
    T &back();
    const T &back() const;
    bool empty();
    size_t size() const;
    size_t capacity() const;
    void shrink_to_fit();
    void clear();
    T &operator[](size_t pos);
    const T &operator[](size_t pos) const;
    bool operator==(Vector &b);
    bool operator!=(Vector &b);
    Iterator<T> begin();
    Iterator<T> end();
    Const_Iterator<T> cbegin() const;
    Const_Iterator<T> cend() const;
    Iterator<T> erase(Iterator<T> it);
    Iterator<T> insert(Iterator<T> it, const T &val);
    void insert(Iterator<T> it, const T &val, const size_t n);
    ~Vector();
};
template<typename T, class Allocator>
Vector<T, Allocator>::Vector()
{
    arr = alloc.allocate(1);
    sz = 0;
    cap = 1;
}
template<typename T, class Allocator>
Vector<T, Allocator>::Vector(const Vector<T, Allocator> &copyd)
{
    sz = copyd.sz;
    cap = copyd.cap;
    T *new_arr = alloc.allocate(cap);

    try {
        std::uninitialized_copy(copyd.arr, copyd.arr + copyd.sz, new_arr);
    }
    catch (...) {
        alloc.deallocate(new_arr, cap);
        throw;
    }
    arr = new_arr;
}
template<class T, class Allocator>
Vector<T, Allocator>::Vector(const size_t num, const T &value)
{
    cap = num + 1;
    sz = num;
    arr = alloc.allocate(cap);
    std::fill_n(arr, num, value);
}
template<typename T, class Allocator>
Vector<T, Allocator>::Vector(std::initializer_list<T> init)
{
    T *new_arr = alloc.allocate(init.size());

    try {
        std::uninitialized_copy(init.begin(), init.end(), new_arr);
    }
    catch (...) {
        alloc.deallocate(new_arr, init.size());
        throw;
    }
    arr = new_arr;
    cap = init.size();
    sz = init.size();
}
template<typename T, class Allocator>
void Vector<T, Allocator>::reserve(size_t n)
{
    if (n > UINT_MAX) {
        throw std::range_error("capacity overflow");
    }
    if (n < cap)
        return;
    T *new_arr = alloc.allocate(n);
    try {
        std::uninitialized_copy(arr, arr + sz, new_arr);
    }
    catch (...) {
        alloc.deallocate(new_arr, n);
        throw;
    }
    for (size_t i = 0; i < sz; ++i) {
        arr[i].~T();
    }
    alloc.deallocate(arr, cap);
    arr = new_arr;
    cap = n;
}
template<typename T, class Allocator>
void Vector<T, Allocator>::resize(size_t n, const T &value)
{
    if (n > UINT_MAX) {
        throw std::range_error("capacity overflow");
    }
    if (n > cap) {

        reserve(n);
    }

    if (n < sz) {
        for (size_t i = n; i < sz; ++i) {
            arr[i].~T();
        }
    }
    if (n > sz) {
        for (size_t i = sz; i < n; ++i) {
            new (arr + i) T(value);
        }
    }
    for (size_t i = 0; i < sz; ++i) {
        arr[i] = T(value);
    }
    sz = n;
}
template<typename T, class Allocator>
void Vector<T, Allocator>::push_back(const T &value)
{

    if (cap == sz) {
        if (cap * 2 < cap) {
            throw std::range_error("capacity overflow");
        }
        reserve(2 * cap);
    }
    new (arr + sz) T(value);
    ++sz;
}
template<typename T, class Allocator>
template<typename... Args>
void Vector<T, Allocator>::emplace_back(Args &&...args)
{

    push_back(T(args...));
}
template<typename T, class Allocator>
void Vector<T, Allocator>::pop_back()
{

    if (sz > 0) {
        --sz;
        arr[sz].~T();
    }
    else {
        return;
    }
}
template<typename T, class Allocator>
Vector<T, Allocator>::~Vector()
{
    for (size_t i = 0; i < sz; ++i) {

        arr[i].~T();
    }

    alloc.deallocate(arr, cap);

    sz = 0;
    cap = 0;
}
template<typename T, class Allocator>
T &Vector<T, Allocator>::at(size_t pos)
{

    if (pos < sz) {
        return arr[pos];
    }
    else {
        throw std::out_of_range("The requested position is outside the vector");
    }
}
template<typename T, class Allocator>
const T &Vector<T, Allocator>::at(size_t pos) const
{

    if (pos < sz) {
        return arr[pos];
    }
    else {
        throw std::out_of_range("The requested position is outside the vector");
    }
}
template<typename T, class Allocator>
T &Vector<T, Allocator>::front()
{
    return arr[0];
}
template<typename T, class Allocator>
const T &Vector<T, Allocator>::front() const
{
    return arr[0];
}
template<typename T, class Allocator>
T &Vector<T, Allocator>::back()
{
    return arr[sz - 1];
}
template<typename T, class Allocator>
const T &Vector<T, Allocator>::back() const
{
    return arr[sz - 1];
}
template<typename T, class Allocator>
bool Vector<T, Allocator>::empty()
{
    return sz == 0;
}
template<typename T, class Allocator>
size_t Vector<T, Allocator>::size() const
{
    return sz;
}
template<typename T, class Allocator>
size_t Vector<T, Allocator>::capacity() const
{
    return cap;
}
template<typename T, class Allocator>
void Vector<T, Allocator>::clear()
{

    for (size_t i = 0; i < sz; ++i) {
        arr[i].~T();
    }
    sz = 0;
}
template<typename T, class Allocator>
void Vector<T, Allocator>::shrink_to_fit()
{
    T *new_arr = alloc.allocate(sz);
    try {
        std::uninitialized_copy(arr, arr + sz, new_arr);
    }
    catch (...) {
        alloc.deallocate(new_arr, sz);
        throw;
    }
    for (size_t i = sz; i < cap; ++i) {
        arr[i].~T();
    }
    alloc.deallocate(arr, cap);
    arr = new_arr;
    cap = sz;
    if (!cap) {
        cap = 1;
    }
}
template<typename T, class Allocator>
Vector<T, Allocator> &Vector<T, Allocator>::operator=(const Vector<T, Allocator> &copyd)
{
    for (size_t i = 0; i < sz; ++i) {
        arr[i].~T();
    }
    alloc.deallocate(arr, cap);
    sz = copyd.sz;
    cap = copyd.cap;
    T *new_arr = alloc.allocate(cap);

    try {
        std::uninitialized_copy(copyd.arr, copyd.arr + copyd.sz, new_arr);
    }
    catch (...) {
        alloc.deallocate(new_arr, cap);
        throw;
    }
    arr = new_arr;
    return *this;
}
template<typename T, class Allocator>
T &Vector<T, Allocator>::operator[](size_t pos)
{
    return arr[pos];
}
template<typename T, class Allocator>
const T &Vector<T, Allocator>::operator[](size_t pos) const
{
    return arr[pos];
}
template<typename T, class Allocator>
bool Vector<T, Allocator>::operator==(Vector<T, Allocator> &b)
{

    if (sz != b.sz) {
        return false;
    }
    for (size_t i = 0; i < sz; ++i) {
        if (this->arr[i] != b.arr[i]) {
            return false;
        }
    }
    return true;
}
template<typename T, class Allocator>
bool Vector<T, Allocator>::operator!=(Vector<T, Allocator> &b)
{

    if (sz != b.sz) {
        return true;
    }
    for (size_t i = 0; i < sz; ++i) {
        if (this->arr[i] != b.arr[i]) {
            return true;
        }
    }
    return false;
}
template<typename T, class Allocator>
Iterator<T> Vector<T, Allocator>::begin()
{
    return Iterator(arr, 0, sz);
}
template<typename T, class Allocator>
Iterator<T> Vector<T, Allocator>::end()
{
    return Iterator(arr, sz, sz);
}
template<typename T, class Allocator>
Const_Iterator<T> Vector<T, Allocator>::cbegin() const
{
    return Const_Iterator(arr, 0, sz);
}
template<typename T, class Allocator>
Const_Iterator<T> Vector<T, Allocator>::cend() const
{
    return Const_Iterator(arr, sz, sz);
}
template<typename T, class Allocator>
Iterator<T> Vector<T, Allocator>::erase(Iterator<T> it)
{
    size_t index = it.get_index();
    if (index >= sz) {
        throw std::out_of_range("The requested position is outside the vector");
    }
    if (!sz) {
        return begin();
    }
    if (index == sz - 1) {
        pop_back();
        return Iterator<T>(arr, index, sz);
    }

    arr[index].~T();

    for (size_t i = index; i < sz - 1; ++i) {

        arr[i] = arr[i + 1];
    }

    pop_back();
    return Iterator<T>(arr, index, sz);
}
template<typename T, class Allocator>
Iterator<T> Vector<T, Allocator>::insert(Iterator<T> it, const T &val)
{
    size_t index = it.get_index();
    push_back(T());
    for (size_t i = sz - 1; i > index; --i) {
        arr[i] = arr[i - 1];
    }
    arr[index] = val;
    return Iterator<T>(arr, index, sz);
}
template<typename T, class Allocator>
void Vector<T, Allocator>::insert(Iterator<T> it, const T &val, const size_t n)
{
    for (size_t i = 0; i < n; ++i) {
        it = insert(it, val);
    }
}
#endif// VECTOR_HPP_INCLUDED

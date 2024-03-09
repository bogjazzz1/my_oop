#include "../include/Point.hpp"
#include <float.h>

template <typename T>
requires std::integral<T> || std::floating_point<T>
Point<T>::Point(T x, T y) : _x(x), _y(y) {}
template <typename T>
requires std::integral<T> || std::floating_point<T>
Point<T>::Point(const Point<T> &other) : _x(other._x), _y(other._y) {}
template <typename T>
requires std::integral<T> || std::floating_point<T>
Point<T>::Point(Point<T> &&other) noexcept
{
    _x = std::move(other._x);
    _y = std::move(other._y);
}
template <typename T>
requires std::integral<T> || std::floating_point<T>
Point<T> &Point<T>::operator=(const Point<T> &other)
{
    if (this != &other) {
        _x = other._x;
        _y = other._y;
    }
    return *this;
}
template <typename T>
requires std::integral<T> || std::floating_point<T>
Point<T> &Point<T>::operator=(Point<T> &&other)
{
    _x = std::move(other._x);
    _y = std::move(other._y);
    return *this;
}
template <typename T>
requires std::integral<T> || std::floating_point<T>
T Point<T>::get_x() const
{
    return _x;
}
template <typename T>
requires std::integral<T> || std::floating_point<T>
void Point<T>::set_x(T x)
{
    _x = x;
}
template <typename T>
requires std::integral<T> || std::floating_point<T>
T Point<T>::get_y() const
{
    return _y;
}
template <typename T>
requires std::integral<T> || std::floating_point<T>
void Point<T>::set_y(T y)
{
    _y = y;
}
template <typename T>
requires std::integral<T> || std::floating_point<T>
std::istream &operator>>(std::istream &in, Point<T> &x)
{
    in >> x._x >> x._y;
    return in;
}
template <typename T>
requires std::integral<T> || std::floating_point<T>
std::ostream &operator<<(std::ostream &out, const Point<T> &x)
{
    out << x._x << " " << x._y;
    return out;
}
template <typename T>
requires std::integral<T> || std::floating_point<T>
bool Point<T>::operator==(const Point<T> &other) const
{
    return (std::abs(_x - other._x) < FLT_EPSILON) && (std::abs(_y - other._y) < FLT_EPSILON);
}

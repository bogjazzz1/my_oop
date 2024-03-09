#include "../../include/Point.hpp"
#include <float.h>
Point::Point(double x, double y) : _x(x), _y(y) {}
Point::Point(const Point &other) : _x(other._x), _y(other._y) {}
Point::Point(Point &&other) noexcept
{
    _x = std::move(other._x);
    _y = std::move(other._y);
}
Point &Point::operator=(const Point &other)
{
    if (this != &other) {
        _x = other._x;
        _y = other._y;
    }
    return *this;
}
Point &Point::operator=(Point &&other)
{
    _x = std::move(other._x);
    _y = std::move(other._y);
    return *this;
}
double Point::get_x() const
{
    return _x;
}
void Point::set_x(double x)
{
    _x = x;
}
double Point::get_y() const
{
    return _y;
}
void Point::set_y(double y)
{
    _y = y;
}
std::istream &operator>>(std::istream &in, Point &x)
{
    in >> x._x >> x._y;
    return in;
}
std::ostream &operator<<(std::ostream &out, const Point &x)
{
    out << x._x << " " << x._y;
    return out;
}
bool Point::operator==(const Point &other) const
{
    return (std::abs(_x - other._x) < FLT_EPSILON) && (std::abs(_y - other._y) < FLT_EPSILON);
}

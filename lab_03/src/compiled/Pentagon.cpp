#include "../../include/pentagon.hpp"
#include <float.h>
const double pi = M_PI;
bool Pentagon::check_Pentagon(const Point &a, const Point &b, const Point &c, const Point &d, const Point &e) const
{
    double fr_side = std::sqrt((a.get_x() - b.get_x()) * (a.get_x() - b.get_x()) + (a.get_y() - b.get_y()) * (a.get_y() - b.get_y()));
    double s_side = std::sqrt((c.get_x() - b.get_x()) * (c.get_x() - b.get_x()) + (c.get_y() - b.get_y()) * (c.get_y() - b.get_y()));
    double t_side = std::sqrt((c.get_x() - d.get_x()) * (c.get_x() - d.get_x()) + (c.get_y() - d.get_y()) * (c.get_y() - d.get_y()));
    double fo_side = std::sqrt((e.get_x() - d.get_x()) * (e.get_x() - d.get_x()) + (e.get_y() - d.get_y()) * (e.get_y() - d.get_y()));
    double fi_side = std::sqrt((a.get_x() - e.get_x()) * (a.get_x() - e.get_x()) + (a.get_y() - e.get_y()) * (a.get_y() - e.get_y()));
    if (!(std::abs(fr_side - s_side) < FLT_EPSILON && std::abs(s_side - t_side) < FLT_EPSILON && std::abs(fo_side - t_side) < FLT_EPSILON && std::abs(fi_side - fo_side) < FLT_EPSILON)) {//��� double_������� ��� � ������
        return false;
    }
    return true;
}
Pentagon::Pentagon(const Point &a, const Point &b, const Point &c, const Point &d, const Point &e)
{//����� �� ������� �������, ������� � ����� �����

    if (!check_Pentagon(a, b, c, d, e)) {//����� �� ������ �� ������� ��������, ��� ���������� ��� ���������� ��������
        throw std::logic_error("Not creating a pentagon");
    }
    side = std::sqrt((a.get_x() - b.get_x()) * (a.get_x() - b.get_x()) + (a.get_y() - b.get_y()) * (a.get_y() - b.get_y()));
    _a = a;
    _b = b;
    _c = c;
    _d = d;
    _e = e;
}
Pentagon::Pentagon(double _side)
{
    if (_side <= 0) {
        throw std::logic_error("wrong side");
    }
    side = _side;
    double Radius = side * std::sqrt((0.5) + (std::sqrt(5) / 10));
    _a = Point(Radius * std::cos(0 * 2 * pi / 5), Radius * std::sin(0 * 2 * pi / 5));
    _b = Point(Radius * std::cos(1 * 2 * pi / 5), Radius * std::sin(1 * 2 * pi / 5));
    _c = Point(Radius * std::cos(2 * 2 * pi / 5), Radius * std::sin(2 * 2 * pi / 5));
    _d = Point(Radius * std::cos(3 * 2 * pi / 5), Radius * std::sin(2 * 3 * pi / 5));
    _e = Point(Radius * std::cos(4 * 2 * pi / 5), Radius * std::sin(4 * 2 * pi / 5));
}
Pentagon::Pentagon(const Pentagon &other)
{
    _a = other._a;
    _b = other._b;
    _c = other._c;
    _d = other._d;
    _e = other._e;
    side = other.side;
}
Pentagon::Pentagon(Pentagon &&other) noexcept
{
    _a = std::move(other._a);
    _b = std::move(other._b);
    _c = std::move(other._c);
    _d = std::move(other._d);
    _e = std::move(other._e);
    side = other.side;
}
Pentagon &Pentagon::operator=(Pentagon &&other) noexcept
{
    _a = std::move(other._a);
    _b = std::move(other._b);
    _c = std::move(other._c);
    _d = std::move(other._d);
    _e = std::move(other._e);
    side = other.side;

    return *this;
}
Pentagon &Pentagon::operator=(const Pentagon &other)
{
    if (this != &other) {
        _a = other._a;
        _b = other._b;
        _c = other._c;
        _d = other._d;
        side = other.side;
        _e = other._e;
    }

    return *this;
}
Point Pentagon::geometric_center() const
{
    return Point((_a.get_x() + _b.get_x() + _c.get_x() + _d.get_x() + _e.get_x()) / 5, (_a.get_y() + _b.get_y() + _c.get_y() + _d.get_y() + _e.get_y()) / 5);
}
double Pentagon::area() const
{

    return (std::sqrt(5 * (5 + 2 * (std::sqrt(5)))) * side * side) / 4;
}
Pentagon::operator double() const
{
    return (std::sqrt(5 * (5 + 2 * (std::sqrt(5)))) * side * side) / 4;
}
std::istream &operator>>(std::istream &in, Pentagon &x)
{

    in >> x._a >> x._b >> x._c >> x._d >> x._e;
    Pentagon temp(x._a, x._b, x._c, x._d, x._e);
    x = temp;
    return in;
}
std::ostream &operator<<(std::ostream &out, const Pentagon &x)
{
    out << x._a << " " << x._b << " " << x._c << " " << x._d << " " << x._e;
    return out;
}
bool Pentagon::operator==(const Pentagon &other) const
{
    return _a == other._a && _b == other._b && _c == other._c && _d == other._d && _e == other._e;
}

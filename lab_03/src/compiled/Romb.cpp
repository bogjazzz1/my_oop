#include "../../include/Romb.hpp"
#include <float.h>
    bool
    Romb::check_Romb(const Point &a, const Point &b, const Point &c, const Point &d) const
{
    double fr_side = std::sqrt((a.get_x() - b.get_x()) * (a.get_x() - b.get_x()) + (a.get_y() - b.get_y()) * (a.get_y() - b.get_y()));
    double s_side = std::sqrt((c.get_x() - b.get_x()) * (c.get_x() - b.get_x()) + (c.get_y() - b.get_y()) * (c.get_y() - b.get_y()));
    double t_side = std::sqrt((c.get_x() - d.get_x()) * (c.get_x() - d.get_x()) + (c.get_y() - d.get_y()) * (c.get_y() - d.get_y()));
    double fo_side = std::sqrt((a.get_x() - d.get_x()) * (a.get_x() - d.get_x()) + (a.get_y() - d.get_y()) * (a.get_y() - d.get_y()));

    if (!(std::abs(fr_side - s_side) < DBL_EPSILON && std::abs(s_side - t_side) < DBL_EPSILON && std::abs(fo_side - t_side) < DBL_EPSILON)) {
        return false;
    }
    return true;
}
Romb::Romb(const Point &a, const Point &b, const Point &c, const Point &d)
{

    if (!check_Romb(a, b, c, d)) {
        throw std::logic_error("Not creating a romb");
    }
    side = std::sqrt((a.get_x() - b.get_x()) * (a.get_x() - b.get_x()) + (a.get_y() - b.get_y()) * (a.get_y() - b.get_y()));
    _a = a;
    _b = b;
    _c = c;
    _d = d;
    //std::cout<<side<<std::endl;
}
Romb::Romb(double _side)
{
    if (_side <= 0) {
        throw std::logic_error("side<=0");
    }
    side = _side;
    _a = Point(0, 0);
    _b = Point(side, 0);
    _c = Point(side, side);
    _d = Point(0, side);
}
Romb::Romb(const Romb &other)
{
    _a = other._a;
    _b = other._b;
    _c = other._c;
    _d = other._d;
    side = other.side;
}
Romb::Romb(Romb &&other) noexcept
{
    _a = std::move(other._a);
    _b = std::move(other._b);
    _c = std::move(other._c);
    _d = std::move(other._d);
    side = std::move(other.side);
}
Romb &Romb::operator=(const Romb &other)
{
    if (this != &other) {
        _a = other._a;
        _b = other._b;
        _c = other._c;
        _d = other._d;
        side = other.side;
    }

    return *this;
}
Romb &Romb::operator=(Romb &&other) noexcept
{
    _a = std::move(other._a);
    _b = std::move(other._b);
    _c = std::move(other._c);
    _d = std::move(other._d);
    side = std::move(other.side);
    return *this;
}
bool Romb::operator==(const Romb &other) const
{
    return _a == other._a && _b == other._b && _c == other._c && _d == other._d;
}
Point Romb::geometric_center() const
{
    return Point((_a.get_x() + _c.get_x()) / 2, (_b.get_y() + _d.get_y()) / 2);
}
double Romb::area() const
{
    double fr_diag = std::sqrt((_a.get_x() - _c.get_x()) * (_a.get_x() - _c.get_x()) + (_a.get_y() - _c.get_y()) * (_a.get_y() - _c.get_y()));
    double sc_diag = std::sqrt((_b.get_x() - _d.get_x()) * (_b.get_x() - _d.get_x()) + (_b.get_y() - _d.get_y()) * (_b.get_y() - _d.get_y()));
    return 0.5 * fr_diag * sc_diag;
}
Romb::operator double() const
{
    double fr_diag = std::sqrt((_a.get_x() - _c.get_x()) * (_a.get_x() - _c.get_x()) + (_a.get_y() - _c.get_y()) * (_a.get_y() - _c.get_y()));
    double sc_diag = std::sqrt((_b.get_x() - _d.get_x()) * (_b.get_x() - _d.get_x()) + (_b.get_y() - _d.get_y()) * (_b.get_y() - _d.get_y()));
    return 0.5 * fr_diag * sc_diag;
}
std::istream &operator>>(std::istream &in, Romb &x)
{

    in >> x._a >> x._b >> x._c >> x._d;
    Romb temp(x._a, x._b, x._c, x._d);
    x = temp;
    return in;
}
std::ostream &operator<<(std::ostream &out, const Romb &x)
{
    out << x._a << " " << x._b << " " << x._c << " " << x._d;
    return out;
}

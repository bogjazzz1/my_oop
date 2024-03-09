#include "../include/Hexagon.hpp"
template<typename T>
requires  std::floating_point<T>
bool Hexagon<T>::check_Hexagon(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d, const Point<T> &e, const Point<T> &g) const
{
    double fr_side = std::sqrt((a.get_x() - b.get_x()) * (a.get_x() - b.get_x()) + (a.get_y() - b.get_y()) * (a.get_y() - b.get_y()));
    double s_side = std::sqrt((c.get_x() - b.get_x()) * (c.get_x() - b.get_x()) + (c.get_y() - b.get_y()) * (c.get_y() - b.get_y()));
    double t_side = std::sqrt((c.get_x() - d.get_x()) * (c.get_x() - d.get_x()) + (c.get_y() - d.get_y()) * (c.get_y() - d.get_y()));
    double fo_side = std::sqrt((e.get_x() - d.get_x()) * (e.get_x() - d.get_x()) + (e.get_y() - d.get_y()) * (e.get_y() - d.get_y()));
    double fi_side = std::sqrt((g.get_x() - e.get_x()) * (g.get_x() - e.get_x()) + (g.get_y() - e.get_y()) * (g.get_y() - e.get_y()));
    double si_side = std::sqrt((a.get_x() - g.get_x()) * (a.get_x() - g.get_x()) + (a.get_y() - g.get_y()) * (a.get_y() - g.get_y()));
    if (!(std::abs(fr_side - s_side) < FLT_EPSILON && std::abs(s_side - t_side) < FLT_EPSILON && std::abs(fo_side - t_side) < FLT_EPSILON && std::abs(fi_side - fo_side) < FLT_EPSILON && std::abs(si_side - fi_side) < FLT_EPSILON)) {//��� double_������� ��� � ������
        return false;
    }
    return true;
}
template<typename T>
requires  std::floating_point<T>
Hexagon<T>::Hexagon(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d, const Point<T> &e, const Point<T> &g)
{

    if (!check_Hexagon(a, b, c, d, e, g)) {
        throw std::logic_error("Not creating a hexagon");
    }
    side = std::sqrt((a.get_x() - b.get_x()) * (a.get_x() - b.get_x()) + (a.get_y() - b.get_y()) * (a.get_y() - b.get_y()));
    _a = a;
    _b = b;
    _c = c;
    _d = d;
    _e = e;
    _g = g;
}
template<typename T>
requires  std::floating_point<T>
Hexagon<T>::Hexagon(T _side)
{
    if (_side <= 0) {
        throw std::logic_error("wrong side");
    }
    side = _side;
    T Radius = side;
    _a = Point(Radius * std::cos(0 * 2 * pi / 6), Radius * std::sin(0 * 2 * pi / 6));
    _b = Point(Radius * std::cos(1 * 2 * pi / 6), Radius * std::sin(1 * 2 * pi / 6));
    _c = Point(Radius * std::cos(2 * 2 * pi / 6), Radius * std::sin(2 * 2 * pi / 6));
    _d = Point(Radius * std::cos(3 * 2 * pi / 6), Radius * std::sin(2 * 3 * pi / 6));
    _e = Point(Radius * std::cos(4 * 2 * pi / 6), Radius * std::sin(4 * 2 * pi / 6));
    _g = Point(Radius * std::cos(5 * 2 * pi / 6), Radius * std::sin(5 * 2 * pi / 6));
}
template<typename T>
requires  std::floating_point<T>
Hexagon<T>::Hexagon(const Hexagon<T> &other)
{
    _a = other._a;
    _b = other._b;
    _c = other._c;
    _d = other._d;
    _e = other._e;
    _g = other._g;
    side = other.side;
}
template<typename T>
requires  std::floating_point<T>
Hexagon<T>::Hexagon(Hexagon<T> &&other) noexcept
{
    _a = std::move(other._a);
    _b = std::move(other._b);
    _c = std::move(other._c);
    _d = std::move(other._d);
    _e = std::move(other._e);
    _g = std::move(other._g);
    side = other.side;
}
template<typename T>
requires  std::floating_point<T>
Hexagon<T> &Hexagon<T>::operator=(Hexagon<T> &&other) noexcept
{
    _a = std::move(other._a);
    _b = std::move(other._b);
    _c = std::move(other._c);
    _d = std::move(other._d);
    _e = std::move(other._e);
    _g = std::move(other._g);
    side = other.side;

    return *this;
}
template<typename T>
requires  std::floating_point<T>
Hexagon<T> &Hexagon<T>::operator=(const Hexagon<T> &other)
{
    if (this != &other) {
        _a = other._a;
        _b = other._b;
        _c = other._c;
        _d = other._d;
        side = other.side;
        _e = other._e;
        _g = other._g;
    }

    return *this;
}
template<typename T>
requires  std::floating_point<T>
Point<T> Hexagon<T>::geometric_center() const
{
    return Point((_a.get_x() + _b.get_x() + _c.get_x() + _d.get_x() + _e.get_x() + _g.get_x()) / 6, (_a.get_y() + _b.get_y() + _c.get_y() + _d.get_y() + _e.get_y() + _g.get_y()) / 6);
}
template<typename T>
requires  std::floating_point<T>
double Hexagon<T>::area() const
{

    return (6 * side * side * sqrt(3) / 4);
}
template<typename T>
requires  std::floating_point<T>
Hexagon<T>::operator double() const
{
    return (6 * side * side * sqrt(3) / 4);
}
template<typename T>
requires  std::floating_point<T>
std::istream &operator>>(std::istream &in, Hexagon<T> &x)
{

    in >> x._a >> x._b >> x._c >> x._d >> x._e >> x._g;
    Hexagon<T> temp(x._a, x._b, x._c, x._d, x._e, x._g);
    x = temp;
    return in;
}
template<typename T>
requires  std::floating_point<T>
std::ostream &operator<<(std::ostream &out, const Hexagon<T> &x)
{
    out << x._a << " " << x._b << " " << x._c << " " << x._d << " " << x._e << " " << x._g;
    return out;
}
template<typename T>
requires  std::floating_point<T>
bool Hexagon<T>::operator==(const Hexagon<T> &other) const
{
    return _a == other._a && _b == other._b && _c == other._c && _d == other._d && _e == other._e && _g == other._g;
}
template<typename T>
requires  std::floating_point<T>
void Hexagon<T>::print() const
{
    std::cout << *this;
}
template<typename T>
requires  std::floating_point<T>
void Hexagon<T>::read()
{
    std::cin >> *this;
}

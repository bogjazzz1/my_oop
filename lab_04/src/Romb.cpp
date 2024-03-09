#include "../include/Romb.hpp"
template<typename T>
bool Romb<T>::check_Romb(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d) const
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
template<typename T>
Romb<T>::Romb(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d)
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
template<typename T>
Romb<T>::Romb(T _side)
{
    if (_side <= 0) {
        throw std::logic_error("side<=0");
    }
    side = _side;
    _a = Point<T>(0, 0);
    _b = Point<T>(side, 0);
    _c = Point<T>(side, side);
    _d = Point<T>(0, side);
}
template<typename T>
Romb<T>::Romb(const Romb<T> &other)
{
    _a = other._a;
    _b = other._b;
    _c = other._c;
    _d = other._d;
    side = other.side;
}
template<typename T>
Romb<T>::Romb(Romb<T> &&other) noexcept
{
    _a = std::move(other._a);
    _b = std::move(other._b);
    _c = std::move(other._c);
    _d = std::move(other._d);
    side = std::move(other.side);
}
template<typename T>
Romb<T> &Romb<T>::operator=(const Romb<T> &other)
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
template<typename T>
Romb<T> &Romb<T>::operator=(Romb<T> &&other) noexcept
{
    _a = std::move(other._a);
    _b = std::move(other._b);
    _c = std::move(other._c);
    _d = std::move(other._d);
    side = std::move(other.side);
    return *this;
}
template<typename T>
bool Romb<T>::operator==(const Romb<T> &other) const
{
    return _a == other._a && _b == other._b && _c == other._c && _d == other._d;
}
template<typename T>
Point<T> Romb<T>::geometric_center() const
{
    return Point((_a.get_x() + _c.get_x()) / 2, (_b.get_y() + _d.get_y()) / 2);
}
template<typename T>
double Romb<T>::area() const
{
    double fr_diag = std::sqrt((_a.get_x() - _c.get_x()) * (_a.get_x() - _c.get_x()) + (_a.get_y() - _c.get_y()) * (_a.get_y() - _c.get_y()));
    double sc_diag = std::sqrt((_b.get_x() - _d.get_x()) * (_b.get_x() - _d.get_x()) + (_b.get_y() - _d.get_y()) * (_b.get_y() - _d.get_y()));
    return 0.5 * fr_diag * sc_diag;
}
template<typename T>
Romb<T>::operator double() const
{
    double fr_diag = std::sqrt((_a.get_x() - _c.get_x()) * (_a.get_x() - _c.get_x()) + (_a.get_y() - _c.get_y()) * (_a.get_y() - _c.get_y()));
    double sc_diag = std::sqrt((_b.get_x() - _d.get_x()) * (_b.get_x() - _d.get_x()) + (_b.get_y() - _d.get_y()) * (_b.get_y() - _d.get_y()));
    return 0.5 * fr_diag * sc_diag;
}
template<typename T>
std::istream &operator>>(std::istream &in, Romb<T> &x)
{

    in >> x._a >> x._b >> x._c >> x._d;
    Romb<T> temp(x._a, x._b, x._c, x._d);
    x = temp;
    return in;
}
template<typename T>
std::ostream &operator<<(std::ostream &out, const Romb<T> &x)
{
    out << x._a << " " << x._b << " " << x._c << " " << x._d;
    return out;
}
template<typename T>
void Romb<T>::print() const
{
    std::cout << *this;
}
template<typename T>
void Romb<T>::read()
{
    std::cin >> *this;
}

#include "../include/pentagon.hpp"

template<typename T>
requires  std::floating_point<T>
bool Pentagon<T>::check_Pentagon(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d, const Point<T> &e) const
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
template<typename T>
requires  std::floating_point<T>
Pentagon<T>::Pentagon(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d, const Point<T> &e)
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
template<typename T>
requires  std::floating_point<T>
Pentagon<T>::Pentagon(T _side)
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
template<typename T>
requires  std::floating_point<T>
Pentagon<T>::Pentagon(const Pentagon<T> &other)
{
    _a = other._a;
    _b = other._b;
    _c = other._c;
    _d = other._d;
    _e = other._e;
    side = other.side;
}
template<typename T>
requires  std::floating_point<T>
Pentagon<T>::Pentagon(Pentagon<T> &&other) noexcept
{
    _a = std::move(other._a);
    _b = std::move(other._b);
    _c = std::move(other._c);
    _d = std::move(other._d);
    _e = std::move(other._e);
    side = other.side;
}
template<typename T>
requires  std::floating_point<T>
Pentagon<T> &Pentagon<T>::operator=(Pentagon<T> &&other) noexcept
{
    _a = std::move(other._a);
    _b = std::move(other._b);
    _c = std::move(other._c);
    _d = std::move(other._d);
    _e = std::move(other._e);
    side = other.side;

    return *this;
}
template<typename T>
requires  std::floating_point<T>
Pentagon<T> &Pentagon<T>::operator=(const Pentagon<T> &other)
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
template<typename T>
requires  std::floating_point<T>
Point<T> Pentagon<T>::geometric_center() const
{
    return Point((_a.get_x() + _b.get_x() + _c.get_x() + _d.get_x() + _e.get_x()) / 5, (_a.get_y() + _b.get_y() + _c.get_y() + _d.get_y() + _e.get_y()) / 5);
}
template<typename T>
requires  std::floating_point<T>
double Pentagon<T>::area() const
{

    return (std::sqrt(5 * (5 + 2 * (std::sqrt(5)))) * side * side) / 4;
}
template<typename T>
requires  std::floating_point<T>
Pentagon<T>::operator double() const
{
    return (std::sqrt(5 * (5 + 2 * (std::sqrt(5)))) * side * side) / 4;
}
template<typename T>
requires  std::floating_point<T>
std::istream &operator>>(std::istream &in, Pentagon<T> &x)
{

    in >> x._a >> x._b >> x._c >> x._d >> x._e;
    Pentagon<T> temp(x._a, x._b, x._c, x._d, x._e);
    x = temp;
    return in;
}
template<typename T>
requires  std::floating_point<T>
std::ostream &operator<<(std::ostream &out, const Pentagon<T> &x)
{
    out << x._a << " " << x._b << " " << x._c << " " << x._d << " " << x._e;
    return out;
}
template<typename T>
requires  std::floating_point<T>
bool Pentagon<T>::operator==(const Pentagon<T> &other) const
{
    return _a == other._a && _b == other._b && _c == other._c && _d == other._d && _e == other._e;
}
template<typename T>
requires  std::floating_point<T>
void  Pentagon<T>::print() const{
std::cout<<*this;
 }
 template<typename T>
 requires  std::floating_point<T>
void   Pentagon<T>::read(){
std::cin>>*this;
 }

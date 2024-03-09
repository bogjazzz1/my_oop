#include "../../include/Figurearray.hpp"
size_t FigureArray::size() const
{
    return _array.size();
}
void FigureArray::print_geometric_center() const
{
    std::cout << "Geometric centers" << std::endl;
    for (size_t i = 0; i < _array.size(); ++i) {
        std::cout << _array[i]->geometric_center() << std::endl;
    }
}
FigureArray::operator double() const
{
    double temp_a = 0;
    for (size_t i = 0; i < _array.size(); ++i) {
        temp_a += _array[i]->area();
    }
    return temp_a;
}
double FigureArray::sum_area() const
{
    double temp_a = 0;
    for (size_t i = 0; i < _array.size(); ++i) {
        temp_a += _array[i]->area();
    }
    return temp_a;
}
void FigureArray::erase(size_t index)
{
    _array.erase(index);
}
std::ostream &operator<<(std::ostream &out, const FigureArray &x)
{
    for (size_t i = 0; i < x._array.size(); ++i) {
        out << static_cast<double>(*x._array[i]) << std::endl;
    }
    return out;
}
std::istream &operator>>(std::istream &in, FigureArray &x)
{
    size_t n;
    char ii = '1';
    in >> n;
    for (size_t i = 0; i < n; ++i) {
        in >> ii;
        if (ii == 'r') {
            Romb *a1 = new Romb();
            in >> (*a1);
            x._array.push_back(a1);
        }
        else if (ii == 'p') {
            Pentagon *a1 = new Pentagon();
            in >> (*a1);
            x._array.push_back(a1);
        }
        else if (ii == 'h') {
            Hexagon *a1 = new Hexagon();
            in >> (*a1);
            x._array.push_back(a1);
        }
        else {
            throw std::logic_error("required type of figure ");
        }
    }
    return in;
}

#ifndef FIGUREARRAY_HPP_INCLUDED
#define FIGUREARRAY_HPP_INCLUDED
#include "Hexagon.hpp"
#include "Romb.hpp"
#include "Vector.hpp"
#include "pentagon.hpp"
class FigureArray
{
    Vector<Figure *> _array;

public:
    FigureArray() = default;
    size_t size() const;
    void print_geometric_center() const;
    double sum_area() const;
    operator double() const;
    void erase(size_t index);
    friend std::istream &operator>>(std::istream &in, FigureArray &x);
    friend std::ostream &operator<<(std::ostream &out, const FigureArray &x);
    ~FigureArray() = default;
};

#endif// FIGUREARRAY_HPP_INCLUDED

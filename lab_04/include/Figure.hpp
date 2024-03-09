#ifndef FIGURE_HPP_INCLUDED
#define FIGURE_HPP_INCLUDED
#include "Point.hpp"
#include <float.h>

const double pi = M_PI;

template<typename T>
class Figure
{
protected:
    Figure() = default;

public:
    virtual ~Figure() = default;
    virtual Point<T> geometric_center() const = 0;
    virtual double area() const = 0;
    virtual operator double() const = 0;
    virtual void print() const = 0;
    virtual void read() = 0;
};


#endif// FIGURE_HPP_INCLUDED

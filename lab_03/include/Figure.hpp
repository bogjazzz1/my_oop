#ifndef FIGURE_HPP_INCLUDED
#define FIGURE_HPP_INCLUDED
#include "Point.hpp"

class Figure
{
protected:
    Figure() = default;

public:
    virtual ~Figure() = default;

    virtual Point geometric_center() const = 0;
    virtual double area() const = 0;

    virtual operator double() const = 0;
};


#endif// FIGURE_HPP_INCLUDED

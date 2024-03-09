#ifndef PENTAGON_HPP_INCLUDED
#define PENTAGON_HPP_INCLUDED

#include "Figure.hpp"
class Pentagon final: public Figure
{
    Point _a;
    Point _b;
    Point _c;
    Point _d;
    Point _e;
    double side;

public:
    Pentagon() = default;
    Pentagon(const Point &a, const Point &b, const Point &c, const Point &d, const Point &e);
    Pentagon(double _side);
    Pentagon(const Pentagon &other);
    Pentagon(Pentagon &&other) noexcept;
    Pentagon &operator=(const Pentagon &other);
    Pentagon &operator=(Pentagon &&other) noexcept;
    virtual Point geometric_center() const override;
    virtual double area() const override;
    virtual operator double() const override;
    bool operator==(const Pentagon &other) const;
    friend std::istream &operator>>(std::istream &in, Pentagon &x);
    friend std::ostream &operator<<(std::ostream &out, const Pentagon &x);
    ~Pentagon() = default;

private:
    bool check_Pentagon(const Point &a, const Point &b, const Point &c, const Point &d, const Point &e) const;
};


#endif// PENTAGON_HPP_INCLUDED

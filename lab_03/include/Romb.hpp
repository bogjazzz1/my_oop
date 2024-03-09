#ifndef ROMB_HPP_INCLUDED
#define ROMB_HPP_INCLUDED
#include "Figure.hpp"
class Romb final: public Figure
{
private:
    Point _a;
    Point _b;
    Point _c;
    Point _d;
    double side;

public:
    Romb() = default;
    Romb(const Point &a, const Point &b, const Point &c, const Point &d);
    Romb(double _side);
    Romb(const Romb &other);
    Romb(Romb &&other) noexcept;
    Romb &operator=(const Romb &other);
    Romb &operator=(Romb &&other) noexcept;
    virtual Point geometric_center() const override;
    virtual double area() const override;
    virtual operator double() const override;
    bool operator==(const Romb &other) const;
    friend std::istream &operator>>(std::istream &in, Romb &x);
    friend std::ostream &operator<<(std::ostream &out, const Romb &x);
    ~Romb() = default;

private:
    bool check_Romb(const Point &a, const Point &b, const Point &c, const Point &d) const;
};


#endif// ROMB_HPP_INCLUDED

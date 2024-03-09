#ifndef HEXAGON_HPP_INCLUDED
#define HEXAGON_HPP_INCLUDED
#include "Figure.hpp"
class Hexagon final: public Figure
{
private:
    Point _a;
    Point _b;
    Point _c;
    Point _d;
    Point _e;
    Point _g;
    double side;

public:
    Hexagon() = default;
    Hexagon(const Point &a, const Point &b, const Point &c, const Point &d, const Point &e, const Point &g);
    Hexagon(double _side);
    Hexagon(const Hexagon &other);
    Hexagon(Hexagon &&other) noexcept;
    Hexagon &operator=(const Hexagon &other);
    Hexagon &operator=(Hexagon &&other) noexcept;
    virtual Point geometric_center() const override;
    virtual double area() const override;
    virtual operator double() const override;
    bool operator==(const Hexagon &other) const;
    friend std::istream &operator>>(std::istream &in, Hexagon &x);
    friend std::ostream &operator<<(std::ostream &out, const Hexagon &x);
    ~Hexagon() = default;

private:
    bool check_Hexagon(const Point &a, const Point &b, const Point &c, const Point &d, const Point &e, const Point &g) const;
};


#endif// HEXAGON_HPP_INCLUDED

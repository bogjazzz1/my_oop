#ifndef HEXAGON_HPP_INCLUDED
#define HEXAGON_HPP_INCLUDED
#include "Figure.hpp"

template<typename T>
    requires  std::floating_point<T>
class Hexagon final: public Figure<T>
{
private:
    Point<T> _a;
    Point<T> _b;
    Point<T> _c;
    Point<T> _d;
    Point<T> _e;
    Point<T> _g;
    T side;

public:
    Hexagon() = default;
    Hexagon(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d, const Point<T> &e, const Point<T> &g);
    Hexagon(T _side);
    Hexagon(const Hexagon &other);
    Hexagon(Hexagon &&other) noexcept;
    Hexagon &operator=(const Hexagon &other);
    Hexagon &operator=(Hexagon &&other) noexcept;
    virtual Point<T> geometric_center() const override;
    virtual double area() const override;
    virtual operator double() const override;
    bool operator==(const Hexagon &other) const;
    template<typename j>
    requires  std::floating_point<j>
    friend std::istream &operator>>(std::istream &in, Hexagon<j> &x);
    template<typename j>
    requires  std::floating_point<j>
    friend std::ostream &operator<<(std::ostream &out, const Hexagon<j> &x);
    ~Hexagon() = default;
    virtual void print() const override;
    virtual void read() override;

private:
    bool check_Hexagon(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d, const Point<T> &e, const Point<T> &g) const;
};

#include "../src/Hexagon.cpp"
#endif// HEXAGON_HPP_INCLUDED

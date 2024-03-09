#ifndef ROMB_HPP_INCLUDED
#define ROMB_HPP_INCLUDED
#include "Figure.hpp"

template<typename T>
class Romb final: public Figure<T>
{
private:
    Point<T> _a;
    Point<T> _b;
    Point<T> _c;
    Point<T> _d;
    double side;

public:
    Romb() = default;
    Romb(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d);
    Romb(T _side);
    Romb(const Romb &other);
    Romb(Romb &&other) noexcept;
    Romb &operator=(const Romb &other);
    Romb &operator=(Romb &&other) noexcept;
    virtual Point<T> geometric_center() const override;
    virtual double area() const override;
    virtual operator double() const override;
    bool operator==(const Romb &other) const;
    template<typename j>
    friend std::istream &operator>>(std::istream &in, Romb<j> &x);
    template<typename j>
    friend std::ostream &operator<<(std::ostream &out, const Romb<j> &x);
    ~Romb() = default;
    virtual void print() const override;
    virtual void read() override;

private:
    bool check_Romb(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d) const;
};
#include "../src/Romb.cpp"

#endif// ROMB_HPP_INCLUDED

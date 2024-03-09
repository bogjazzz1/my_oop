#ifndef PENTAGON_HPP_INCLUDED
#define PENTAGON_HPP_INCLUDED
#include "Figure.hpp"

template<typename T>
    requires  std::floating_point<T>
class Pentagon final: public Figure<T>
{
    Point<T> _a;
    Point<T> _b;
    Point<T> _c;
    Point<T> _d;
    Point<T> _e;
    T side;

public:
    Pentagon() = default;
    Pentagon(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d, const Point<T> &e);
    Pentagon(T _side);
    Pentagon(const Pentagon &other);
    Pentagon(Pentagon &&other) noexcept;
    Pentagon &operator=(const Pentagon &other);
    Pentagon &operator=(Pentagon &&other) noexcept;
    virtual Point<T> geometric_center() const override;
    virtual double area() const override;
    virtual operator double() const override;
    bool operator==(const Pentagon &other) const;
    template<typename j>
    requires  std::floating_point<j>
    friend std::istream &operator>>(std::istream &in, Pentagon<j> &x);
    template<typename j>
    requires  std::floating_point<j>
    friend std::ostream &operator<<(std::ostream &out, const Pentagon<j> &x);
    ~Pentagon() = default;
    virtual void print() const override;
    virtual void read() override;

private:
    bool check_Pentagon(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d, const Point<T> &e) const;
};

#include "../src/Pentagon.cpp"
#endif// PENTAGON_HPP_INCLUDED

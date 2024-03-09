#ifndef POINT_HPP_INCLUDED
#define POINT_HPP_INCLUDED
#include <cmath>
#include <concepts>
#include <iostream>

template<typename T>
    requires std::integral<T> || std::floating_point<T>
class Point
{

    T _x = 0.0;
    T _y = 0.0;

public:
    Point() = default;
    Point(T x, T y);
    Point(const Point &other);
    Point(Point &&other) noexcept;
    Point &operator=(const Point &other);
    Point &operator=(Point &&other);
    T get_x() const;
    T get_y() const;
    void set_x(T x);
    void set_y(T x);
    bool operator==(const Point &other) const;
    ~Point() = default;
    template<typename j>
        requires std::integral<j> || std::floating_point<j>
    friend std::ostream &operator<<(std::ostream &out, const Point<j> &x);
    template<typename j>
        requires std::integral<j> || std::floating_point<j>
    friend std::istream &operator>>(std::istream &in, Point<j> &x);
};
#include "../src/Point.cpp"
#endif// POINT_HPP_INCLUDED

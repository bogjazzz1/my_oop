#ifndef POINT_HPP_INCLUDED
#define POINT_HPP_INCLUDED
#include <cmath>
#include <iostream>
class Point
{

    double _x = 0.0;
    double _y = 0.0;

public:
    Point() = default;
    Point(double x, double y);
    Point(const Point &other);
    Point(Point &&other) noexcept;
    Point &operator=(const Point &other);
    Point &operator=(Point &&other);
    double get_x() const;
    double get_y() const;
    void set_x(double x);
    void set_y(double x);
    bool operator==(const Point &other) const;
    ~Point() = default;
    friend std::ostream &operator<<(std::ostream &out, const Point &x);
    friend std::istream &operator>>(std::istream &in, Point &x);
};

#endif// POINT_HPP_INCLUDED

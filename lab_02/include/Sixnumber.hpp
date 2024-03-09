#ifndef SIXNUMBER_HPP_INCLUDED
#define SIXNUMBER_HPP_INCLUDED
#include <string>
#include <iostream>
#include <cstdint>
class Six{
    size_t _size;
    unsigned char *_array;
public:
    Six();
    Six(const size_t &n,unsigned char t=0);
    Six(const std::initializer_list< unsigned char> &t);
    Six(const std::string &t);
    Six(const Six& other);
    Six(Six&& other) noexcept;
    bool operator==(const Six &other) const ;
    bool operator!=(const Six &other) const ;
    bool operator >(const Six &other) const;
    bool operator <(const Six &other) const;
    Six operator +(const Six&other) const;
    Six operator -(const Six&other) const;
    Six& operator +=(const Six &other);
    Six& operator -=(const Six &other);
    friend std::ostream &operator<<(std::ostream &out, const Six &x);
     ~Six() noexcept ;
private:
    void shrink();
};

#endif // SIXNUMBER_HPP_INCLUDED

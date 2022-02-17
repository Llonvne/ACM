#include "Vector.h"
#include <cmath>
#include <iostream>

VECTOR::Vector VECTOR::operator*(double n, const VECTOR::Vector & a)
{
    return a * n;
}

std::ostream & VECTOR::operator<<(std::ostream & os, const VECTOR::Vector & a)
{
    os << "x: " << a.x << " y: " << a.y << std::endl;
    return os;
}

VECTOR::Vector::Vector(double v1, double v2, VECTOR::Vector::Vector_Mode mode)
{
    reset(v1, v2, mode);
}

void VECTOR::Vector::reset(double v1, double v2, VECTOR::Vector::Vector_Mode mode)
{
    if (mode == Vector_Mode::RECT) {
        x = v1;
        y = v2;
    }
    else if (mode == Vector_Mode::POL) {
        constexpr double RAD_TO_DEG = 57.29577951;
        v2 /= RAD_TO_DEG;
        x = v1 * cos(v2);
        y = v1 * sin(v2);
    }
    else {
        std::cout << "Invalid vector mode,mode is setting to RECT,x,y is initalized to 0,0" << std::endl;
        x = y = 0;
    }
}

VECTOR::Vector::~Vector()
= default;

double VECTOR::Vector::get_x() const
{
    return x;
}

double VECTOR::Vector::get_y() const
{
    return y;
}

double VECTOR::Vector::get_ang() const
{
    if (x == 0 && y == 0) {
        return 0.0;
    }
    return atan2(y, x);
}

double VECTOR::Vector::getmag() const
{
    return sqrt(pow(x, 2) + pow(y, 2));
}

VECTOR::Vector VECTOR::Vector::operator+(const VECTOR::Vector & a) const
{
    return {x + a.x, y + a.y};
}

VECTOR::Vector VECTOR::Vector::operator-(const VECTOR::Vector & a) const
{
    return (*this + (-a));
}

VECTOR::Vector VECTOR::Vector::operator-() const
{
    return {-x, -y};
}

VECTOR::Vector VECTOR::Vector::operator*(double n) const
{
    return Vector{x * n, y * n};
}

#include <iostream>
#include <sstream>

MyComplex::MyComplex(double real, double imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}

MyComplex MyComplex::operator-(const MyComplex & b) const
{
    return {real - b.real, imaginary - b.imaginary};
}

MyComplex MyComplex::operator~() const
{
    return {real, -imaginary};
}

MyComplex operator+(const MyComplex & a, const MyComplex & b)
{
    return {a.real + b.real, a.imaginary + b.imaginary};
}

MyComplex operator*(const MyComplex & a, const MyComplex & b)
{
    return {
        a.real * b.real - a.imaginary * b.imaginary,
        a.real * b.imaginary + b.real * a.imaginary
    };
}

MyComplex operator*(double n, const MyComplex & b)
{
    return {b.real * n,b.imaginary * n};
}

std::ostream & operator<<(std::ostream & os, const MyComplex & c)
{
    os << c.real;
    if (c.imaginary > 0) {
        os << "+";
    }
    os << c.imaginary << "i" << " ";
    return os;
}

std::istream & operator>>(std::istream & is, MyComplex & c)
{
    std::string real,imaginary;
    is >> real >> imaginary;
    std::stringstream r(real);
    r >> c.real;
    std::stringstream i(imaginary);
    i >> c.imaginary;
    return is;
}

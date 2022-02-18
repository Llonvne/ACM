#ifndef MYCOMPLEX_H
#define MYCOMPLEX_H
#include <ostream>

class MyComplex
{
    double real,imaginary;
public:
    MyComplex(double real = 0.0,double imaginary = 0.0);

    friend MyComplex operator+(const MyComplex & a,const MyComplex & b) ;
    MyComplex operator-(const MyComplex & b) const;
    friend MyComplex operator*(const MyComplex & a,const MyComplex & b);
    friend MyComplex operator*(double n,const MyComplex & b);
    MyComplex operator~() const;

    friend std::ostream & operator<<(std::ostream &,const MyComplex &);
    friend std::istream & operator>>(std::istream & is, MyComplex & c);
};


#endif //MYCOMPLEX_H

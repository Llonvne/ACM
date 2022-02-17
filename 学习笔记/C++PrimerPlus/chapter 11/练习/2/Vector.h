#ifndef VECTOR_H
#define VECTOR_H
#include <ostream>
namespace VECTOR{
    typedef double Number_t;
    class Vector
    {
        Number_t x{};
        Number_t y{};
    public:
        enum class Vector_Mode {POL,RECT};
        Vector(double v1,double v2,Vector_Mode mode = Vector_Mode::RECT);
        void reset(double v1, double v2, Vector_Mode mode = Vector_Mode::RECT);
        ~Vector();
        double get_x() const;
        double get_y() const;
        double get_ang() const;
        double getmag() const;

        Vector operator+(const Vector &) const;
        Vector operator-(const Vector &) const;
        Vector operator-() const;
        Vector operator*(double ) const;

        friend Vector operator*(double n,const Vector & a);
        friend std::ostream & operator<<(std::ostream &,const Vector &);
    };
}

#endif //VECTOR_H

//
// Created by 华邵钶 on 2022/2/28.
//

#ifndef STRING_H
#define STRING_H
#include "../Vector/Vector.h"
#include <ostream>
#include <istream>

class String : public Vector<char>
{
public:
    bool operator<(const String & s);
    String(const char * = "");
    const char * c_str();
    friend bool operator<(String const & a,String const & b);
    friend bool operator>(String const & a,String const & b);
    friend bool operator==(String const & a,String const & b);
    friend bool operator!=(String const & a,String const & b);
    operator const Vector<char>();
};

std::ostream & operator<<(std::ostream & os, const String & s);
std::istream & operator>>(std::istream & input, String & s);

#endif //STRING_H

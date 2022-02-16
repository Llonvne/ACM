//
// Created by 华邵钶 on 2022/2/15.
//

#include "Person.h"
#include <iostream>

Person::Person(const std::string & ln, const char * fn)
{
    lname = ln;
    std::strcpy(fname,fn);
}

void Person::show() const
{
    std::cout << fname << " " << lname << std::endl;
}

void Person::FormalShow() const
{
    std::cout << lname << " " << fname << std::endl;
}

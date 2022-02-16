//
// Created by 华邵钶 on 2022/2/16.
//

#include "Plorg.h"
#include <iostream>

Plorg::Plorg(const char * fn)
{
    strcpy(fullname, fn);
}

void Plorg::report() const
{
    std::cout << "Fullname: " << fullname << " " << "CI: " << CI << std::endl;
}

int Plorg::getCI() const
{
    return CI;
}

const Plorg & Plorg::setCI(int ci)
{
    this->CI = ci;
    return *this;
}

Plorg::Plorg()
{
    strcpy(fullname, "Plorg");
}

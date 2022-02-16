//
// Created by 华邵钶 on 2022/2/15.
//

#include "golf.h"
#include <iostream>

golf::golf(const std::string & fullname, int handicap)
{
    set(fullname,handicap);
}

int golf::set()
{
    std::cout << "Your fullname: ";
    std::getline(std::cin, fullname);
    while (!std::cin){
        while (std::cin.get() != '\n'){};
        std::getline(std::cin, fullname);
    }

    std::cout << "Your Handicap: ";
    std::cin >> handicap;
    while (!std::cin){
        while (std::cin.get() != '\n'){};
        std::cin >> handicap;
    }

    std::cin.get();
    return fullname.empty();
}

void golf::show() const
{
    std::cout << "Your fullname: " << fullname << std::endl;
    std::cout << "Your handicap: " << handicap << std::endl;
}

golf::golf()
{
    fullname = "undefine";
    handicap = 0;
}

int golf::set(const std::string & fullname, int handicap)
{
    this->fullname = fullname;
    this->handicap = handicap;
}

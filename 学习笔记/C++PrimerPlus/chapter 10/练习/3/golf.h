//
// Created by 华邵钶 on 2022/2/15.
//

#ifndef GOLF_H
#define GOLF_H

#include <string>

class golf
{
    std::string fullname;
    int handicap;

public:
    golf();
    golf(const std::string & fullname,int handicap);
    int set(const std::string & fullname,int handicap);
    int set();
    void show() const;
};


#endif //GOLF_H

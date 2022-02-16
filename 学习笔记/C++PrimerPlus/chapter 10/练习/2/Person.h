//
// Created by 华邵钶 on 2022/2/15.
//

#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person
{
private:
    static const int LIMIT = 25;
    std::string lname;
    char fname[LIMIT]{};
public:
    Person(){lname = "",fname[0] = '\0';};
    Person(const std::string & ln,const char * fn = "Heyyou");
    void show() const;
    void FormalShow() const;
};


#endif //PERSON_H

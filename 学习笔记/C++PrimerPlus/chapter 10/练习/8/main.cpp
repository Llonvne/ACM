#include "List.h"
#include <iostream>
void out(int & a){
    std::cout << a;
}
int main()
{
    List<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
}

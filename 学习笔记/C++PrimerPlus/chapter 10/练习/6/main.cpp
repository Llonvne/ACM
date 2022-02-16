#include <iostream>
#include "Move.h"

int main()
{
    Move a(1,2);
    a.showMove();
    Move b(1,3);
    a.add(b).showMove();
    a.reset(1,100);
    a.showMove();
}

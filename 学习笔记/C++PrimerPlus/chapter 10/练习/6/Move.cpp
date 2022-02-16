//
// Created by 华邵钶 on 2022/2/16.
//

#include "Move.h"
#include <iostream>

Move::Move(double a, double b)
{
    reset(a,b);
}

void Move::showMove() const
{
    using std::cout;
    using std::endl;
    cout << "x: " << x << " ";
    cout << "y: " << y << endl;
}

Move Move::add(const Move & move) const
{
    return {x + move.x, y + move.y};
}

void Move::reset(double a, double b)
{
    x = a;
    y = b;
}

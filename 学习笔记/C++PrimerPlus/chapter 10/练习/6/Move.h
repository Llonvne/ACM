//
// Created by 华邵钶 on 2022/2/16.
//

#ifndef MOVE_H
#define MOVE_H


class Move
{
private:
    double x;
    double y;
public:
    Move(double a,double b);
    void showMove() const;
    Move add(const Move & move) const;
    void reset(double a = 0,double y = 0);
};


#endif //MOVE_H

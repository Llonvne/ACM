//
// Created by 华邵钶 on 2022/5/23.
//

#ifndef MAXPRIORITYQUEUE_H
#define MAXPRIORITYQUEUE_H
#include <vector>
using std::vector;

class MaxPriorityQueue
{
    std::unique_ptr<vector<int>> elem;

public:
    MaxPriorityQueue(int * elem, int n);
    MaxPriorityQueue(vector<int> a);

    int top();
    int pop();
    int size();
    int push(int x);
};


#endif //MAXPRIORITYQUEUE_H

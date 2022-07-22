#include <iostream>
#include "heap/MaxPriorityQueue.h"

int main()
{
    int a[] {4,1,3,2,16,9,10,14,8,7};
    MaxPriorityQueue maxPriorityQueue(a,10);
    maxPriorityQueue.push(100000);
    while (maxPriorityQueue.size() != 0) {
        std::cout << maxPriorityQueue.top() << " ";
        maxPriorityQueue.pop();
    }
}

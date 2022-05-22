#include <iostream>
#include "heap/BuildMaxHeap.h"

int main()
{
    int a[] {4,1,3,2,16,9,10,14,8,7};
    build_max_heap(a,10);
    for (int i : a){
        std::cout << i << " ";
    }
    return 0;
}

//
// Created by 华邵钶 on 2022/5/22.
//

#include "HeapSort.h"
#include "BuildMaxHeap.h"
#include "MaxHeapIteration.h"
#include <utility>
using std::swap;

void heap_sort(int * A, int n)
{
    build_max_heap(A,n);
    for (int i = n - 1; i >= 1; --i) {
        swap(A[0],A[i]);
        --n;
        max_heapify_iteration(A,n,0);
    }

}

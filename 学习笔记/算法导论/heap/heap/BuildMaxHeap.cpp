//
// Created by 华邵钶 on 2022/5/22.
//

#include "BuildMaxHeap.h"
#include "MaxHeapIteration.h"

void build_max_heap(int A[], int n)
{
    for (int i = n / 2 - 1; i >= 0; --i) {
        max_heapify_iteration(A, n, i);
    }
}

//
// Created by 华邵钶 on 2022/5/22.
//

#include "MaxHeapIteration.h"
#include "HeapOperations.h"
#include <utility>
using namespace std;

void max_heapify_iteration(int * A, int n, int i)
{
    int maximum = i;
    while (true) {
        int l = left(i);
        int r = right(i);

        if (l < n && A[l] > A[maximum]) {
            maximum = l;
        }
        if (r < n && A[r] > A[maximum]) {
            maximum = r;
        }
        if (i != maximum) {
            swap(A[i], A[maximum]);
            i = maximum;
        }
        else {
            break;
        }
    }
}

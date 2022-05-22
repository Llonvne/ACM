//
// Created by 华邵钶 on 2022/5/22.
//

#include "MaxHeapify.h"
#include "HeapOperation.h"
#include <utility>

void max_heapify(int A[],int n,int i) {
    int l = left(i);
    int r = right(i);

    int maximum = i;
    if (l < n && A[l] > A[i]){
        maximum = l;
    }
    if (r < n && A[r] > A[maximum]){
        maximum = r;
    }

    if (maximum != i){
        swap(A[maximum],A[i]);
        max_heapify(A,n,maximum);
    }
}
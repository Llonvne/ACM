//
// Created by 华邵钶 on 2022/5/22.
//

#include "MinHeapify.h"
#include "HeapOperation.h"
#include <utility>

void min_heapify(int A[],int n,int i){
    int l = left(i);
    int r = right(i);

    int minimum = i;
    if (l < n && A[l] < A[minimum]){
        minimum = l;
    }
    if (r < n && A[r] < A[minimum]){
        minimum = r;
    }
    if (minimum != i){
        swap(A[minimum],A[i]);
        min_heapify(A,n,minimum);
    }
}

//
// Created by 华邵钶 on 2022/5/22.
//

#include "MinHeapifyIteration.h"
#include "HeapOperation.h"
#include <utility>

void min_heapify_iteration(int A[],int n,int i){
    int minimum = i;
    while (true){
        int l = left(i);
        int r = right(i);

        if (l < n && A[l] < A[minimum]){
            minimum = l;
        }
        if (r < n && A[r] < A[minimum]){
            minimum = r;
        }
        if (i != minimum){
            swap(A[i],A[minimum]);
            i = minimum;
        }
        else {
            return;
        }
    }
}
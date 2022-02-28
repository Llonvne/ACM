//
// Created by 华邵钶 on 2022/2/27.
//

#ifndef VECTOR_MERGESORT_H
#define VECTOR_MERGESORT_H
#include "../../Vector_Definitions.h"

template<typename T> void merge(T * A, Rank lo, Rank mi, Rank hi)
{
    T * a = A + lo;
    int lb = mi - lo;
    T * b = new T[lb];
    for (Rank i = 0; i < lb;++i){
        b[i] = a[i];
    };
    int lc = hi - mi;
    T * c = A + mi;
    for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);) {
        if ((j < lb) && (lc <= k || (b[j] <= c[k]))) {
            a[i++] = b[j++];
        }
        if ((k < lc) && (lb <= j || (c[k] < b[j]))) {
            a[i++] = c[k++];
        }
    }
    delete[] b;
}

template<typename T>
void mergeSort(T * A, Rank lo, Rank hi)
{
    if (hi - lo < 2) { // 一个元素自然有序
        return;
    }
    int mi = (lo + hi) >> 1; // 以中点为界限
    mergeSort(A, lo, mi); // [lo,mi)
    mergeSort(A, mi, hi); // [mi,hi)
    merge(A, lo, mi, hi); // 合并 [lo ... mi ... hi)
}

#endif //VECTOR_MERGESORT_H

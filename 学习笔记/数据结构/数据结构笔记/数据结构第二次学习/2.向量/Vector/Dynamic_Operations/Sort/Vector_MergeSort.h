//
// Created by 华邵钶 on 2022/2/27.
//

#ifndef VECTOR_MERGESORT_H
#define VECTOR_MERGESORT_H
#include "../../Vector_Definitions.h"

template<typename T> void merge(T * A, Rank lo, Rank mi, Rank hi)
{
    Vector<int> result;
    T * l = A + lo;
    int lsize = mi - lo;
    T * r = A + mi;
    int rsize = hi - mi;
    while (lsize > 0 || rsize > 0) {
        if (lsize > 0 && rsize == 0) {
            result.push_back(*l);
            l++;
            lsize--;
        }
        else if (rsize > 0 && lsize == 0) {
            result.push_back(*r);
            r++;
            rsize--;
        }
        else if (*l > *r) {
            result.push_back(*r);
            r++;
            rsize--;
        }
        else {
            result.push_back(*l);
            l++;
            lsize--;
        }
    }
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

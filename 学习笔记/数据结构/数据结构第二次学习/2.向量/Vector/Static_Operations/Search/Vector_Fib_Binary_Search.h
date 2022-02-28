//
// Created by 华邵钶 on 2022/2/27.
//

#ifndef VECTOR_FIB_BINARY_SEARCH_H
#define VECTOR_FIB_BINARY_SEARCH_H
#include "../../../../1.绪论/src/fibnacci/fibnacciClassSmall.cpp"
using Fib = Fibnacci;
#include "../../Vector_Definitions.h"

template<typename T>
Rank fibSearch(T * A, T const & e, Rank lo, Rank hi)
{
    Fib fib(hi - lo);
    while (lo < hi) {
        while (hi - lo < fib.get()) {
            fib.prev();
        }
        Rank mi = lo + fib.get() - 1;
        if (e < A[mi]) { // 目标小于中点
            hi = mi; // 往左侧
        }
        else { // 目标大于中点
            lo = mi + 1;
        }
    }
    return lo-1;
}

template<typename T>
Rank binSearch(T * A, T const & e, Rank lo, Rank hi)
{
    while (lo < hi) {
        int mi = (lo + hi) >> 1;
        if (e < A[mi]) {
            hi = mi;
        }
        else {
            lo = mi + 1;
        }
    }
    return lo - 1;
}

template<typename T>
Rank binSearch_2(T * A, T const & e, Rank lo, Rank hi)
{
    while (1 < hi - lo){
        Rank mi = (lo + hi) >> 1;
        if (e < A[mi]){
            hi = mi;
        }
        else {
            lo = mi;
        }
    }
    return e == A[lo] ? lo : -1;
}

#endif //VECTOR_FIB_BINARY_SEARCH_H

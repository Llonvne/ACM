//
// Created by 华邵钶 on 2022/2/27.
//

#ifndef VECTOR_BUBBLESORT_H
#define VECTOR_BUBBLESORT_H
// 第一章的版本 for int O(n^2)
//#include "../../../../1.绪论/src/bubbleSort/bubbleSort(纯定理实现).h"
#include "../../Vector_Definitions.h"
template<typename T> static Rank bubble(T * A, Rank lo, Rank hi);

template<typename T>
void bubbleSort(T * A, Rank lo, Rank hi)
{ // 找出无序中有序的进行优化
    // 每一次扫描交换的过程中是否存在逆序元素，
    // 存在等于有交换，否则就是有序,如果做过记录最后一次交换的位置
    while (lo < (hi = bubble(A,lo,hi)));
}

template<typename T>
static Rank bubble(T * A, Rank lo, Rank hi)
{
    int last = lo;
    while (++lo < hi) {
        if (A[lo - 1] > A[lo]) {
            last = lo;
            std::swap(A[lo - 1], A[lo]);
        }
    }
    return last;
}

#endif //VECTOR_BUBBLESORT_H

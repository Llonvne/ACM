//
// Created by 华邵钶 on 2022/2/27.
//

#ifndef VECTOR_INTERPOLATION_SEARCH_H
#define VECTOR_INTERPOLATION_SEARCH_H
// 插值查找 均匀独立的随机的分布 O(logN)
#include "../Vector.h"
template <typename T>
Rank InterpolationSearch(T * A, T const & e, Rank lo, Rank hi){
    while (lo < hi){
        // 通过猜测轴点mi，可以极大的提升收敛速度
        Rank mi = lo + (hi - lo) * (e - A[lo]) / (A[hi] - A[lo]);
        if (e < A[mi]) { // 目标小于中点
            hi = mi; // 往左侧
        }
        else { // 目标大于中点
            lo = mi + 1;
        }
    }
    return lo - 1;
}
#endif //VECTOR_INTERPOLATION_SEARCH_H

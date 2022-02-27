//
// Created by 华邵钶 on 2022/2/27.
//

#ifndef VECTOR_STATIC_OPERATION_H
#define VECTOR_STATIC_OPERATION_H
#include "Vector.h"

template<typename T>
Rank Vector<T>::search(const T & e, Rank lo, Rank hi) const
{
    return fibSearch(_elem, e, lo, hi);
}

template<typename T>
Rank Vector<T>::search(const T & e) const
{
    return search(e, 0, _size);
}

template<typename T>
int Vector<T>::disordered() const
{
    int n = 0; // 逆序对数量统计
    for (int i = 1; i < _size; ++i) {
        if (_elem[i - 1] > _elem[i]) // 如果前面一个后面一个 就 ++
        {
            ++n;
        }
    }
    return n;
}

template<typename T>
bool Vector<T>::sorted() const
{
    for (int i = 1; i < _size; ++i) {
        if (_elem[i - 1] > _elem[i]) // 一旦前面一个大于后面一个
        {
            return false;
        }
    }
    return true;
}

template<typename T>
Rank Vector<T>::find(const T & e, Rank lo, Rank hi) const
{
    while (lo < hi) {
        if (e == _elem[--hi]) { // 命中直接返回
            return hi;
        }
    }
    return -1;
}

template<typename T>
Rank Vector<T>::find(const T & e) const
{
    return find(e, 0, _size);
}

template<typename T>
T & Vector<T>::operator[](Rank r) const
{
    return _elem[r];
}

// Fibnacci Search
// 调用第一章的Fibnacci数列算法
#include "../../1.绪论/src/fibnacci/fibnacciClassSmall.cpp"
using Fib = Fibnacci;
template<typename T>
static Rank fibSearch(T * A, T const & e, Rank lo, Rank hi)
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
        else if (A[mi] < e) { // 目标大于中点
            lo = mi + 1;
        }
        else { // 命中
            return mi;
        }
    }
    return -1;
}

#endif //VECTOR_STATIC_OPERATION_H

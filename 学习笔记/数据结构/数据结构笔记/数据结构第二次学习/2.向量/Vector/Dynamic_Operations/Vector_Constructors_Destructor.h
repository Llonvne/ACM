//
// Created by 华邵钶 on 2022/2/27.
//

#ifndef VECTOR_CONSTRUCTORS_DESTRUCTOR_H
#define VECTOR_CONSTRUCTORS_DESTRUCTOR_H
#pragma once
#include "../Vector.h"

template<typename T>
Vector<T>::Vector(int c)
{
    _capacity = c;
    _elem = new T[_capacity];
    _size = 0;
    defaultSearchMode = DEFAULT_SEARCH_MODE;
}

template<typename T>
Vector<T>::Vector(const T * A, Rank lo, Rank hi)
{
    copyFrom(A, lo, hi);
    defaultSearchMode = DEFAULT_SEARCH_MODE;
}

template<typename T>
Vector<T>::Vector(const Vector<T> & V, Rank lo, Rank hi)
{
    copyFrom(V._elem, lo, hi);
    defaultSearchMode = DEFAULT_SEARCH_MODE;
}

template<typename T>
Vector<T>::Vector(const Vector<T> & V)
{
    copyFrom(V._elem, 0, V._size);
    defaultSearchMode = DEFAULT_SEARCH_MODE;
}

template<typename T>
Vector<T>::~Vector()
{
    delete[] _elem;
}

template<typename T>
void Vector<T>::copyFrom(const T * A, Rank lo, Rank hi)
{
    _capacity = (hi - lo) * CAPACITY_MULTIPLIER_EXPAND; // 开辟两倍于区间大小的内存，为什么后面讲
    _elem = new T[_capacity];

    // 复制元素
    for (_size = 0; lo < hi; _size++, lo++) {
        _elem[_size] = A[lo];
    }
}

#endif //VECTOR_CONSTRUCTORS_DESTRUCTOR_H

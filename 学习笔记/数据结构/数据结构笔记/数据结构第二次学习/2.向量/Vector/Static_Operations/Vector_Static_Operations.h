//
// Created by 华邵钶 on 2022/2/27.
//

#ifndef VECTOR_STATIC_OPERATIONS_H
#define VECTOR_STATIC_OPERATIONS_H
#pragma once
#include "../Vector.h"
#include "../Error/SimpleError.h"
#include "./Search/Vector_Search_Interface.h"

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

template<typename T>
T & Vector<T>::at(Rank r) const
{
    // 与 STL at相同提供边界检查，但是内部还是由 [] 实现
    if (r < 0 || r >= _size){
        error_message("Rank out of range");
    }
    else {
        return this->operator[](r);
    }
}

#endif //VECTOR_STATIC_OPERATIONS_H

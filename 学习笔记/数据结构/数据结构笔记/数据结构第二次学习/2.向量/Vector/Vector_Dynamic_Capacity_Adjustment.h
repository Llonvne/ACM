//
// Created by 华邵钶 on 2022/2/27.
//

#ifndef VECTOR_DYNAMIC_CAPACITY_ADJUSTMENT_H
#define VECTOR_DYNAMIC_CAPACITY_ADJUSTMENT_H
#pragma once
#include <algorithm>
#include "Vector.h"

template<typename T>
void Vector<T>::expand()
{
    // _size < _capacity 没有满，无需拓展
    if (_size < _capacity) {
        return;
    }

    // 容量不得低于最小容量
    _capacity = std::max(_capacity, DEFAULT_CAPACITY);
    T * oldelem = _elem; // 备份原数组地址
    _capacity <<= 1; // 容量加倍
    _elem = new T[_capacity]; // 开辟加倍后容量的空间

    // 复制元素
    for (int i = 0; i < _size; ++i) {
        _elem[i] = oldelem[i]; // 将原数组的元素复制到新开辟的数组
    }

    delete[] oldelem; // 释放原数组内存
}

template<typename T>
void Vector<T>::shrink()
{
    #ifdef SHRINK
    if (_capacity < DEFAULT_CAPACITY << 1) {  // 如果容量小于最小容量的两倍，不缩小
        return;
    }
    if (_size << 4 > _capacity) { // size * 4 < capacity 才缩容量
        return;
    }

    // 备份原来的数组
    T * oldelem = _elem;
    _capacity >>= 1; // 容量缩小一半
    _elem = new T[_capacity >> 1]; // 重新开辟空间

    // 复制元素
    for (int i = 0; i < _size; ++i) {
        _elem[i] = oldelem[i];
    }

    // 释放原来的空间
    delete[] oldelem;
    #endif
}

#endif //VECTOR_DYNAMIC_CAPACITY_ADJUSTMENT_H

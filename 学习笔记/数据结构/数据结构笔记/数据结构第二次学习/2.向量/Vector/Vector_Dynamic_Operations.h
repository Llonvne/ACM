//
// Created by 华邵钶 on 2022/2/27.
//

#ifndef VECTOR_DYNAMIC_OPERATIONS_H
#define VECTOR_DYNAMIC_OPERATIONS_H
#pragma once
#include "Vector.h"
template<typename T>
Rank Vector<T>::insert(Rank r, const T & e)
{
    // insert 属于动态操作需要考虑到容量
    expand(); // 如果向量满了则拓展容量

    // 从最后面开始不断向前 直到 r 元素
    for (int i = _size; i > r; --i) {
        _elem[i] = _elem[i - 1]; // 不断前移 最后一次是 i = r + 1 => _elem[r+1] = _elem[r]
    }
    _elem[r] = e; // 插入元素
    ++_size; // 更新容量

    return r; // 返回插入的位置
}

template<typename T>
int Vector<T>::remove(Rank lo, Rank hi)
{
    if (lo == hi) { // 因为 [hi,lo) 所以相等时不包含元素 删除0个元素
        return 0;
    }

    while (hi < _size) {
        _elem[lo] = _elem[hi]; // 将区间后到第一个元素覆盖到区间到第一个元素，不断重复，直达尾部
        ++lo;
        ++hi;
    }

    _size = lo; // 更新容量

    shrink(); // 有必要,缩小容量
    return hi - lo;
}

template<typename T>
T Vector<T>::remove(Rank r)
{
    // 有必要就缩小容量
    shrink();

    T e = _elem[r]; // 备份被删除的元素
    remove(r, r + 1); // 调用区间删除函数，删除r位置的元素
    return e; // 返回被删除的元素
}

template<typename T> template<typename VST>
void Vector<T>::traverse(VST & visit)
{
    for (int i = 0; i < _size; ++i) {
        visit(_elem[i]);
    }
}

template<typename T>
int Vector<T>::uniquify()
{
    Rank i = 0, j = 0;
    while (++j < _size) { // 循环所有元素
        if (_elem[i] != _elem[j]) { // 如果雷同
            _elem[++i] = _elem[j]; // 将j移动到 i+1，同时i向后移动
        }
    }
    // 此时i是最后一个不重复元素的下标
    _size = ++i; // 规模的最后一个元素的下标+1
    shrink(); // 如果有必要就减少容量
    return j - i; // 此时 j 就是原来数组的大小 i == _size 是现在数组的大小
}

#endif //VECTOR_DYNAMIC_OPERATIONS_H

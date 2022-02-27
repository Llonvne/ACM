//
// Created by 华邵钶 on 2022/2/27.
//

#ifndef VECTOR_DEBUG_ONLY_H
#define VECTOR_DEBUG_ONLY_H
#pragma once
//--- For_Debug 函数实现 ---//
#include "../Vector.h"
#ifdef DEBUG
#include <iostream>

template<typename T>
void Vector<T>::print() const
{
    for (int i = 0; i < _size; ++i) {
        std::cout << _elem[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
int Vector<T>::deduplicate_1()
{
    int oldsize = _size;
    Rank i = 1; // 第0个一定不会重复，所以从第一个开始
    while (i < _size) {
        // 如果在前面找到了相同的元素 则
        if (find(_elem[i], 0, i) < 0) {
            i++;
        }
            // 反之
        else {
            remove(i);
        }
    }
    return oldsize - _size; // 删除的元素总数
}

template<typename T>
int Vector<T>::uniquify_v1()
{
    int oldsize = _size;
    int i = 0; // 从第0个元素开始
    while (i < _size - 1) {
        if (_elem[i] == _elem[i + 1]) // 如果与后面的元素相等
        {
            remove(i + 1);// 删除后面第元素
        }// 否则
        else {
            i++; // 移动到后面一个元素
        }
    }
    return oldsize - _size;
}

template<typename T>
Rank Vector<T>::search_v1(const T & e, Rank lo, Rank hi) const
{
    while (lo < hi) {
        // 中点
        int mi = (lo + hi) >> 1;
        if (e < _elem[mi]) { // 目标小于中点
            hi = mi; // 往左侧
        }
        else if (_elem[mi] < e) { // 目标大于中点
            lo = mi + 1;
        }
        else { // 命中
            return mi;
        }
    }
    // 查找失败
    return -1;
}

#endif
//--- For_Debug 函数实现 END ---//
#endif //VECTOR_DEBUG_ONLY_H

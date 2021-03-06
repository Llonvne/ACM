//
// Created by 华邵钶 on 2022/2/27.
//

#ifndef VECTOR_DYNAMIC_OPERATIONS_H
#define VECTOR_DYNAMIC_OPERATIONS_H
#pragma once
#include "../../Vector.h"

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
Rank Vector<T>::push_back(const T & e)
{
    insert(_size, e);
}

template<typename T>
Rank Vector<T>::insert_InOrder(const T & e)
{
    insert(search(e) + 1,e);
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
Vector<T> & Vector<T>::operatorr=(const Vector<T> & V)
{
    delete[] _elem;
    copyFrom(V,0,V._size);
    return *this;
}

template<typename T>
void Vector<T>::resize(int size)
{
    if (size >= 0){
        _size = size;
    }
    shrink();
    expand();
}

template<typename T>
void Vector<T>::pop_back()
{ // 使用惰性删除
    resize(_size -1);
}


#endif //VECTOR_DYNAMIC_OPERATIONS_H

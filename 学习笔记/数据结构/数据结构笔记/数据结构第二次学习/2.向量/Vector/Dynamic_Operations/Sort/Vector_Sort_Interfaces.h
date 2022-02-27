//
// Created by 华邵钶 on 2022/2/27.
//

#ifndef VECTOR_SORT_INTERFACES_H
#define VECTOR_SORT_INTERFACES_H
#include "../../Vector.h"
#include "Vector_BubbleSort.h"

template<typename T>
void Vector<T>::setSortMode(Sort_Mode mode)
{
    defaultSortMode = mode;
}

template<typename T>
void Vector<T>::sort(Rank lo, Rank hi)
{
    if (defaultSortMode == Sort_Mode::BubbleSort){
        bubbleSort<T>(_elem, lo, hi);
    }
}

template<typename T>
void Vector<T>::sort()
{
    sort(0, _size);
}

#endif //VECTOR_SORT_INTERFACES_H

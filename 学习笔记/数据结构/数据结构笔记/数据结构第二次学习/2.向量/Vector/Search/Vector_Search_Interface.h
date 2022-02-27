//
// Created by 华邵钶 on 2022/2/27.
//

#ifndef VECTOR_SEARCH_INTERFACE_H
#define VECTOR_SEARCH_INTERFACE_H
#include "../Vector.h"
#include "Vector_Fib_Binary_Search.h"
#include "Vector_Interpolation_Search.h"

template<typename T>
void Vector<T>::setDefaultSearchMode(Search_Mode mode)
{
    defaultSearchMode = mode;
}

template<typename T>
Rank Vector<T>::search(const T & e, Rank lo, Rank hi) const
{
    if (defaultSearchMode == Search_Mode::BinarySearch) {
        return binSearch(_elem, e, lo, hi);
    }
    else if (defaultSearchMode == Search_Mode::FibonacciSearch) {
        return fibSearch(_elem, e, lo, hi);
    }
    else if (defaultSearchMode == Search_Mode::BinarySearch_2) {
        return binSearch_2(_elem, e, lo, hi);
    }
    else if (defaultSearchMode == Search_Mode::InterpolationSearch) {
        return InterpolationSearch(_elem, e, lo, hi);
    }
}

template<typename T>
Rank Vector<T>::search(const T & e) const
{
    return search(e, 0, _size);
}

#endif //VECTOR_SEARCH_INTERFACE_H

//
// Created by 华邵钶 on 2022/2/28.
//

#ifndef BITMAP_O1_H
#define BITMAP_O1_H

#include "../Vector/Vector.h"
template <typename T>
class BitMap
{
    Vector<int> key,value;
public:
    BitMap<T>(int n = 8);
    // 是否存在
    bool test(T k);
    // 令其存在
    void set(T k);
    // 清空
    void clear(T k);
    // 清空所有
    void clear_all();
};

template<typename T>
inline bool BitMap<T>::test(T k)
{
    return (k < key.size() && key[k] < value.size() && value[key[k]] == k);
}

template<typename T>
inline void BitMap<T>::set(T k)
{
    key[k] = value.size();
    value.push_back(k);
}

template<typename T>
inline void BitMap<T>::clear(T k)
{
    if (test(k)) // k 确实存在
    {
        // 最后一个覆盖第一个
        value[key[k]] = value[value.size() - 1];
        key[value[value.size() - 1]] = k;
        value.resize(value.size() - 1);
    }
}

template<typename T>
BitMap<T>::BitMap(int n)
{
    key.resize(n);
}

template<typename T>
inline void BitMap<T>::clear_all()
{
    value.resize(0);
}


#endif //BITMAP_O1_H

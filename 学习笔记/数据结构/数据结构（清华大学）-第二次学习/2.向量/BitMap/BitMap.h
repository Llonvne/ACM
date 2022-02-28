//
// Created by 华邵钶 on 2022/2/27.
//

#ifndef BITMAP_H
#define BITMAP_H

template<typename T>
class BitMap
{
    T N;
    char * M;
public:
    explicit BitMap(T n = 8);
    ~BitMap();
    // 是否存在
    bool test(T k);
    // 令其存在
    void set(T k);
    // 清空
    void clear(T k);
};

template<typename T>
BitMap<T>::BitMap(T n)
{
    M = new char[N = (n + 7) / 8];
    memset(M, 0, N);
}

template<typename T>
bool BitMap<T>::test(T k)
{
    return M[k >> 3] & (0x80 >> (k & 0x07));
}

template<typename T>
void BitMap<T>::set(T k)
{
    expand(k);
    M[k >> 3] |= (0x80 >> (k & 0x07));
}

template<typename T>
void BitMap<T>::clear(T k)
{
    expand(k);
    M[k >> 3] &= ~(0x80 >> (k & 0x07));
}

template<typename T>
BitMap<T>::~BitMap()
{
    delete[] M;
    M = nullptr;
}




#endif //BITMAP_H

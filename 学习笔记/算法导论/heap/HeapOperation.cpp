//
// Created by 华邵钶 on 2022/5/22.
//

#include "HeapOperation.h"

inline int left(int root)
{
    return 2 * root;
}

inline int right(int root){
    return 2 * root + 1;
}

inline int root(int child)
{
    return child / 2;
}

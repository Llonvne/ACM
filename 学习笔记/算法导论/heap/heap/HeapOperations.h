//
// Created by 华邵钶 on 2022/5/22.
//

#ifndef HEAPOPERATIONS_H
#define HEAPOPERATIONS_H

inline int left(int root)
{
    return 2 * root + 1;
}

inline int right(int root){
    return 2 * root + 2;
}

inline int root(int child)
{
    return (child - 1) / 2;
}

#endif //HEAPOPERATIONS_H

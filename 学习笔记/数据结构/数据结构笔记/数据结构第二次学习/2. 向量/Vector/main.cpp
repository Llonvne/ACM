#include <iostream>

// 导入向量类
#define DEBUG
#include "Vector.h"

int main()
{
    // 向量
    Vector<int> a;

    // 从数组复制
    int b[] = {1,2,3,4,5};
    Vector<int>c(b,0,4);
    c.print();

    // 从向量复制
    Vector<int>d(c);
    d.print();
    Vector<int>e(c,0,2);
    e.print();
}

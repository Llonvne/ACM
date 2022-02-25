#include <iostream>

// 导入向量类
#define DEBUG // DEBUG
#define SHRINK
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

    // call by Rank
    std::cout << e[0] << std::endl;

    // expand
    Vector<int> test_expand;
    test_expand.insert(0,1);
    test_expand.insert(0,2);
    test_expand.insert(0,3);
    test_expand.insert(0,4);
    test_expand.print();


    // insert
    e.insert(0,99);
    e.insert(2,4);
    e.print();

    // 单元素删除
    e.remove(0);
    e.print();

    // 区间删除
    e.remove(0,2);
    e.print();

    // 查找
    test_expand.print();
    std::cout << test_expand.find(99,0,3) << std::endl;

    // 去重复
    int de_array[] = {1,1,1,2,2,2,3,3};
    Vector<int> de(de_array,0,7);
    de.print();
    de.deduplicate_1();
    de.print();
}

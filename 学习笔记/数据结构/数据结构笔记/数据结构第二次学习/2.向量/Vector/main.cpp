// 导入向量类
#define DEBUG // DEBUG
#define SHRINK
#include "Vector.h"


int main()
{
    // 向量
    Vector<int> a;

    // 从数组复制
    int b[] = {1, 2, 3, 4, 5};
    Vector<int> c(b, 0, 4);
    c.print();

    // 从向量复制
    Vector<int> d(c);
    d.print();
    Vector<int> e(c, 0, 2);
    e.print();

    // call by Rank
    std::cout << e[0] << std::endl;

    // expand
    Vector<int> test_expand;
    test_expand.insert(0, 1);
    test_expand.insert(0, 2);
    test_expand.insert(0, 3);
    test_expand.insert(0, 4);
    test_expand.print();


    // insert
    e.insert(0, 99);
    e.insert(2, 4);
    e.print();

    // 单元素删除
    e.remove(0);
    e.print();

    // 区间删除
    e.remove(0, 2);
    e.print();

    // 查找
    test_expand.print();
    std::cout << test_expand.find(99, 0, 3) << std::endl;
    std::cout << test_expand.find(4) << std::endl;

    // 去重复
    int de_array[] = {1, 1, 1, 2, 2, 2, 3, 3};
    Vector<int> de(de_array, 0, 7);
    de.print();
    de.deduplicate_1();
    de.print();

    // 是否排序和逆序对数量
    std::cout << de.disordered() << std::endl;
    std::cout << de.sorted() << std::endl;

    // 有序向量唯一化 低效率版本
    int sorted[] = {1,1,1,2,2,3,4,5,6,7,7,7,7,9};
    Vector<int> sorted_V(sorted,0,14);
    sorted_V.uniquify_v1();
    sorted_V.print();

    // 有序向量唯一化 高效率版本
    int sorted_2[] = {1,1,1,2,2,3,4,5,6,7,7,7,7,9};
    Vector<int> sorted_V2(sorted_2,0,14);
    sorted_V2.uniquify();
    sorted_V2.print();

    // 查找原理算法
    std::cout << sorted_V2.search_v1(3,0,8) << std::endl;

    // FIBONACCI 查找
    std::cout << sorted_V2.search(3,Vector<int>::Search_Mode::FibonacciSearch) << std::endl;
    // 调用默认Bin查找 或者显式调用bin查找
    std::cout << sorted_V2.search(3,Vector<int>::Search_Mode::BinarySearch) << std::endl;
    // BinarySearch 2
    std::cout << sorted_V2.search(3,Vector<int>::Search_Mode::BinarySearch_2) << std::endl;
    // at 函数
    sorted_V2.print();
    std::cout << sorted_V2.at(0) << std::endl;
    // 以下会导致越界
    //std::cout << sorted_V2.at(-1) << std::endl;
    std::cout << "If you can see this means test pass!";
}

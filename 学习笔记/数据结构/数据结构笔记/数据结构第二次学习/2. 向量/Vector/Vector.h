//
// Created by 华邵钶 on 2022/2/25.
//

#ifndef VECTOR_H
#define VECTOR_H

typedef int Rank; // 定义 秩
#define DEFAULT_CAPACITY (3)

template<typename T>
class Vector // 向量模版类
{
private:
    // 下划线一方面表示内部变量，一方面与下面的接口函数做出区分
    Rank _size; // 规模
    int _capacity; // 容量
    T * _elem; // 数据区域

    // 复制构造函数
    void copyFrom(T * A, Rank lo, Rank hi);
protected:
public:
    //--- 构造函数 ---//
    // 初始化容量构造函数
    explicit Vector(int c = DEFAULT_CAPACITY) // 使用 explicit 来禁止隐式转换 详见 C++单参数构造函数 隐式转换
    {
        _capacity = c; // 初始化容量
        _elem = new T[_capacity]; // 为数据区域开辟内存空间
        _size = 0; // 初始化规模
    }

    // 复制数组构造函数
    Vector(T const * A, Rank lo, Rank hi) // 通过 const 来确保不修改 A 数据和接受常量数组
    {
        copyFrom(A, lo, hi);
    }

    // 复制向量区间构造函数
    Vector(Vector<T> const & V, Rank lo, Rank hi)
    {
        copyFrom(V._elem, lo, hi); // 从向量区间复制，成员函数可以访问私有变量，所以直接访问 _elem
    }

    // 复制向量整体构造函数
    Vector(Vector<T> const & V)
    {
        copyFrom(V._elem, 0, V._size);
        // 函数区间复制，通过函数重载实现,等价于上面的 提供 0 和 size() 注意这边因为是成员函数可以使用_size,但是如果是用户只能使用 size()接口
    }

    //--- 构造函数 END ---//

    //--- 析构函数 ---//
    // 释放 new 开辟的 _elem 的空间
    ~Vector()
    {
        delete[] _elem;
    }
    //--- 析构函数 END ---//
};

template<typename T>
void Vector<T>::copyFrom(T * const A, Rank lo, Rank hi)
{
    _capacity = (hi - lo) * 2; // 开辟两倍于区间大小的内存，为什么后面讲
    _size = 0; // 规模清0

    // 复制元素
    while (lo < hi) {
        _elem[_size] = A[lo]; // 复制

        // lo,size 递增
        ++_size;
        ++lo;
    }
}


#endif //VECTOR_H

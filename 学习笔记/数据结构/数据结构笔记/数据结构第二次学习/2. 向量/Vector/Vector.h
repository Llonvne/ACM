#ifndef VECTOR_H
#define VECTOR_H

// Debug
#ifdef DEBUG
// do something
#endif
#ifdef DEBUG
  #include <iostream>
#endif

#include <utility>
#include <algorithm>
typedef int Rank; // 定义 秩
#define DEFAULT_CAPACITY (3)

template<typename T>
class Vector // 向量模版类
{
private:
    // 下划线一方面表示内部变量，一方面与下面的接口函数做出区分
    Rank _size = 0; // 规模
    int _capacity = DEFAULT_CAPACITY; // 容量
    T * _elem; // 数据区域

    // 复制构造函数
    void copyFrom(T const * A, Rank lo, Rank hi);

    // 拓展向量容量
    void expand();
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

    #ifdef DEBUG     // 测试Print函数
    void print() const;
    #endif

};

template<typename T>
void Vector<T>::copyFrom(const T * A, Rank lo, Rank hi)
{
    _capacity = (hi - lo) * 2; // 开辟两倍于区间大小的内存，为什么后面讲
    _elem = new T[_capacity];

    // 复制元素
    for (_size = 0; lo < hi; _size++, lo++) {
        _elem[_size] = A[lo];
    }
}

template<typename T>
void Vector<T>::expand()
{
    // _size < _capacity 没有满，无需拓展
    if (_size < _capacity) {
        return;
    }

    // 容量不得低于最小容量
    _capacity = std::max(_capacity, DEFAULT_CAPACITY);
    T * oldelem = _elem; // 备份原数组地址
    _capacity <<= 1; // 容量加倍
    _elem = new T[_capacity]; // 开辟加倍后容量的空间

    // 复制元素
    for (int i = 0; i < _size; ++i) {
        _elem[i] = oldelem[i]; // 将原数组的元素复制到新开辟的数组
    }

    delete[] oldelem; // 释放原数组内存
}

#ifdef DEBUG
template<typename T>
void Vector<T>::print() const
{
    for (int i = 0; i < _size; ++i) {
        std::cout << _elem[i] << " ";
    }
    std::cout << std::endl;
}
#endif


#endif //VECTOR_H

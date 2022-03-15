#ifndef VECTOR_H
#define VECTOR_H
#pragma once
// 导入定义
#include "Vector_Definitions.h"
// 向量 Vector 模版类
template<typename T>
class Vector
{
private:
    // 规模
    Rank _size = 0;
    // 容量
    int _capacity = DEFAULT_CAPACITY;
    // 数据区域
    T * _elem;
    // 默认查找算法
    Search_Mode defaultSearchMode = DEFAULT_SEARCH_MODE;
    // 默认排序算法
    Sort_Mode defaultSortMode = DEFAULT_SORT_MODE;

    // 拓展向量容量
    void expand();
    // 缩小向量容量
    void shrink();
protected:
    inline T * data(){
        return _elem;
    }
    // 复制构造函数
    void copyFrom(T const * A, Rank lo, Rank hi);
public:
    //--- 构造函数 ---//
    // 初始化容量构造函数 使用 explicit 来禁止隐式转换 详见 C++单参数构造函数 隐式转换
    explicit Vector(int c = DEFAULT_CAPACITY);
    // 复制数组构造函数 通过 const 来确保不修改 A 数据和接受常量数组
    Vector(T const * A, Rank lo, Rank hi);
    // 复制数组构造函数，重载上面函数，用数组长度
    Vector(T const * A,int N);
    // 复制向量区间构造函数
    Vector(Vector<T> const & V, Rank lo, Rank hi);
    // 复制向量整体构造函数
    Vector(Vector<T> const & V);
    // 赋值运算符
    Vector<T> & operator=(const Vector<T> & V);
    // 判等运算符
    bool operator==(const Vector<T> & V) const;

    //--- 析构函数 ---//
    // 释放 new 开辟的 _elem 的空间
    ~Vector();

    //--- 重载下标操作符 & at访问函数 ---//
    T & operator[](Rank r) const; // 用const来修饰this指针以保证不修改内部元素，以访问常量向量
    // 提供与 STL Vector 容器一样提供边界检查的 at 访问函数
    T & at(Rank r) const;
    T & get(Rank r) const;
    T get_copy(Rank r) const;

    // 长度和空向量函数
    int size() const;
    bool empty() const;

    //--- 插入 ---//
    // 在 r 位置插入 e 元素，通过常量引用来加快速度
    Rank insert(Rank r, T const & e);
    Rank insert_InOrder(T const & e);
    Rank push_back(T const & e);

    //--- 删除 ---//
    // 区间元素删除
    int remove(Rank lo, Rank hi);
    // 单个元素删除
    T remove(Rank r);
    // 惰性删除
    void resize(int size);
    // 删除最后一个元素
    void pop_back();

    //--- 无序查找 ---//
    // 区间查找
    Rank find(T const & e, Rank lo, Rank hi) const;
    // 全局查找
    Rank find(T const & e) const;

    //--- 遍历 ---//
    // 函数对象设计 由于是对象，内部可以包含数据，所以可以进行全局性质的修改
    template<class VST> void traverse(VST & visit);

    //--- 是否有序判断 ---//
    // 逆序对统计函数
    int disordered() const;
    // 有序判断函数
    bool sorted() const;

    //--- 去重复函数 ---//
    // 有序向量去重复函数
    int uniquify();
    int deduplicateBasedCompared();
    int deduplicate();
    //--- 搜索算法---//
    // 区间搜索
    Rank search(const T & e, Rank lo, Rank hi) const;
    // 全局搜索
    Rank search(const T & e) const;
    // 设置 defaultSearchMode
    void setSearchMode(Search_Mode mode);

    //--- 排序算法 ---//
    void sort(Rank lo,Rank hi);
    void sort();
    void setSortMode(Sort_Mode mode);
    Vector<T> getSortedCopy() const;

    //--- Debug函数声明 ---//
    #ifdef DEBUG
    // 输出所有的内部的元素，如果要自定义类型需要重载 << 操作符
    void print() const;
    // 繁琐错误的 deduplicateBasedCompared
    int deduplicate_1();
    // 低效的有序向量去重复
    int uniquify_v1();
    // 二分查找——原理
    Rank search_v1(const T & e, Rank lo, Rank hi) const;
    #endif
};
// 导入函数实现
#include "Vector_Includes.h"

#endif //VECTOR_H

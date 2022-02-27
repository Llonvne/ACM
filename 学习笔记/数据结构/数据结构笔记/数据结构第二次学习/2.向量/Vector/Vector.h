#ifndef VECTOR_H
#define VECTOR_H

//--- 配置项 ---//
// 定义 DEBUG 宏变量来启用debug函数，DEBUG模式会有一些不优秀的算法
// 定义 SHRINK 宏变量来开启缩小容量模式,默认将不会缩小向量

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

    // 缩小向量容量
    void shrink();
protected:
public:
    //--- 构造函数 ---//
    // 初始化容量构造函数
    explicit Vector(int c = DEFAULT_CAPACITY); // 使用 explicit 来禁止隐式转换 详见 C++单参数构造函数 隐式转换

    // 复制数组构造函数
    Vector(T const * A, Rank lo, Rank hi); // 通过 const 来确保不修改 A 数据和接受常量数组

    // 复制向量区间构造函数
    Vector(Vector<T> const & V, Rank lo, Rank hi);

    // 复制向量整体构造函数
    Vector(Vector<T> const & V);

    //--- 析构函数 ---//
    // 释放 new 开辟的 _elem 的空间
    ~Vector()
    {
        delete[] _elem;
    }

    //--- 重载下标操作符 ---//
    T & operator[](Rank r) const; // 用const来修饰this指针以保证不修改内部元素，以访问常量向量
    // 通过引用既可以作为右值，也可以作为左值

    //--- 插入 ---//
    // 在 r 位置插入 e 元素，通过常量引用来加快速度
    Rank insert(Rank r, T const & e);

    //--- 删除 ---//
    // 区间元素删除
    int remove(Rank lo, Rank hi);
    // 单个元素删除
    T remove(Rank r);

    //--- 查找 ---//
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
    //--- 是否有序判断 END ---//

    //--- 去重复函数 ---//
    // 有序向量去重复函数
    int uniquify();

    //--- 有序向量查找 ---//
    Rank search(const T & e, Rank lo, Rank hi) const;
    // 全局搜索
    Rank search(const T & e) const;


    //--- Debug函数声明 ---//
    #ifdef DEBUG
    // 测试Print函数
    void print() const;
    // 繁琐错误的 deduplicate
    int deduplicate_1();
    // 低效的有序向量去重复
    int uniquify_v1();
    // 二分查找——原理
    Rank search_v1(const T & e, Rank lo, Rank hi) const;
    #endif
};


#include "Vector_Dynamic_Capacity_Adjustment.h"

#include "Vector_Constructors_Destructor.h"

#include "Vector_Debug_Only.h"

#include "Vector_Static_Operation.h"

#include "Vector_Dynamic_Operations.h"

#endif //VECTOR_H

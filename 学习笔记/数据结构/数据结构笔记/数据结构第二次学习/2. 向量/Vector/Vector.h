#ifndef VECTOR_H
#define VECTOR_H

//--- Debug ---//
// 定义 DEBUG 宏变量来启用debug函数
//--- Debug END ---//
//--- Shrink ---//
// 定义 SHRINK 宏变量来开启缩小容量模式
//--- Shrink END ---//

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

    // 缩小向量容量
    void shrink();
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

    //--- 重载下标操作符 ---//
    T & operator[](Rank r) const; // 用const来修饰this指针以保证不修改内部元素，以访问常量向量
    // 通过引用既可以作为右值，也可以作为左值
    //--- 重载下标操作符 END ---//

    //--- 插入 ---//
    // 在 r 位置插入 e 元素，通过常量引用来加快速度
    Rank insert(Rank r, T const & e);
    //--- 插入 END ---//

    //--- 删除 ---//
    // 区间元素删除
    int remove(Rank lo, Rank hi);
    // 单个元素删除
    T remove(Rank r);
    //--- 删除 END ---//

    //--- 查找 ---//
    Rank find(T const & e, Rank lo, Rank hi) const;
    //--- 查找 END ---//

    //--- 遍历 ---//
    // 函数对象设计 由于是对象，内部可以包含数据，所以可以进行全局性质的修改
    template<class VST> void traverse(VST & visit);
    //--- 遍历 END ---//

    //--- 是否有序判断 ---//
    // 逆序对统计函数
    int disordered() const;
    // 有序判断函数
    bool sorted() const;
    //--- 是否有序判断 END ---//

    //--- 去重复函数 ---//
    // 有序向量去重复函数
    int uniquify();
    //--- 去重复函数 END ---//

    //--- Debug函数声明 ---//
    #ifdef DEBUG
    // 测试Print函数
    void print() const;
    // 繁琐错误的 deduplicate
    int deduplicate_1();
    // 低效的有序向量去重复
    int uniquify_v1();
    #endif
    //--- Debug函数声明 END ---//
};

//--- Debug 函数实现 ---//
#ifdef DEBUG

template<typename T>
void Vector<T>::print() const
{
    for (int i = 0; i < _size; ++i) {
        std::cout << _elem[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
int Vector<T>::deduplicate_1()
{
    int oldsize = _size;
    Rank i = 1; // 第0个一定不会重复，所以从第一个开始
    while (i < _size) {
        // 如果在前面找到了相同的元素 则
        if (find(_elem[i], 0, i) < 0) {
            i++;
        }
            // 反之
        else {
            remove(i);
        }
    }
    return oldsize - _size; // 删除的元素总数
}

template<typename T>
int Vector<T>::uniquify_v1()
{
    // 非有序向量，退出
    if (!sorted()) {
        return 0;
    }
    int oldsize = _size;
    int i = 0; // 从第0个元素开始
    while (i < _size - 1) {
        if (_elem[i] == _elem[i + 1]) // 如果与后面的元素相等
        {
            remove(i + 1);// 删除后面第元素
        }// 否则
        else {
            i++; // 移动到后面一个元素
        }
    }
    return oldsize - _size;
}

#endif
//--- Debug 函数实现 END ---//

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

template<typename T>
void Vector<T>::shrink()
{
    #ifdef SHRINK
    if (_capacity < DEFAULT_CAPACITY << 1) {  // 如果容量小于最小容量的两倍，不缩小
        return;
    }
    if (_size << 4 > _capacity) { // size * 4 < capacity 才缩容量
        return;
    }

    // 备份原来的数组
    T * oldelem = _elem;
    _capacity >>= 1; // 容量缩小一半
    _elem = new T[_capacity >> 1]; // 重新开辟空间

    // 复制元素
    for (int i = 0; i < _size; ++i) {
        _elem[i] = oldelem[i];
    }

    // 释放原来的空间
    delete[] oldelem;
    #endif
}

template<typename T>
T & Vector<T>::operator[](Rank r) const
{
    return _elem[r];
}

template<typename T>
Rank Vector<T>::insert(Rank r, const T & e)
{
    // insert 属于动态操作需要考虑到容量
    expand(); // 如果向量满了则拓展容量

    // 从最后面开始不断向前 直到 r 元素
    for (int i = _size; i > r; --i) {
        _elem[i] = _elem[i - 1]; // 不断前移 最后一次是 i = r + 1 => _elem[r+1] = _elem[r]
    }
    _elem[r] = e; // 插入元素
    ++_size; // 更新容量

    return r; // 返回插入的位置
}

template<typename T>
int Vector<T>::remove(Rank lo, Rank hi)
{
    if (lo == hi) { // 因为 [hi,lo) 所以相等时不包含元素 删除0个元素
        return 0;
    }

    while (hi < _size) {
        _elem[lo] = _elem[hi]; // 将区间后到第一个元素覆盖到区间到第一个元素，不断重复，直达尾部
        ++lo;
        ++hi;
    }

    _size = lo; // 更新容量

    shrink(); // 有必要,缩小容量
    return hi - lo;
}

template<typename T>
T Vector<T>::remove(Rank r)
{
    // 有必要就缩小容量
    shrink();

    T e = _elem[r]; // 备份被删除的元素
    remove(r, r + 1); // 调用区间删除函数，删除r位置的元素
    return e; // 返回被删除的元素
}

template<typename T>
Rank Vector<T>::find(const T & e, Rank lo, Rank hi) const
{
    while (lo < hi) {
        if (e == _elem[--hi]) { // 命中直接返回
            return hi;
        }
    }
    return -1;
}

template<typename T> template<typename VST>
void Vector<T>::traverse(VST & visit)
{
    for (int i = 0; i < _size; ++i) {
        visit(_elem[i]);
    }
}

template<typename T>
int Vector<T>::disordered() const
{
    int n = 0; // 逆序对数量统计
    for (int i = 1; i < _size; ++i) {
        if (_elem[i - 1] > _elem[i]) // 如果前面一个后面一个 就 ++
        {
            ++n;
        }
    }
    return n;
}

template<typename T>
bool Vector<T>::sorted() const
{
    for (int i = 1; i < _size; ++i) {
        if (_elem[i - 1] > _elem[i]) // 一旦前面一个大于后面一个
        {
            return false;
        }
    }
    return true;
}

template<typename T>
int Vector<T>::uniquify()
{
    // 无序向量 退出
    if (!sorted() || _size <= 1){
        return 0;
    }
    Rank i = 0,j = 0;
    while (++j < _size ){ // 循环所有元素
        if (_elem[i] != _elem[j]){ // 如果雷同
            _elem[++i] = _elem[j]; // 将j移动到 i+1，同时i向后移动
        }
    }
    // 此时i是最后一个不重复元素的下标
    _size = ++i; // 规模的最后一个元素的下标+1
    shrink(); // 如果有必要就减少容量
    return j - i ; // 此时 j 就是原来数组的大小 i == _size 是现在数组的大小
}

#endif //VECTOR_H

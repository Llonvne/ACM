//
// Created by 华邵钶 on 2022/2/28.
//

#ifndef VECTOR_UNIQUIFY_DEDUPLICATE_H
#define VECTOR_UNIQUIFY_DEDUPLICATE_H
#include "../../Vector.h"
#include "../../../BitMap/BitMap.h"

template<typename T>
int Vector<T>::uniquify()
{
    Rank i = 0, j = 0;
    while (++j < _size) { // 循环所有元素
        if (_elem[i] != _elem[j]) { // 如果雷同
            _elem[++i] = _elem[j]; // 将j移动到 i+1，同时i向后移动
        }
    }
    // 此时i是最后一个不重复元素的下标
    _size = ++i; // 规模的最后一个元素的下标+1
    shrink(); // 如果有必要就减少容量
    return j - i; // 此时 j 就是原来数组的大小 i == _size 是现在数组的大小
}

template<typename T>
int Vector<T>::deduplicate()
{
    int oldsize = _size;
    BitMap<int> needTodelete(_size);
    for (int i = 1; i < _size; ++i) {
        int result = find(_elem[i],0,i);
        if (result != -1){
            needTodelete.set(result);
        }
    }
    int top = 0;
    for (int i = 0; i < _size; ++i) {
        if (!needTodelete.test(i)){
            _elem[top++] = _elem[i];
        }
    }
    resize(top);
    return oldsize - _size;
}

template<typename T>
int Vector<T>::deduplicateBasedCompared()
{
    // 保存原来的尺寸
    int oldsize = _size;
    // 保存用户设计的排序模式
    Sort_Mode old = this->defaultSortMode;
    // 设置排序模式为 MergeSort
    setSortMode(Sort_Mode::MergeSort);
    // 获得拷贝后向量的排序 O(nlogn)
    Vector<T> copy = this->getSortedCopy();
    // 恢复用户的排序模式
    setSortMode(old);
    // 对有序向量进行去重复 O(n)
    copy.uniquify();

    // 栈顶计数
    int top = 0;
    // 建立BitMap 大小为去重复数组对大小
    BitMap<int> M(copy.size());
    // 保存用户的搜索算法
    Search_Mode old_search_mode = defaultSearchMode;
    // 启用 FibonacciSearch 算法
    setSearchMode(Search_Mode::FibonacciSearch);
    for (int i = 0; i < _size; i++) { // O(n)
        // 获得 _elem[i] 在去重复后对位置 O(logN)
        int searchResult = copy.search(_elem[i]);
        //如果还不存在
        if (!M.test(searchResult))
        {
            M.set(searchResult); // 设置为存在
            _elem[top++] = _elem[i]; // 栈顶自增，赋值
        }
    }
    // 恢复用户的搜索算法
    setSearchMode(old_search_mode);
    resize(top); // 采用惰性删除
    shrink(); // 有必要的话 缩小容量
    return oldsize - top;
}

#endif //VECTOR_UNIQUIFY_DEDUPLICATE_H

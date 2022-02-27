//
// Created by 华邵钶 on 2022/2/27.
//

#ifndef VECTOR_DEFINITIONS_H
#define VECTOR_DEFINITIONS_H
// 定义内部序号
typedef int Rank;
// 定义查找模式
enum class Search_Mode : unsigned int
{
    BinarySearch, FibonacciSearch, BinarySearch_2, InterpolationSearch
};
// 定义排序模式
enum class Sort_Mode : unsigned int
{
    BubbleSort,SelectionSort,MergeSort,HeapSort,QuickSort
};
// 定义默认的容量
constexpr int DEFAULT_CAPACITY = 100;
// 定义默认的搜索方式
constexpr Search_Mode DEFAULT_SEARCH_MODE = Search_Mode::BinarySearch;
// 定义默认的排序方式
constexpr Sort_Mode DEFAULT_SORT_MODE = Sort_Mode::BubbleSort;
// 定义每次扩容的倍数
constexpr int CAPACITY_MULTIPLIER_EXPAND = 2;
// 定义扩容的边界
constexpr int CAPACITY_EXPAND_LIMIT = 1;
// 定义每次减少的倍数
constexpr int CAPACITY_MULTIPLIER_SHRINK = 2;
// 定义需要减少的边界
constexpr double CAPACITY_SHRINK_LIMIT = 0.25;
#endif //VECTOR_DEFINITIONS_H

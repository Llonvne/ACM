#include "bits/stdc++.h"
using namespace std;
// 判断是不是空元组
bool isZeroTuple(array<int, 20> tuple, int size)
{
    return (std::all_of(tuple.begin(), tuple.begin() + size,
                        [&](const int item)
                        {
                            return item == 0;
                        }));
    // 上述等价于下面的算法
//    for (int i = 0; i < size; ++i) {
//        if (tuple[i] != 1){
//            return false;
//        }
//    }
//    return true;
}
// 生成下一代数组
void next_tuple(array<int,20>& tuple,int size){
    // 保存第一个元素
    int first = tuple[0];
    // 求 [0,size - 1) 
    for (int i = 0; i < size - 1; ++i) {
        tuple[i] = std::abs(tuple[i] - tuple[i+1]);
    }
    // 生成最后一个
    tuple[size - 1] = std::abs(first - tuple[size - 1]);
}

int main()
{
    // 测试用例数量
    int N;
    cin >> N;
    // 元组数据
    array<int,20> tuple;
    for (int i = 0; i < N; ++i) {
        // 测试数据输入
        int size;
        scanf("%d", &size);
        for (int j = 0; j < size; ++j) {
            scanf("%d",&tuple[j]);
        }

        // 最大迭代次数不会超过 1000 次，这边用 1002 强保证， 在每次判断之前都判断是否是 0 元组
        for (int j = 0; j < 1002 && !isZeroTuple(tuple,size); ++j) {
            next_tuple(tuple,size);
        }
        if (isZeroTuple(tuple,size)){
            printf("ZERO\n");
        }
        else {
            printf("LOOP\n");
        }
    }
}
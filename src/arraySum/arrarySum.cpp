// 计算 N 个整数之和
// 迭代版本 
// Decrease and Conquer 减而治之 每次规模缩减 O(1)
int sumIteration(int A[],int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
    }
    return sum;
}
// 线性递归版本 还是 Decrease and Conquer
// [0,n)
int sumRecursion(int A[],int n){
    return n == 0 ? 0 : sumRecursion(A,n-1) + A[n-1];
}

#include <iostream>
int main(){
    int A[] = {1,2,3,4,5,6,7,8};
    std::cout << sumRecursion(A,8);
}
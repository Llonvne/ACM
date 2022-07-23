#include "bits/stdc++.h"
using namespace std;

// 打印子集
void print_subset(int n,int A[],int cur){
    
    // 打印当前集合
    for (int i = 0; i < cur; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");

    // 确定当前元素最小的可能值
    int s = cur ? A[cur-1] : 0;

    // 递归构造子集
    for (int i = s+1; i <= n; i++)
    {
        A[cur] = i;
        print_subset(n,A,cur+1);
    }
    
}

int main(int argc, char *argv[])
{
    int n = 4;
    int A[n];
    print_subset(n,A,0);
    return 0;
}
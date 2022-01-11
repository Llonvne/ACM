// 接口标准化
int arraySum(int A[],int n){
    return sumIteration(A,n);
    // return sumLinearRecursion(A,n);
    // return SumFoldRecursion(A,0,n);
}

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
int sumLinearRecursion(int A[],int n){
    return n == 0 ? 0 : sumLinearRecursion(A,n-1) + A[n-1];
}

// Divide and Conquer 二分递归解决方法
// [lo,hi]
int sumFoldRecursion(int A[],int lo,int hi){
    if (lo == hi) // Recursion base case
    {
        return A[lo]; // or A[hi] because of lo == hi so A[lo] == A[hi]
    }
    int mi = (lo + hi) >> 1; // >> 1 == /2 but faster
    return sumFoldRecursion(A,lo,mi) + sumFoldRecursion(A,mi + 1,hi);
}

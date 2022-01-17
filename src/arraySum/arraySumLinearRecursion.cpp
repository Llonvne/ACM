// Array Sum Linear Recursion 线性递归版本 [0,n)
int sumLinearRecursion(int A[],int n){
    return n == 0 ? 0 : sumLinearRecursion(A,n-1) + A[n-1];
}
// Decrease and Conquer 减而治之
// 返回 n 个元素的中的最大值 线性递归版本 O(N)
int maxNumber(int A[],int n){
    if (n == 1){
        return A[0];
    }
    int frontMax = maxNumber(A,n-1);
    return frontMax > A[n-1] ? frontMax : A[n-1];
}
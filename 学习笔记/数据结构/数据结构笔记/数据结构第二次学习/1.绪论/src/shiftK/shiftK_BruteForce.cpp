// 移动一位
void shift1(int A[],int n){
    // 平凡情况
    if (n <= 1){
        return;
    }
    int temp = A[0];
    for (int i = 1; i < n; ++i) {
        A[i-1] = A[i];
    }
    A[n-1] = temp;
}
// 移动 k 位
void shiftK(int A[],int n,int k){
    for (int i = 0; i < k; ++i) {
        shift1(A,n);
    }
}
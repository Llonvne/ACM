// 内联了 reverse 算法
void reverse(int A[],int lo,int hi){
    while (lo < hi){
        swap(A[lo++],A[--hi]);
    }
}
void reverse(int A[],int n){
    reverse(A,0,n);
}

// 可以用两本书理解 不妨把 0,k 理解为第一本书 k,n 理解为第二本书操作一下
void shiftK(int A[],int n,int k){
    reverse(A,k);
    reverse(A,k,n - k);
    reverse(A,n);
}
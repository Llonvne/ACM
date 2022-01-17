// 内联了 reverse 算法 此处reverse 为自己实现，而非C++提供的算法
void reverse(int A[],int lo,int hi){
    while (lo < hi){
        swap(A[lo++],A[--hi]);
    }
}
void reverse(int A[],int n){
    reverse(A,0,n);
}

// 向左移动
// 可以用两本书理解 不妨把 0,k 理解为第一本书 k,n 理解为第二本书操作一下
void shiftK(int A[],int n,int k){
    reverse(A,k);
    reverse(A,k,n - k);
    reverse(A,n);
} // O(3n) 但是要比那个 O(1.5n) 快很多
// 因为连续访问 Cache加速
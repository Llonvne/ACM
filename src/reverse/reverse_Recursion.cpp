// reverse 递归版本统一接口
void reverse(int A[],int n){
    reverseRecursion(A,0,n);
}
// 数组倒置 递归版本 [lo,hi) 减而治之 
void reverseRecursion(int A[],int lo,int hi){
    if (lo < hi){
        swap(A[lo],A[hi-1]);
        reverseRecursion(A,lo+1,hi-1);
    }
}
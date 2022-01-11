// 减而治之 迭代 [lo,hi)
void reverse(int A[],int lo,int hi){
    while (lo < hi){
        swap(A[lo++],A[--hi]);
    }
}
// 减而治之 递归 [lo,hi)
void reverse(int A[],int lo,int hi){
    if (lo < hi){
        swap(A[lo],A[hi-1]);
        reverse(A,lo+1,hi-1);
    }
}
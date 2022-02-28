// 数组倒置 迭代版本 [lo,hi)
void reverse(int A[],int lo,int hi){
    while (lo < hi){
        swap(A[lo++],A[--hi]);
    }
}

// 返回 n 个元素的中的最大值 二分递归版本 O(n)
int maxNumber(int A[],int n){
    // 使用函数重载的形式实现统一接口
    maxNumber(A,0,n);
}
int maxNumber(int A[],int lo,int hi){
    // 递归基 区间只有一个元素
    if (lo + 1 == hi){
        return A[lo];
    }
    int mi = (lo + hi) >> 1;
    int leftMax = maxNumber(A,lo,mi);
    int rightMax = maxNumber(A,mi,hi);
    
    return leftMax > rightMax ? leftMax : rightMax;
}
// 返回 n 个元素的中的最大值 迭代版本 O(n)
int maxNumber(int A[],int n){
    // 平凡情况 只有一个元素
    if (n == 1)
    {
        return A[0];
    }
    // 假设第一个元素为最大元素
    int max = A[0];
    // 开始比较
    for (int i = 1; i < n; i++)
    {
        max = A[i] > max ? A[i] : max;
    }
    return max;
}
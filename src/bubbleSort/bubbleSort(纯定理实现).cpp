// 冒泡排序
// 纯粹定理的版本,即如果一个序列不存在逆序元素即为有序
// 默认实现 从小到大排序
void bubbleSort(int A[],int n){
    bool sorted = true;
    while (!sorted){
        for (int i = 1; i < n; i++)
        {
            if (A[i-1] > A[i])
            {
                int temp = A[i-1];A[i-1] = A[i];A[i] = temp;
                sorted = false;
            }
        }
    }
}
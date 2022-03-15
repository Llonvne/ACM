// 递归版本插入排序
void insertionSort(int a[],int lo,int hi){ // A[lo,hi)
    if (hi - lo == 1){ // 如果只有一个元素自然有序
        return;
    }
    insertionSort(a,lo,hi-1); // 递归排序 前 [lo,hi-1)
    // 将 第 hi 插入到 前面有序 hi-1个中
    int key = a[hi-1]; // 第hi个下标为 hi-1
    int i; // 在循环外部定义 i 用来保存结束位置
    for (i = hi-2; i >= 0; --i) { // 从 hi downto 0
        if (a[i] > key){ // 如果 a[i] > key 说明还不到插入位置
            a[i+1] = a[i]; // 将 a[i] -> a[i+1] 向后移动腾出位置
        }
        else { // 一旦 a[i] < key 说明 i+1就是插入位置，此时 a[i+1] -> a[i+2] 所以退出直接插入
            break;
        }
    }
    // 插入
    a[i+1] = key;
}
int partition(int a[],int p,int q){
    int x = a[p]; // pivot value
    int i = p; // pivot index
    for (int j = p+1; j < q ; ++j) { // partition
        if (a[j] < x){
            ++i;
            std::swap(a[i],a[j]);
        }
    }
    std::swap(a[p],a[i]); // move pivot to middle of array
    return i;
}
int rand_partition(int A[], int lo, int hi)
{
    // 随机选择支点
    int pivot = (rand() % (hi-lo))+ lo; // [lo,hi)
    // 把支点换到第一个
    std::swap(A[lo],A[pivot]);
    // 调用partition
    return partition(A,lo,hi);
}
void quickSort(int A[],int p,int q){
    if (p < q){
        int pivot = partition(A,p,q);
        quickSort(A,p,pivot);
        quickSort(A,pivot + 1,q);
    }
}
void quickSort(int A[],int n){
    quickSort(A,0,n);
}
void rand_quickSort(int A[],int p,int q){
        if (p < q){
        int pivot = rand_partition(A,p,q);
        quickSort(A,p,pivot);
        quickSort(A,pivot + 1,q);
    }
}
void rand_quickSort(int A[],int n){
    rand_partition(A,0,n);
}
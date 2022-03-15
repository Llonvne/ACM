void merge(int A[],int lo,int mi,int hi);
void mergeSort(int A[],int lo,int hi){
    // 如果只有一个元素直接返回，因为一个元素本省有序
    if (hi - lo == 1){
        return;
    }
    int mi = (lo + hi) >> 1; // 取中点
    mergeSort(A,lo,mi); // [lo,mi) 
    mergeSort(A,mi,hi); // [mi,hi)
    merge(A,lo,mi,hi); // 合并两个有序数组 A[lo,mi),A[mi,hi)
}
void merge(int A[],int lo,int mi,int hi){
    int n1 = mi - lo; // 数组1的长度
    int n2 = hi - mi; // 数组2的长度
    int L[n1],R[n2];  // 两个数组的拷贝
    for (int i = 0; i < n1; ++i) { // 拷贝数组1
        L[i] = A[lo + i];
    }
    for (int i = 0; i < n2; ++i) { // 拷贝数组2
        R[i] = A[mi + i];
    }
    int i = 0,j = 0,k = lo; // i 表示 数组1的访问点，j 表示 数组2的访问位置，k表示原来的数组的访问位置 
    while (i < n1 && j < n2){ // 当数组1和2都没有被访问完
        if (L[i] < R[j]){ // 如果 L[i] < R[j]
            A[k] = L[i++];
        }
        else {
            A[k] = R[j++];
        }
        k++;
    }
    // 如果 k已经是hi 说明已经完成直接退出
    if (k == hi){
        return;
    }
    else if (i == n1){ // 如果 1 完成了就是需要复制2
        for (int l = j; l < n2; ++l) {
            A[k++] = R[l];
        }
    }// 反之复制1
    else {
        for (int l = i; l < n1; ++l) {
            A[k++] = L[l];
        }
    }
}
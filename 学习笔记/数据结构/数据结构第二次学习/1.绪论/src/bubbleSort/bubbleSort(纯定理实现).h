void bubbleSort(int A[],int n){
    bool sorted = false;
    while (!sorted){
        sorted = true;
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
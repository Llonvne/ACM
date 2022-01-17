// Array Sum Iteration 迭代版本 
int sumIteration(int A[],int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
    }
    return sum;
}
// Decrease and Conquer 减而治之 每次规模缩减 O(1)
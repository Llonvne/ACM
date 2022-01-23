/*
\brief: Array Sum Iteration Version 

@params: int A[]; Summed Array
@params: int n; Array size;

@return: The sum of the arrays

\details: This function uses an iterative method to find the sum of arrays, 
with time complexity O(n) and space complexity O(1)

*/
int sumIteration(int A[],int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
    }
    return sum;
}
// Decrease and Conquer 减而治之 每次规模缩减 O(1)
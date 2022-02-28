/*
\brief: Array Sum Function Interface

@params: int A[]; Summed Array
@params: int n; Array size;

@return: The sum of the arrays

\details: This function defines the interface to the rest of the summation functions, 
and the different array summation functions can be called by modifying the annotations

*/
int arraySum(int A[],int n){

    // Iterative version of the array summation function
    return sumIteration(A,n); 

    // Linear recursive summation functions
    // return sumLinearRecursion(A,n);

    // Dichotomous recursive summation functions for arrays
    // return SumFoldRecursion(A,0,n-1);
}

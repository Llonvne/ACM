/*
\brief: Array Sum Fold Recursion 

@params: int A[]; Summed Array
@params: int lo; Left bound
@params: int hi; Right bound

@return: The sum of the arrays

\details: This function uses dichotomous recursion for summing arrays, with a time complexity of O(n)
space complexity is O(n), recursion depth O(logn).

\addictions: recursive base: the interval narrows to 1 when the argument lo is equal to the argument hi, and returns A[lo] directly.
If the parameter lo is less than hi, that is, 
the interval is greater than 1, 
then the interval will be divided into two intervals of length folded in half to the sub-problem to deal with

Divide and conquer

T(1) = O(1);
T(n) = 2(n/2)
=> T(n) = O(n)
*/
int sumFoldRecursion(int A[],int lo,int hi){
    if (lo == hi) // Recursion base case
    {
        return A[lo]; // or A[hi] because of lo == hi so A[lo] == A[hi]
    }
    int mi = (lo + hi) >> 1; // >> 1 == /2 but faster
    return sumFoldRecursion(A,lo,mi) + sumFoldRecursion(A,mi + 1,hi);
}
/*
\brief: Array Sum Linear Recursion

@params: int A[]; Summed Array
@params: int n; Array size;

@return: The sum of the arrays

\details: This array summation function uses linear recursion to sum arrays, 
with time complexity O(n), space complexity O(n), and recursion depth O(n).

\addictions: 
The recursive base parameter n is equal to 0, i.e. there are no elements, and 0 is returned directly
When n>0, A[n-1] will be added to the first n-1 sums and returned；

Decrease and Conquer 

T(1) = O(1);
T(n) = T(n-1) + O(1)
=> T(n) = O(n)
*/
int sumLinearRecursion(int A[],int n){
    return n == 0 ? 0 : sumLinearRecursion(A,n-1) + A[n-1];
}
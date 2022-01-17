// Array Sum Fold Recursion 二分递归版本 [0,n];
int sumFoldRecursion(int A[],int lo,int hi){
    if (lo == hi) // Recursion base case
    {
        return A[lo]; // or A[hi] because of lo == hi so A[lo] == A[hi]
    }
    int mi = (lo + hi) >> 1; // >> 1 == /2 but faster
    return sumFoldRecursion(A,lo,mi) + sumFoldRecursion(A,mi + 1,hi);
}
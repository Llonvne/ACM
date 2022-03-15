#include "bits/stdc++.h"
#include "../排序/快速排序/quickSort.h"
using namespace std;

int rand_select(int A[], int lo, int hi, int th)
{ // [lo,hi)
    srand((int)time(nullptr));
    if (hi - lo == 1) {
        return A[lo];
    }
    int r = rand_partition(A, lo, hi);
    int r_th = r - lo + 1;
    if (r_th == th) { return A[r]; }
    if (th < r_th){return rand_select(A,lo,r,th);}
    else return rand_select(A,r+1,hi,th);
}

int main(int argc, char **argv) {
    int A[] = {3,6,2,4,2,6,1};
    cout << rand_select(A,0,7,1);
}
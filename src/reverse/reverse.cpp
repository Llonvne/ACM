// 减而治之 迭代 [lo,hi)
void reverse(int A[],int n){
    reverseRecursion(A,0,n);
}
void reverse(int A[],int lo,int hi){
    while (lo < hi){
        swap(A[lo++],A[--hi]);
    }
}
// 数组倒置 递归版本 [lo,hi) 减而治之 
void reverseRecursion(int A[],int lo,int hi){
    if (lo < hi){
        swap(A[lo],A[hi-1]);
        reverseRecursion(A,lo+1,hi-1);
    }
}

// vector<char> leetcode 344
class Solution {
public:
    void reverseString(vector<char>& s) {
        uint32_t lo = 0,hi = s.size() - 1;
        
        while (lo < hi){
            swap(s[lo++],s[hi--]);
        }
    }
};
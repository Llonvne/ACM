// fibnacci 数列线性递归 O(n)
// prev 用来记录前一项
int64_t fib(int n,int64_t& prev){
    if (0 == n){
        // fib(-1) = 1,fib(0) = 0; 直接取 0
        prev = 1;
        return 0;
    }
    int64_t prevPrev;
    prev = fib(n-1,prevPrev);
    return prev + prevPrev;
}
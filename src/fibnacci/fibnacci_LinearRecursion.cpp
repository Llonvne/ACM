// fibnacci 数列线性递归 O(n)
// prev 用来记录前一项
uint64_t fib(int n,uint64_t& prev){
    if (0 == n){
        // fib(-1) = 1,fib(0) = 0; 直接取 0
        prev = 1;
        return 0;
    }
    uint64_t prevPrev = fib(n-1,prev); // 算出前两项
    return prev + prevPrev; 
}
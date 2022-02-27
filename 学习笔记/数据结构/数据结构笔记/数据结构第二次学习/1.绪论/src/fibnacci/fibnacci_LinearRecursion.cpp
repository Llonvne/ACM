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

// Fib函数统一入口
int64_t fib(int n){
    // 因为线性递归必须在形式参数中传递 prev 所以可以函数重载，通过该接口函数隐式调用
    int64_t prev;
    return fib(n,prev);
}

// 该算法在开始计算 Fib(n != 0)的时候，会不断向下递归 每一次n都减少1
// 直到 n == 0 时候， 另 prev = 1; 这样使得第 0 项和第一项初始化为 1 和 2
// 这样的写法可能会稍微难以理解 我们可以稍加改动

int64_t fib(int n,int64_t& prev){
    if (n == 1){
        prev = 0; // fib(0) = 0
        return 1; // fib(1) = 1
    }
    int64_t prevPrev;
    prev = fib(n-1,prevPrev);
    return prev + prevPrev;
}
int64_t fib(int n){
    if (n == 0){
        return 0;
    }
    int64_t prev;
    return fib(n,prev);
}
// 将 fib 递归函数中 排除 n == 0的情况交由上层接口函数处理，而在fib递归函数只递归到第一项，
// 这样子 prev 即是 第 0 项 为 0，return 第一项为 1
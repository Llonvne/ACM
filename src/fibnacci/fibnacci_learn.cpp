// Fibnacci 递归算法实现 时间复杂度 O(2^N)
int fib(int n){
    return n < 2 ? n : fib(n-1) + fib(n-2);
}

// Fibnacci 迭代动态规划实现
// 从递归的自上而下递归实现 转换为 自底向上迭代实现
int fib(int n) {
    int f = 0;
    int g = 1;
    while (n--){
        g += f; f = g-f;
    }
    return g;
}


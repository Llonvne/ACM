// Fibnacci 递归实现 时间复杂度 O(2^N)
int fib(int n){
    return n < 2 ? n : fib(n-1) + fib(n-2);
}
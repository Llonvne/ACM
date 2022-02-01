// Fibnacci 迭代动态规划实现
int fib(int n) {
    int f = 0;
    int g = 1;
    while (n--){
        g += f; f = g-f;
    }
    return g;
}
// 从递归的自上而下递归实现 转换为 自底向上迭代实现


// 统计参数 n 二进制展开后里面 1 的个数 O(CountOnes(n)) 复杂度线性正比于 
// n 二进制展开后1的个数 == O(ones)
int CountOnes(int n){
    int ones = 0;
    while (0 < n){
        ++ones;
        n &= (n - 1); // 清楚最靠右的 1
    }
    return ones;
}
// 统计参数 n 二进制展开后里面 1 的个数 O(logN)
int CountOnes(int n){
    int ones = 0;

    while (0 < n){
        ones += (1 & n) ; // 检查最低位
        n >>= 1; // 向右移动一位(去除最低位)
    }
    return ones;
}
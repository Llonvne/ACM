// 统计参数 n 二进制展开后里面 1 的个数 O(log2W)
// 其中 W = O(log2N) 是整数的二进制表示的位宽
#define POW(c) (1 << (c)) // 2^c 宏实现
#define MASK(c) (((unsigned long) -1 ) / (POW(POW(c)) + 1))
// MASK(0) = 5555,5555(h) = 01010101,01010101,01010101,01010101(b)
// MASK(1) = 3333,3333(h) = 00110011,00110011,00110011,00110011(b)
// MASK(2) = 0f0f,0f0f(h)
// MASK(3) = 00ff,00ff(h)
// MASK(4) = 0000,ffff(h)

// 输入 n的二进制展开中，以 2^c 位为单位分组 各组数值已经分别等于原先这 2^c 位中1的数目
#define ROUND(n,c) (((n) & MASK(c)) + ((n) >> POW(c) & MASK(c)))
// 过程 以 2^c 位为单位分组，相邻的组两两捉对累加，累加值用原 2^(c+1) 就地记录
// 输出 n的二进制展开中，以 2^c 位为单位分组 各组数值已经分别等于 原先这个 2^(c+1)位中 1 的数目

int CountOnes(int n){
    n = ROUND( n, 0);
    n = ROUND( n, 1);
    n = ROUND( n, 2);
    n = ROUND( n, 3);
    n = ROUND( n, 4);
    return n;
}
// 三十二位字长 O(log_2(32)) = O(5) = O(1)
// GreatestCommonDivisor_Fast中华更相减损术(GCD)
// 本算法将所有运算更变为 位和+-以提升速度！
int64_t gcd(int64_t a, int64_t b){

    // a 与 b 的 2^r 形式的公共因子
    int r = 0;

    // 如果 a 和 b 都是偶数
    while (! ((a & 1) || (b & 1))){ // (!(a % 2 == 1) || (b % 2 == 1))

        // a,b 同时除 2
        a >>= 1; b >>= 1; // a /= 2; b/=2;

        // r++ 等价于 2^r 乘2
        ++r;

    }
    // 现在：a 和 b 中一定有一个奇数

    while (1){

        // 如果 b 是偶数 就不断除2
        while (! (a & 1) ) { // (!(a % 2 == 1))
            a >>= 1; // a /= 2;
        }

        while (! (b & 1)) { // 同上
            b >>= 1;
        }

        // 等价于 gcd(max(a,b) - min(a,b),min(a,b))
        (a > b) ? a = a - b : b = b -a;

        // 平凡情况 gcd(0,b) = b
        if (a == 0){
            return b << r;
        }

        // 同上
        if (b == 0){
            return a << r;
        }

    }
}
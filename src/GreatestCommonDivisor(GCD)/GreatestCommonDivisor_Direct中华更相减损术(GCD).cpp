// Greatest Common Divisor(GCD) 直接使用 goto语句翻译
// 请注意该版本的算法是为与中华更相减损术相匹配，请勿对代码格式作出苛求.
int64_t gcd(int64_t x, int64_t y) {
    int64_t p = 1;  // 令 p = 1

    a: if (x % 2 == 1 || y % 2 == 1) goto b; // 如果 a和b 不都是偶数 则转到 b
    p *= 2;x /= 2;y /= 2; // p乘二 x,y乘二.
    goto a; 

    b: int64_t t = x-y>0 ? x-y : -x+y; // 令 t = |a-b|
    if (t == 0) return x * p; // 如果 t = 0 就返回 x * p

    d :if (t % 2 == 1) goto c; // 如果 t 是奇数
    t = t/2; // t 除以2
    goto d; 

    c: if(x >= y) x = t; //如果 x >= t 则 a = t 否则 b = t;
    else y = t;
    goto b; 
}
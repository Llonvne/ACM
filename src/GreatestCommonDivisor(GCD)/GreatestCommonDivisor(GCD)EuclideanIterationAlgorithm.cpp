//GreatestCommonDivisor(GCD) EuclideanIterationAlgorithm
// 不难发现原本的递归是一个尾递归，经过简单处理就可以转换为迭代算法.
int64_t gcd(int64_t a, int64_t b)
{
    while (a % b != 0){
        int64_t t = a;
        a = b;
        b = t % a;
    }
    return b;
}


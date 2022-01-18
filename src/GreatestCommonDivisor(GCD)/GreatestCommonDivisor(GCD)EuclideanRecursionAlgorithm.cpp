// GreatestCommonDivisor(GCD) Euclidean Recursion Algorithm
int64_t gcd(int64_t a, int64_t b){
    if (a % b == 0){
        return b;
    }
    else return gcd(b, a%b);
}
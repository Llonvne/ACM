//中华更相减损术
// GreatestCommonDivisor(GCD)
int gcd(int a,int b){
    int p = 1;
    while ((a % 2 == 0)&&(b % 2 == 0)){
        p *= 2;
        a /= 2;
        b /= 2;
    }
    int t = a-b > 0 ? a-b : -a+b;
    while (t != 0){
        while (t % 2 == 0 ){
            t/=2;
        }
        if (a >= b){
            a = t;
        }
        else {
            b = t;
        }
        t = a-b > 0 ? a-b : -a+b;
    }
    return a*p;
}
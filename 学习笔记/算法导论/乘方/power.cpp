// divide and conuquer
int powering(int base,int exponent){ // O(logn)
    if (exponent == 1){
        return base;
    }
    // 是偶数
    if (exponent % 2 == 0){
        int n_2 = powering(base,exponent / 2);
        return n_2 * n_2;
    }
    // 是奇数
    int n_2 = powering(base,(exponent-1)/2);
    return base * n_2 * n_2;
}
int powering_naive(int base,int exponent){ // O(n)
    for (int i = 0; i < exponent-1; i++)
    {
        base *= exponent;
    }
    return base;
}
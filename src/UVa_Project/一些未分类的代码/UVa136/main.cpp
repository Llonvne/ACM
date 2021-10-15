#include "bits/stdc++.h"
using namespace std;

#define MAX_UGLY_NUMBERS_COUNT 1600

int main(){

    set<long long> uglyNumber;
    uglyNumber.insert(1);

    auto p = uglyNumber.begin();
    for (int i = 0; i < 1499; ++i) {
        long long x = *p;
        uglyNumber.insert(2 * x);
        uglyNumber.insert(3 * x);
        uglyNumber.insert(5 * x);
        p++;
    }

    printf("The 1500'th ugly number is %lld.\n",*p);

}
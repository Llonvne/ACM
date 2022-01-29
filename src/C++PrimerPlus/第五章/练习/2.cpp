// array count !
#include "bits/stdc++.h"
using namespace std;
int main(){


    array<long double,16> fact{1,1};
    for (int i = 2; i < fact.size(); i++)
    {
        fact[i] = i * fact[i-1];
    }

    cout << setprecision(16);
    for (const long double& i : fact){
        cout << i << endl;
    }
    return 0;
}
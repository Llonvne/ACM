#include "bits/stdc++.h"
using namespace std;

const int down = -100;
const int up = 100;

struct fx{
    int a,b,c,d;

    int operator()(const int x) const {
        // 实现大的数字优先级低
        return a * pow(x,3) + b * pow(x,2) + c * x + d;
    }




};

int main(){
    fx f;
    cin >> f.a >> f.b >> f.c >> f.d;

    for (int i = down; i < up; i++) {

        int r[2] = {
                f(i),f(i+1)
        };

        if (r[0] * r[1] > 0){
            continue;
        }
        if (r[0] * r[1] == 0){
            if (r[0] == 0) {
                cout << i;
            }
            if(r[1] == 0){
                cout << i+1;
            }

            continue;
        }

        cout << find

    }


}
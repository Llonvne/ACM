#include "bits/stdc++.h"
using namespace std;

const int MAXN = 30;
int n;
vector<int> pile[MAXN];

// 使用引用来回传参数
void find_block(int a,int& p,int& h){
    for (p = 0; p < n ; p++){
        for (int h = 0; h < pile[p].size(); h++){
            if (pile[p][h] == a){
                return;
            }
        }
    }
}

void clear_above(int p,int h){
    for (int i = h+1; i < pile[p].size(); ++i) {
        int b = pile[p][i];
        pile[p].push_back(b);
    }
    pile[p].resize(h+1);
}

void pile_onto(int p)

int main(){

}

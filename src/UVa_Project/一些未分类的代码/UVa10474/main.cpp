#include "bits/stdc++.h"
using namespace std;

int main(){
    int N,Q;
    int caseCount = 1;
    int first = 1;
    while(scanf("%d %d",&N,&Q) && N && Q){

        if (first){
            printf("CASE# %d:",caseCount++);
            first = 0;
        }else {
            printf("\nCASE# %d:",caseCount++);
        }

        vector<int> stone;

        for (int i = 0; i < N; ++i) {
            int buffer;
            scanf("%d",&buffer);
            stone.push_back(buffer);
        }

        sort(stone.begin(),stone.end());

        for (int i = 0; i < Q;i++){
            int nowQ;
            scanf("%d",&nowQ);
            int point = lower_bound(stone.begin(),stone.end(),nowQ) - stone.begin();
            if (stone[point] != nowQ){
                printf("\n%d not found",nowQ);
            }
            else{
                printf("\n%d found at %d",nowQ,point+1);
            }
        }
    }
    printf("\n");
}

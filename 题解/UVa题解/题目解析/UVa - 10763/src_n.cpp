#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    while (~scanf("%d", &N) && N) {
        map<int,int> places;
        int s,d;
        for (int i = 0; i < N; ++i) {
            scanf("%d %d",&s,&d);
            // 有人从学校出发，就 +1
            if (places.find(s) == places.end()) {
                places[s] = 1;
            }
            else {
                places[s] ++;
            }
            // 到达这个学校 -1
            if (places.find(d) == places.end()) {
                places[d] = -1;
            }
            else {
                places[d] --;
            }
        }
        bool isOK = true;
        // 判断每个学校都需求是不是 0
        for (const auto& i : places){
            if (i.second != 0){
                isOK = false;
                break;
            }
        }
        if (isOK){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}
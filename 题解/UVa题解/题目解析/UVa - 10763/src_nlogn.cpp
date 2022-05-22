#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    while (~scanf("%d", &N) && N) {
        // 用两个 Vector 分别存储 source 和 dest
        vector<int> sources;
        vector<int> dests;
        // 分别输入source 和 dest
        for (int i = 0; i < N; ++i) {
            int s,d;
            scanf("%d %d",&s,&d);
            sources.push_back(s);
            dests.push_back(d);
        }
        // 对他们进行排序
        sort(sources.begin(),sources.end());
        sort(dests.begin(),dests.end());
        // 只有需求完全对等，才算成功
        if (sources == dests){
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
}
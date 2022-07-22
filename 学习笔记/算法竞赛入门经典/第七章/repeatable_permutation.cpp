#include "bits/stdc++.h"
using namespace std;
// 生成可重集的排列
void print_permutation(int n,int a[],int p[],int cur)
{
    if(cur==n)
    {
        for(int i=0;i<n;i++){cout<<a[i]<<" ";}
        cout<<endl;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
           if(!i||p[i]!=p[i-1])//防止数组p里面的元素都相同时重复输出
           {
               int c1,c2;
               for(int j=0;j<cur;j++)if(a[j]==p[i])c1++;
               for(int j=0;j<n;j++)if(a[j]==a[i])c2++;
               if(c1<c2)
               {
                   a[cur]=p[i];
                   print_permutation(n, a,p,cur+1);
               }
           }
        }
    }
}
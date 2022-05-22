#include "bits/stdc++.h"
using namespace std;

int main(){

    // 输入数据 创建 set O(nlogn)
    set<string> strings;
    string in;
    while (cin >> in){
        strings.insert(in);
    }
    // 循环每一个 s O(n)
    for (const string & s : strings){
        bool found = false;
        // 循环每一个位从 [1:(size - 1)] -> [(size-1):1] O(size)
        for (int i = 1; i < s.size() - 1 && !found; ++i) {
            // 每次查询耗时 O(logN)
            if (strings.find(s.substr(0,i)) != strings.end() && strings.find(s.substr(i)) != strings.end()){
                found = true;
            }
        }
        if (found){
            printf("%s\n",s.c_str());
        }
    }
    // for -> O(nlogN * size)
    // total O(nlogn) + O(nlogN * size) = O(nlogn * size)
}
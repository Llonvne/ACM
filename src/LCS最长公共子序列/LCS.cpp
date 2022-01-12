// 子序列 不连续但是保持相对次序
// computer -> cute
// 最长公共子序列 Longest Common Subsequence
// 两者序列的公共子序列的长者 一般是找出长度就可以

// LCS 递归 it just Work !
#include <string>
using namespace std;

// 效率比较低下的递归版本
int LCS(string a,string b){
    // 有 空序列 递归基
    if (a.size() == 0 || b.size() == 0) {
        return 0;
    }
    // 最后一个相等 Decrease and Conquer
    if (a[a.size()-1] == b[b.size()-1]) {
        return LCS(a.substr(0,a.size()-1),b.substr(0,b.size()-1)) + 1;
    }
    // 不想等 Divide and Conquer
    else {
        int aloss = LCS(a.substr(0,a.size()-1),b.substr(0,b.size()));
        int bloss = LCS(a.substr(0,a.size()),b.substr(0,b.size()-1));
        return max(aloss,bloss);
    }
}   
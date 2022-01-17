// LCS 递归 it just Work !
// 效率比较低下的递归版本 O(2^N)
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
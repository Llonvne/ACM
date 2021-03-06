// 子序列 不连续但是保持相对次序
// computer -> cute
// 最长公共子序列 Longest Common Subsequence
// 两者序列的公共子序列的长者 一般是找出长度就可以
 
// 迭代版本 O(N*M)
int LCS(const string& a, const string& b){
    int N = (int)a.size();
    int M = (int)b.size();

    // 快速初始化二维码 Vectror数组
    vector<vector<int>> dp(N + 1,vector<int>(M + 1,0));
    int maxLength = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {

            if (a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
                maxLength = max(maxLength, dp[i][j]);
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return maxLength;
}
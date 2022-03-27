//https://leetcode-cn.com/problems/longest-common-prefix/
#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> & strs)
    {
        // 结果数组
        string result = "";
        // 如果只有一个字符串，直接返回
        if (strs.size() == 1){
            return strs[0];
        }
        // 获得字符串数组的最小尺寸
        int minSize = strs[0].size();
        for (int i = 1; i < strs.size(); i++) {
            minSize = min((int)strs[i].size(), minSize);
        }
        for (int i = 0; i < minSize; ++i) {
            // 判断对应位是否相等，不想等立刻返回 result
            for (int j = 0; j < strs.size() - 1; ++j) {
                if (strs[j][i] != strs[j+1][i]){
                    return result;
                }
            }
            // 全部相等将当前位添加到result
            result += strs[0][i];
        }
        // 如果全部相等就返回result，此时已经达到能相等的最大限制也就是minSize
        return result;
    }
};
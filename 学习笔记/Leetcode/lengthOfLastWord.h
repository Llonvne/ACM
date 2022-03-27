// https://leetcode-cn.com/problems/length-of-last-word/submissions/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0){
            return 0;
        }
        int end = (int)s.size()-1;
        // 当 end 是空白符号，end向前走
        while(end >= 0 && isblank(s[end])){
            end--;
        }
        // 判断end是否越界
        if (end == -1){
            return 0;
        }
        // end 是第一个非空白符号元素
        int start = end;
        while (start >= 0 && isalpha(s[start])){
            start--;
        }
        // end 是反向第一个空白元素
        return end - start;
    }
};
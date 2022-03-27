//https://leetcode-cn.com/problems/palindrome-number/
class Solution {
public:
    // 反转一般的数位判断是否想等
    // 偶数位情况
    // 1234 -> reverse = 43 x = 12 不想等不是回文数
    // 1221 -> reverse = 12 x = 12 相等，是回文数
    // 奇数位情况
    // 12534 -> reverse = 435 x = 12 不是回文数
    // 12521 -> reverse = 125 x = 12 reverse / 10 == x 是回文数
    bool isPalindrome(int x)
    {
        // -100 -> 001- 带有符号的绝对不可能是回文数
        // 如果最后一位是 0 如果想要是回文数，只有第一位是0 满足这两个条件只能是 0
        if (x < 0 || (x % 10 == 0 && x != 0)){
            return false;
        }
        int reverse = 0;
        while (reverse < x){    // 当 reverse < x 一定不超过一半
            reverse =reverse * 10 + x % 10; // 将x最后一位移动到revsrse最后一位
            x /= 10;
        }
        // 如果有偶数位，就是相等，如果是奇数位，就是/10相等
        return x == reverse || x == reverse / 10;
    }
};
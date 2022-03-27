//https://leetcode-cn.com/problems/roman-to-integer/
#include "bits/stdc++.h"
using namespace std;
//字符          数值
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
// IV = 4 IX = 9
// XL = 40 XC = 90
// CD = 400 CM = 900;
class Solution
{
public:
    int romanToInt(string s)
    {
        // 建立标准转换表
        map<char, int> romanToValue;
        char romans[] = "IVXLCDM";
        int values[] = {1, 5, 10, 50, 100, 500, 1000};
        for (int i = 0; i < 7; ++i) {
            romanToValue[romans[i]] = values[i];
        }
        // 建立特殊字符转换表
        map<string, int> specialRomanToValue;
        string specialRomans[] = {"IV", "IX", "XL", "XC", "CD", "CM"};
        int specialValues[] = {4, 9, 40, 90, 400, 900};
        for (int i = 0; i < 6; i++) {
            specialRomanToValue[specialRomans[i]] = specialValues[i];
        }
        int total = 0;
        for (int i = 0; i < s.size(); i++) {
            // 判断是否是特殊字符
            if (specialRomanToValue.find( // 去特殊字符库内查找
                s.substr(i,2)) == specialRomanToValue.end() // 未找到就直接用原始值
                )
            {
                total += romanToValue[s[i]];
            }
            else {  // 不然用特殊值
                total += specialRomanToValue[s.substr(i,2)];
                ++i; // 多移动一位
            }
        }
        return total;
    }
};
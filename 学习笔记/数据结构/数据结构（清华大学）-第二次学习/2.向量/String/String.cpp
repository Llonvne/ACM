//
// Created by 华邵钶 on 2022/2/28.
//

#include "String.h"

bool String::operator<(const String & s)
{
    if (empty()) {
        return true;
    }
    for (int i = 0; i < std::min(size(), s.size()); ++i) {
        if (get(i) != s[i]) {
            return get(i) < s[i];
        }
    }
    return size() > s.size();
}

String::String(const char str[])
{
    for (int i = 0; i < strlen(str); ++i) {
        push_back(str[i]);
    }
}

const char * String::c_str()
{
    return data();
}

bool operator<(const String & a, const String & b)
{
    int minSize = std::min(a.size(),b.size());
    for (int i = 0; i < minSize; ++i) { // 对比每一个字符
        if (a[i] != b[i]){  // 如果不相等
            return a[i] < b[i]; // 转换为 a[i] < b[i]
        }
    }
    // 如果前面全部相同，就是长度
    return a.size() < b.size();
}

bool operator==(const String & a, const String & b)
{
    if (a.size() != b.size()) // 长度不想等
    {
        return a.size() < b.size(); // 转换为长度比较
    }
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]){
            return false;
        }
    }
    return true;
}

bool operator>(const String & a, const String & b)
{
    return (!(a < b)) && (a != b); // a 不等于且不小于b
}

bool operator!=(const String & a, const String & b)
{
    return !(a == b);
}

std::ostream & operator<<(std::ostream & os, const String & s)
{
    for (int i = 0; i < s.size(); ++i) {
        os << s[i];
    }
    return os;
}

std::istream & operator>>(std::istream & input, String & s)
{
    char c;
    while (true){
        c = (char)input.get();
        if (!std::isspace(c)){
            s.push_back(c);
        }
        else {
            break;
        }
    }
    return input;
}

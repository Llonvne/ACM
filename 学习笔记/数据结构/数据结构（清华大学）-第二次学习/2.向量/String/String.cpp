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

String::String(const char * str)
{
    resize((int) std::strlen(str));
    memcpy(data(), str, size());
}

const char * String::c_str()
{

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

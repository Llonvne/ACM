// cctypes.cpp -- using the ctypes.h library
#include <cctype>
#include <iostream>

int main(int argc, char* argv[]){
    using namespace std;

    cout << "Enter text for analysis and type @ to terminate input \n";
    char ch;
    cin >> ch;

    int whitespace = 0;
    int digit = 0;
    int chars = 0;
    int puncts = 0;
    int others = 0;

    cin.get(ch);
    while (ch != '@')
    {
        if (isalpha(ch))
        {
            chars++;
        }
        else if (isspace(ch)){
            whitespace++;
        }
        else if (isdigit(ch)){
            digit++;
        }
        else if (ispunct(ch)){
            puncts++;
        }
        else {
            others++;
        }
        
        cin.get(ch);
    }

    cout << chars << " chars, " << whitespace << " whitespace, " << digit << " digits, " << puncts << " puncts, " << others << " others\n";

    // 大小写转换 注意是 int 返回需要强制转换
    cout << (char)toupper('a') << endl;
    cout << (char)toupper('A') << endl;
    cout << (char)tolower('a') << endl;
    cout << (char)tolower('A') << endl;

    // isupper islower 是判断
    // isspace 可以判断回车 空格 制表符 等等等 是判断标准空白字符
    // isprint 判断是否是可打印字符
    // isgraph 排除空格外等可打印字符
    // isalnum 是否是数字或者字符 alpha <-> number ==> alnum
    // isdigit 判断数字
    // isalpha 判断字母

}

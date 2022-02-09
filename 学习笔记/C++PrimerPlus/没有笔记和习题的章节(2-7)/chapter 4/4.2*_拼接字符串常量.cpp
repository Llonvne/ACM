// string.cpp -- storing strings in an array
#include <iostream>
#include <cstring>

int main(){
    using namespace std;
    const int Size = 15;
    
    // 使用 空格或者回车来连接两个字符串常量 使用+来连接一个字符串加一个字符 
    char a[] = "1234567" "890";
    // equal to "1234567890"
    cout << "1234567" "890"[2];
    // ouput = 3

    char b[] = "1234567" "890";
    cout << "1234567" + '1';
}

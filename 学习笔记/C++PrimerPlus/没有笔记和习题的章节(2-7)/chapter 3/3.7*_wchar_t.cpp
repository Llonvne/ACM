// wchar_t.cpp -- wchar
#include <iostream>
using namespace std;

int main(){
    wchar_t a = L'a'; // 使用 大写 L 前缀表示 宽字符
    // char b = L"b"; 无法赋值
    char b = 'b';
    wcout << a << endl;
    wcout << b << endl; 

    cout << sizeof(wchar_t) << endl << sizeof(char) << endl; // 4 1
    // cout << a; 需要使用宽字符流 wcout 会输出错误！

}
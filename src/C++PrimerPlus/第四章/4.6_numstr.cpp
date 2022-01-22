// numstr.cpp -- following number input with line input;
#include <iostream>
int main(){
    using namespace std;

    cout << "What was your house built?\n";
    int year;
    cin >> year; // 输入时候多出一个 \n 留在缓冲区

    cout << "What is its address?\n";
    char address[80];
    // getline 一开始读到回车符号 以为是空
    // 如果 get 不被注释程序即正常
    cin./*get().*/getline(address, 80);

    cout << "Year built : " << year << endl;
    cout << "Address : " << address << endl;
    cout << "Done!" << endl;

    return 0;
}
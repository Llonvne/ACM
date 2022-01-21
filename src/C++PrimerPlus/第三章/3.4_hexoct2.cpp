// hexoct2.cpp -- display value in hex and octal
#include <iostream>

int main(){
    using namespace std;
    int chest = 42; // decimal integer literal
    int waist =  0x42; // hexadecimal integer literal
    int inseam = 042; // octal integer literal

    // 类似于 hex dec oct 都是 cout的格式控制符号，默认是十进制，一次更改后会保留直至下次更改

    cout << "Monsieur cuts a striking figure" << endl;
    cout << "chest = " << chest << "(42 in decimal)\n";
    cout << hex;
    cout << "waist = " << waist << "(42 in hexadecimal)\n";
    cout << oct;
    cout << "inseam = " << inseam << "(42 in octal)\n";
    

    return 0;
}
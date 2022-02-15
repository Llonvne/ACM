// strtype4.cpp -- line input
#include <string>
#include <cstring>
#include <iostream>

int main(){
    using namespace std;

    char charr[20];
    string str;

    cout << "Length of char array before input : " << strlen(charr) ;
    cout << endl << "Length of string object before input :" << str.length()
    << endl;

    cout << "Enter a line with text: " ;
    cin.getline(charr,20);
    cout << "You entered : " << charr << endl;
    cout << "Enter another line with text: " ;
    getline(cin,str); // cin 变成了参数，不需要长度控制符号
    cout << "You entered : " << str << endl;

    cout << "Length of char array after input : " << strlen(charr) ;
    cout << endl << "Length of string object after input :" << str.length()
    << endl;
}
// instr3.cpp -- reading more than one word with get() & get()
#include <iostream>
int main(){
    using namespace std;
    const int Arsize = 20;
    char name[Arsize];
    char dessert[Arsize];

    cout << "Enter your name:\n";
    // 第一个get读取 name 长度为 Arsize 第二个get没有参数与 getchar()作用一样
    cin.get(name,Arsize).get();
    cout << "Enter your favorite dessert:\n";
    //getline(data,length);
    cin.get(dessert,Arsize).get();

    // getline 会将行尾部回车用一个回车符号忽略，而get方法必须手动忽略

    cout << "I have some delicious " << dessert;
    cout << " for you " << name << ".\n";
    return 0;
}
// ptrstr.cpp -- using pointers to strings
#include <iostream>
#include <cstring>
int main(){
    using namespace std;
    char animal[20] = "bear";
    // const 修饰 char 将会保证 字符串内容不被改变
    const char * bird = "wren";
    char * ps;

    cout << animal << " and " << bird << endl;
    // cout << ps; display garbage or cause a crash

    cout << "Enter a kind of animal: ";
    cin >> animal;
    // cin >> ps; ps is not allocated space;

    ps = animal;
    cout << "ps = " << ps << endl;
    cout << "before use strcpy():\n";
    cout << (int*)(animal) << endl;
    cout << (int*)(ps) << endl;

    ps = new char[strlen(animal) + 1];
    strcpy(ps, animal);
    cout << "after use strcpy():\n";
    cout << (int*)(animal) << endl;
    cout << (int*)(ps) << endl;
    delete[] ps;
    return 0;
}
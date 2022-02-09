// pointer.cpp -- our first pointer variable
#include <iostream>
int main(){
    using namespace std;
    int updates = 6;
    int  * p_updates;
    p_updates = &updates;

    // express value in two ways;
    cout << updates << endl;
    cout << *p_updates << endl;

    // express address in two ways
    cout << &updates << endl;
    cout << p_updates << endl;

    // use pointer to change value;
    *p_updates = *p_updates + 1;
    cout << updates << endl;

    // 对于指针使用解引用就相当于直接操作被指向的变量
    cout << &*p_updates << endl;

}
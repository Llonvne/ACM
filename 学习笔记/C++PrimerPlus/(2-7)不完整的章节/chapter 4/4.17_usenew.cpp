// usenew.cpp -- using the new operator
#include <iostream>
int main(){
    using namespace std;
    int nights = 1001;
    int * pt = new int; // 使用 new 来为指针分配空间
    *pt = 1001;

    // 部分提示信息有删减
    cout << nights << " " << &nights << endl;
    cout << *pt << " " << pt << endl;

    double * pd = new double;
    *pd = 100000001.0;

    cout << *pd << " " << pd << endl;
    cout << "location of pd = " << &pd << endl;

    cout << "size of pd" << sizeof pd;
    cout << endl << "size of pt" << sizeof pt;
    cout << endl;

    return 0;
}
// typecast.cpp --  forcing type change
#include <iostream>
int main()
{
    using namespace std;
    int auks,bats,coots;

    // the following statement adds the values as double
    // then convert the result to int
    auks = 19.99 + 11.99;
    // floor(19.99 + 11.99) = 31

    // the following statement adds the values as int;
    // result will directly assign to int;
    bats = (int) 19.99 + (int) 11.99 ; // old C syntax
    coots = int(19.99) + int(11.99); // new C++ syntax 
    // C++希望强制希望类似于调用函数,实际上这也更好使得语法更加统一。
    cout << "auks:" << auks << endl;
    cout << "bats" << bats << endl;
    cout << "coots:" << coots << endl;

    char ch = 'z';
    cout << "the code for " << ch << " is " << int(ch) << endl;
    // static_cast<typename> 将对强制转化的精度做更加严格的检查
    cout << "Yes,the code is " << static_cast<int>(ch) << endl;

    return 0;
}
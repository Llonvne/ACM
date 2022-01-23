// addpntrs.cpp - pointer addition
#include <iostream>
int main(){
    using namespace std;
    double wags[3] = {10000.0,20000.0,30000.0};
    short stacks[100] = {3,2,1};

    // get address of array;
    double * pw = wags; // 数组名字 = 首地址
    short * ps = &stacks[0]; // stacks == &stack[0];

    cout << "pw = " << pw << endl;
    cout << "*pw = " << *pw << endl;

    pw = pw + 1;
    cout << "pw = pw + 1; "<< endl;
    cout << "Now pw = " << pw << endl;
    cout << "Now *pw = " << *pw << endl;


    ps = ps + 1;
    cout << "ps = ps + 1; "<< endl;
    cout << "Now ps = " << ps << endl;
    cout << "Now *ps = " << *ps << endl;

    //assess two element
    cout << "stack[1] = " << stacks[1] << endl;
    cout << "*(stacks + 1) = " << *(stacks + 1) << endl;

    // size of array and point
    cout << sizeof wags << endl;
    cout << sizeof pw << endl;

    return 0;
}
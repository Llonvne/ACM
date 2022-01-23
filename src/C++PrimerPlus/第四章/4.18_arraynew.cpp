// arraynew.cpp -- using the new operator for array;
#include <iostream>
int main(){
    using namespace std;
    double * p3 = new double[3];
    p3[0] = 0.2;
    p3[1] = 0.3;
    p3[2] = 0.7;
    cout << "p3[0] = " << p3[0] << endl; // 注意此处不需要解引用符号
    // 或者说 解引用符号被[]替代

    // 这里点出了数组和指针区别，数组名是不修改的，而作为指针数组可以修改开头元素
    p3 = p3 + 1;


    cout << "Now p3[0] = " << p3[0];

    // 删除的时候需要把数组回到开头 否则将不能给 delete 提供正确的地址
    p3 = p3 - 1;
    delete [] p3;

    return 0;
}
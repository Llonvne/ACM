// divide.cpp -- integer and floating point divide
#include <iostream>
int main(){
    using namespace std;
    cout.setf(ios_base::fixed,ios_base::floatfield);
    cout << "Integer Division : 9/5 = " << 9/5 << endl;
    cout << "Floating-point Divide : 9.0/5.0 = " << 9.0/5.0 << endl;

    cout << "Mixed Divide 9/5.0 or 9.0/5 = " << 9/5.0 << endl;
    cout << "double constants: 1e7/9.0 = " << 1e7/9.0 << endl;
    cout << "float constants: 1e7f/9.0 = " << 1e7f/9.0f << endl;

    cout << typeid(9.0).name() << endl; // * 浮点字面量默认是double
    return 0;
}
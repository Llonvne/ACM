// floatnum.cpp -- floating-point types;
#include <iostream>
int main(){
    using namespace std;
    // 定点表示法
    cout.setf(ios_base::fixed,ios_base::floatfield);
    float tub = 10.0/3.0; //good to about 6 place;
    double mint = 10.0/3.0; //good to about 15 place;
    const float million = 1.0e6;

    cout << "tub = " << tub;
    cout << " a million of tubs = " << million * tub;
    cout << "\nand ten million tubs = " << 10 * million * tub << endl;

    cout << "mint = " << tub;
    cout << " a million of mint = " << million * mint;
    cout << "\nand ten million mint = " << 10 * million * mint << endl;

    return 0;
}
// assign.cpp -- type change on initialization
#include <iostream>
int main(){
    using namespace std;
    // 设置精度
    cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    float tree = 3; // int convert to float
    int guess(3.9832); // double convert to int;
    int debt = 7.2E12; // this double numbern is too big 
    // that will cause the int number is undefined

    cout << "tree :" << tree << endl;
    cout << " guess :" << guess << endl;
    cout << "debt :" << debt << endl;
}
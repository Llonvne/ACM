// assign.cpp -- type change on initialization
#include <iostream>
int main(){
    using namespace std;
    // 设置精度
    cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    float tree{3}; // int convert to float
    // 使用 {} 进行初始化的时候将不会允许丢失精度！！！
    // 所以下面的语句将会无法通过编译！
    int guess{3.9832}; // double convert to int;
    int debt{7.2E12}; // this double numbern is too big 
    // that will cause the int number is undefined

    cout << "tree :" << tree << endl;
    cout << " guess :" << guess << endl;
    cout << "debt :" << debt << endl;
}

// Notice 在 C++ 中 如果一个是 float 一个是 int 会将 int -> float 这与 C 语言不同
// C 语言总会将表达式都转换为 Double 在进行计算.
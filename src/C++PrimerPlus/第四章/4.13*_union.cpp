// union.cpp -- 共用体
// 能够存储不同的类型，但是同时只能存储一种
union number {
    int int_val;
    long long_val;
    float float_val;
    double double_val;
};

// 当然也可以创造匿名共用体
// 使用方法如下
struct Good {
    char name[20];
    bool isDouble = false;

    // 共用体 可以完全不需要名字，此时可以直接访问 d_price i_price 
    // 但是显然只有一个是其成员
    // 而且两者地址相同

    union {
        double d_price;
        int i_price;
    };
};

#include <iostream>

int main(){
    using namespace std;
    number n;
    // 给 int 赋值
    n.int_val = 1;
    // 正常输出 int
    cout << n.int_val << endl;;
    // 给 double 赋值 ，int丢失
    n.double_val = 1.01;
    // 正常输出 double
    cout << n.double_val << endl;
    // int 为错误
    cout << n.int_val << endl;

    Good banana;
    banana.isDouble = true;
    // 两者地址完全相同
    cout << &banana.d_price << " " << &banana.i_price << endl;
    
}


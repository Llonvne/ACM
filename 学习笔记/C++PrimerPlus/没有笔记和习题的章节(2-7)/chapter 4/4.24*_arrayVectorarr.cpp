#include <array>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    // 声明C风格数组
    // typename arrayname[arraysize];
    int C_Array[100];

    // C++ 数组模版类 因为不涉及动态内存分配，速度与C风格数组基本一致
    // array<typename,size> arrayname
    // 还有一些简单的成员函数可以使用 更加推荐！！
    array<int,100> Cpp_Array;

    // C++ 向量模版类
    // vector<typename> arrayname; 
    vector<int> Cpp_Vector;
}
// 3.4* -- 使用后缀来表明类型
// 注意如果不是原书给出的代码将会在文件号中标注 *

#include <iostream>
using namespace std;

int main(){
    cout << typeid(1).name();
    cout << endl;
    cout << typeid(1L).name(); // 后面跟L 表示 long型
    cout << endl;
    cout << typeid(1UL).name(); // U 表示 unsigned  字母不分顺序 UL LU 等价
    cout << endl;
}
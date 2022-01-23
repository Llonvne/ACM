// enum.cpp -- 枚举
enum spectrum {red,orange,yellow,green,blue,violet,indigo,ultraviolet};
// 声明 spectrum 为新的类型 让 red orange 成为新的符号变量 对应 0～7

#include <iostream>
using namespace std;

int main(){
    spectrum myLove = red;

    // 枚举类型可以按照 0～7转换为int 类型
    cout << int(myLove) << endl;

    // int 类型不可以转换为 枚举类型
    //myLove = 0;

    enum {red = 1,orange = 2,yellow = 3};
    cout << red << endl;
}
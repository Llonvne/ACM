// C++ 允许你用如下方式定义 raw 文本 在该文本中不存在转义字符 字符就是字符
#include <iostream>
using namespace std;

// 使用 R"( 开头 使用 )" 结束 
// 如果需要使用类似于 )"  这样的文本在里面，请在 开头结束的 括号和引号中间插入一些字母来表示
int main(){
    cout << R"( I am Row!!!!!!!!)()());"""""  int """""""  )";

    cout << R"RAWSIGNAL(
#include <iostream>
using namespace std;
int main() {
    cout << R"(I am a raw )"; // this is RAW test
    return 0;
}
    )RAWSIGNAL";
}
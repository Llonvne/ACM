#include <stack>
using namespace std;

#define SOURCE // 标识汉诺塔源
#define TARGET // 标识汉诺塔目标
#define BUFFER // 汉诺塔缓存
void Hanoi(stack<int>& SOURCE A,stack<int>& BUFFER B,stack<int>& TARGET C,int problemSize){
    if (problemSize > 0){
        // 将 A 上面的 n-1层移动到 B
        Hanoi(SOURCE A,BUFFER C,TARGET B,problemSize-1);
        // 移动第 n 层
        C.push(A.top());
        A.pop();
        // 将 B 上面的 n-1层移动会A
        Hanoi(SOURCE B,BUFFER A,TARGET C,problemSize-1);
    }
}
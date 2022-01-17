#include <stack>
using namespace std;

// 汉诺塔问题解决 O(2^N)
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
        // 将 B 上面的 n-1层移动到 C
        Hanoi(SOURCE B,BUFFER A,TARGET C,problemSize-1);
    }
}

/*
 * 不难发现当只有一个盘子的时候复杂度为 O(1)
 * 每次递归都会产生两个新问题但是问题规模都减少了 1
 * 递推式子为 T(n) = 2 * T(n-1) + O(1)
 * 不难算出 T(n) = O(2^n)
*/
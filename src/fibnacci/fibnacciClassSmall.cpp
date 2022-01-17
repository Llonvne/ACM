// Fibnacci 类，本类为了方便内敛使用，减少了缩进
class Fibnacci{
    int f,g;
public:
    // 构造方法 初始化不小于n的fibnacci数列
    Fibnacci(int n){ f = 1;g = 0; while (g < n) next(); }
    // 下一项
    int next() { g += f; f = g-f; return g; }
    // 获得当前项
    int get(){ return g;}
    // 前一项
    int prev() { f = g -f; g -= f; return g; }
};
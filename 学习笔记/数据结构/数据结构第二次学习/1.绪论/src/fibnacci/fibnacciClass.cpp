/*
使用方法： 初始化： fib(target) 会自动迭代到target // O(N)
获取当前fib值 fib.get() // O(1)
向前迭代一项 fib.prev() // O(1)
向后迭代一项 fib.next() // O(1)
*/
class Fib{
// _prev 记录当前项（_hot）的前一项，_hot为当前项
    int _prev,_hot;
public:
    // 初始化
    Fib(int target){
        // 初始化Fibnacci 函数前两项
        _prev = 0;
        _hot = 1;
        // 当当前项小于目标值，不断向前迭代
        while(get() < target){
            next();
        }
    }
    // 返回当前项
    int get(){
        return _hot;
    }
    // 迭代到下一项返回
    int next(){
        // 生成下一项
        int newHot = _hot + _prev;

        _prev = _hot;
        _hot = newHot;

        return get();
    }
    // 往前回退一项
    int prev(){
        // 退回前面一项
        int prev_prev = _hot - _prev;

        _hot = _prev;
        _prev = prev_prev;

        return get();
    }
};
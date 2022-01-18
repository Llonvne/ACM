// Point 类
class Point{
private:
    int xval;
    int yval;
public:
    Point() : xval(0),yval(0){};
    Point(const int x,const int y): xval(x),yval(y){};
    
    int x() const {
        return xval;
    }
    int y() const {
        return yval;
    }
    
    Point x(const int x){
        xval = x;
        return *this;
    }
    Point y(const int y){
        yval = y;
        return *this;
    }
};
// 抽象引用计数
class UseCount{
public:
    // 构造和解析
    UseCount() : p(new int(1)) {};
    // 两者指向相同的计数器 需要使得计数器自增1
    UseCount(const UseCount& u):p(u.p){
        ++(*p);
    };
    ~UseCount(){
        if (-- (*p) == 0) {
            delete p;
        }
    }
    // 确认这个计数器是否唯一
    bool only(){
        return *p == 1;
    }
    // = 赋值
    bool reattach(const UseCount& u){
        ++ *u.p;
        // 如果该计数器唯一
        if (-- *p == 0)
        {
            // 删除该计数器
            delete p;
            // 替换为赋值过来的计数器
            p = u.p;
            return true;
        }
        // 不唯一 则直接更改
        p = u.p;
        return false;
    }
    // 
    bool makeOnly(){
        // 本身就唯一
        if (*p == 1)
        {
            return false;
        }
        -- *p;
        p = new int(1);
        return true;
    }
private:
    // 计数变量
    int * p;
    // 私有化 = 来禁止复制
    UseCount & operator=(const UseCount&);
};
class Handle {
public:
    // 构造函数
    Handle() : p(new Point){};
    Handle(const int x,const int y) : p(new Point(x,y)){};
    Handle(const Point& p0) : p(new Point(p0)){};
    Handle(const Handle& h) : u(h.u) , p(h.p){};
    // 析构函数
    ~Handle(){
        if (u.only()){
            delete p;
        }
    };
    // 赋值
    Handle& operator= (const Handle& h){
        if (u.reattach(h.u))
        {
            // 返回true表示 最后一个计数器消失，此时需要从内存中删除p
            delete p;
        }
        p = h.p;
        return *this;
    }

    // 成员操作函数
    int x() const {
        return p->x();
    }
    Handle& x(const int x0){
        if (u.makeOnly())
        {
            p = new Point(*p);
        }
        p -> x(x0);
        return *this;
    }
    int y() const ;
    Handle& y(const int y);
private:
    Point * p;
    // 初始化计数器
    UseCount u;
};

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
// Handle 类
class Handle {
public:
    // 构造函数
    Handle();
    Handle(const int x,const int y);
    Handle(const Point& p0);
    Handle(const Handle& h);
    // 析构函数
    ~Handle();
    // 赋值
    Handle& operator= (const Handle& h);

    // 成员操作函数
    int x() const;
    Handle& x(const int x);
    int y() const ;
    Handle& y(const int y);
private:
};

// 抽象引用计数
class UseCount{
public:
    // 构造和解析
    UseCount();
    UseCount(const UseCount&);
    UseCount operator=(const UseCount&);
    ~UseCount();
    
private:
    // 计数变量
    int * p;
};

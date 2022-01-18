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
class Handle {
public:
    // 构造函数
    Handle():u(new int(1)),p(new Point){};
    Handle(const int x,const int y):u(new int(1)),p(new Point(x,y)){};
    Handle(const Point& p0):u(new int(1)),p(new Point(p0)){};
    Handle(const Handle& h):u(h.u),p(h.p){
        ++(*u);
    };
    // 析构函数
    ~Handle() {
        if (-- (*u) == 0) {
            delete p;
            delete u;
        }
    };
    // 赋值
    Handle& operator= (const Handle& h){
        ++(*u);
        if (-- (*u) == 0) {
            delete u;
            delete p;
        }
        u = h.u;
        p = h.p;
        return *this;
    }

    // 成员操作函数
    int x() const;
    Handle& x(const int x);
    int y() const ;
    Handle& y(const int y);
private:
    // 点
    Point * p;
    // 计数
    int * u;
};

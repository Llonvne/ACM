// 在 UPoint 内部建立 变量用于句柄计数
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
// 实现操作切完全私有的UPoint类
class UPoint{
private:
    // 设置handle 为友元类
    friend class Handle;
    
    Point p;
    // 计数器
    int u;
    
    UPoint() : u(1) {};
    UPoint(const int x,const int y) : p(x,y), u(1){};
    UPoint(const Point& p0) : p(p0), u(1) {};
    
    int x() const {
        return p.x();
    }
    int y() const {
        return p.y();
    }
    
    UPoint x(const int x){
        p.x(x);
        return *this;
    }
    UPoint y(const int y){
        p.y(y);
        return *this;
    }
};
// 句柄类 
class Handle {
private:
    
    UPoint & copy(const UPoint & u0){
        UPoint * up = new UPoint(u0);
        return *up;
    }
    
public:
    Handle(): up(new UPoint){};
    Handle(const int x,const int y) : up (new UPoint( x, y) ) {};
    Handle(const Point& p) : up(new UPoint(p) ){};
    Handle(const Handle& h) : up(h.up){
        ++(up->u);
    }
    Handle& operator= (const Handle& h){
        // 参数计数器增加
        ++(h.up->u);
        // 自己的计数器减少并检查是否需要删除
        if (--up->u == 0) {
            delete up;
        }
        up = h.up;
        return *this;
    }
    ~Handle() {
        // 计数器归零则删除up
        if (--up->u == 0) {
            delete up;
        }
    };
    
    int x() const {
        return up->x();
    }
    Handle& x(const int x) {
        up->x(x);
        return *this;
    }
    int y() const {
        return up->y();
    }
    Handle& y(const int y){
        up->y(y);
        return *this;
    }
    
private:
    UPoint * up;
};
#include <iostream>
using namespace std;

struct point{
    int x;
    int y;

    // 构造函数
    point(int x, int y):x(x),y(y) {};
};
template<typename T>
struct superPoint{
    string name;
    T x{},y{};
};
template<typename T>
ostream& operator<<(ostream& out, const superPoint<T>& x){
    out << "该点的横坐标为" << x.x << endl << "该点的纵坐标为" << x.y << endl;
    return out ;
}

template<typename T>
T swap2(T& a,T& b){
    T t= a;a = b;b = t;
}

int main() {
    point p(2,4);
    //cout << p;
    /*
    int a = 1,b = 2;
    swap2<int>(a,b);
    cout << a << " " << b << endl;
    return 0;
    */

    superPoint<int> a;
    a.x = 2;
    a.y = 1;
    cout << a;

    superPoint<string> b;
    b.x = "**";
    b.y = "dna";
    cout << b;




}

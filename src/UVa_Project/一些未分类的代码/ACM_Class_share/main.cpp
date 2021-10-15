#include "bits/stdc++.h"
using namespace std;

struct point{
    int x;
    int y;
    double distance;
};

void culcalateDiameters(point& p){
    p.distance = (double)((int)pow(p.x,2) + (int)pow(p.y,2));
    p.distance = sqrt(p.distance);
}
bool cmp(point a,point b){
    return a.distance < b.distance;
}
int main(){

    point p[20];

    for (int i = 0; i < 5; ++i) {
        cin >> p[i].x >> p[i].y ;
        culcalateDiameters(p[i]);
    }

    sort(p, p+5,cmp);

    for (int i = 0; i < 5; ++i) {
        cout << p[i].x << " " << p[i].y << " "<< p[i].distance << endl;
    }

}
#include <iostream>
using namespace std;

int main(){
    int x,y;
    cout << "Enter two numbers to calculate the harmonic mean." << endl;
    while(cin >> x >> y && x != 0 && y != 0){
        cout << "x: " << x << " y: " << y << endl;
        cout << "The harmonic mean is " << 2.0 * x * y / (x + y) << endl;
        cout << "Enter two numbers to calculate the harmonic mean." << endl;
    }
    return 0;
}
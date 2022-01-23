#include <array>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    array<int,100> a;
    cin >> a[0];
    cin >> a[1];
    cout << a[0] << endl;
    cout << a.max_size() << endl;
    cout << a.size();
}
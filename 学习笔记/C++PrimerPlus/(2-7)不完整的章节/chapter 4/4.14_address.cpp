// address.cpp -- using the & operator to find address
#include <iostream>
int main(){
    using namespace std;
    int donuts = 6;
    double cups = 6;

    cout << "donuts value = " << donuts ;
    cout << " and donuts address = " << &donuts << endl;

    cout << "cup value = " << cups;
    cout << " and cup value = " << &cups << endl;

    return 0;
}
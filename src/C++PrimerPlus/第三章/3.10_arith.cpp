// arith.cpp -- some C++ arithmetic
#include <iostream>
int main(){
    using namespace std;
    float hats,heads;

    cout.setf(ios_base::fixed,ios_base::floatfield);
    cout << "Enter a number" << endl;
    cin >> hats;
    cout << "Enter another number" << endl;
    cin >> heads;

    cout << "hats = " << hats << " heads = " << heads << endl;
    cout << "hats + heads = " << hats + heads << endl; 
    cout << "hats - heads = " << hats - heads << endl; 
    cout << "hats * heads = " << hats * heads << endl; 
    cout << "hats / heads = " << hats / heads << endl; 
    return 0;
}
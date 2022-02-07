#include <iostream>
using namespace std;

long long factorial_recursion(int x);

int main(){
    int x;
    cout << "Please enter number to factorial" << endl;
    while (cin >> x){
        if (x < 0){
            cout << "Negative numbers do not have factorials!" << endl;
            continue;
        }
        else if (x >= 20)
        {
            cout << "Number is out of range!" << endl;
            continue;
        }
        cout << "factorials(" << x << ") = " <<factorial_recursion(x) << endl;
        cout << "Please enter number to factorial" << endl;
    }
    if (!cin.good())
    {
        cout << "Program terminated for invalid input!" << endl;
    }
    
    return 0;
}

long long factorial_recursion(int x){
    if (x == 0)
    {
        return 1;
    }
    return x * factorial_recursion(x - 1);
}
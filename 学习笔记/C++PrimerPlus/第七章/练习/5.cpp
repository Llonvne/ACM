#include <iostream>
using namespace std;

int factorial_recursion(int x);

int main(){
    cout << factorial_recursion(10) << endl;
    return 1;
}

int factorial_recursion(int x){
    if (x == 0)
    {
        return 1;
    }
    return x * factorial_recursion(x - 1);
}
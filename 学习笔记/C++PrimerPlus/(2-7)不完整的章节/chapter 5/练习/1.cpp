// sum range of [a,b] a<b
#include <iostream>
int main(){
    using namespace std;
    // input a , b and a < b;
    int a,b;
    cin >> a >> b;

    int sum = 0;
    for (int i = a; i <= b; i++)
    {
        sum += i;
    }

    printf("The sum of range [%d,%d] is %d.\n",a,b,sum);

    return 0;
}
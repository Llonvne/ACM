// count input
#include <iostream>
using namespace std;
int main(){
    int now;
    int sum;
    while (cin >> now && now != 0){
        sum += now;
        cout << "Total :" << sum << endl;;
    }
    cout << "Total :" << sum << endl;
    return 0;
}
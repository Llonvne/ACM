#include <iostream>
using namespace std;

int main(){
    int golfs[10];
    double sum = 0;
    int golfsCount = 0;
    while (golfsCount < 10 && cin >> golfs[golfsCount]){
        sum += double(golfs[golfsCount]);
        golfsCount++;
    }

    for (int i = 0; i < golfsCount; i++)
    {
        cout << golfs[i] << " ";
    }
    cout << endl;
    cout << "Golfs count : " << golfsCount << endl;
    cout << "Summed score : " << sum << endl;
    cout << "Average : " << sum / golfsCount << endl;
    
    return 0;
}
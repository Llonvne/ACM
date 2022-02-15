// cinfish.cpp -- non-numeric input terminates loop
#include <iostream>
const int MAX = 5;
int main(){
    using namespace std;
    double fish[MAX];

    cout << "Please enter weights of your fish.\n";
    cout << "You may enter up to " << MAX << " fish <q to terminate>.\n";
    cout << "fish #1: ";

    int i = 0;
    while (i < MAX && cin >> fish[i]){
        if (++i < MAX)
        {
            cout << "fish #" << i+1 << ": ";

        }
    }

    double total = 0.0;
    for (int j = 0; j < i; j++)
    {
        total +=fish[j];
    }
    
    if (i == 0) 
    {
        cout << "No fish\n";
    }
    else {
        cout << total / i << " = average weight of " << i << " fish.\n";
    }
    cout << "Done!\n";
    return 0;
}
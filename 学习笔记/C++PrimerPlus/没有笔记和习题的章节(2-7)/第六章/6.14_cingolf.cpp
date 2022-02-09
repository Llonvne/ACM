// cingolf.cpp -- non-numeric input skiped;
#include <iostream>
const int MAX = 5;
int main(){
    using namespace std;
    double golf[MAX];
    cout << "Please enter your golf scores.\n";
    cout << "You must enter " << MAX << " rounds.\n";

    for (int i = 0; i < MAX; i++)
    {
        cout << "round #" << i+1 << ": ";
        while (!(cin >> golf[i])){
            cin.clear(); // reset input
            while (cin.get() != '\n'); // get rid of bad input
            cout << "Please enter a number: ";
        }
    }

    double total = 0.0;
    for (int j = 0; j < MAX; j++)
    {
        total +=golf[j];
    }

    cout << total / MAX << " = average score " << MAX << " round(s)\n";
    return 0;
}
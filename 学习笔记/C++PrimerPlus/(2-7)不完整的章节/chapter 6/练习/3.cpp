#include <iostream>
using namespace std;

char mainMenu[] = 
R"(Please enter of the following choices:
c) carnivore p) pianist
t) tree g) game)";

int main()
{
    cout << mainMenu << endl;
    char ch = cin.get();
    switch (ch){
        case 'c': cout << "the lion is a carnivore" << endl; break;
        case 'p': cout << "Beethoven was a pianist" << endl; break;
        case 't': cout << "A maple is a tree" << endl; break;
        case 'g': cout << "Red Alert is a game" << endl; break;
    }
    return 0;
}
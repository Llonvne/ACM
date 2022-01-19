// ourfunc.cpp -- define our own function
#include <iostream>

void simon(int); // function prototype for simon

int main(){
    using namespace std;
    simon(3); // call the simon function
    cout << "Pick a integer: ";
    int count;
    cin >> count;
    simon(count); // call simon again
    cout << "Done!" << endl;
    return 0;
}

void simon(int count){
    using namespace std;
    cout << "Simon says touch your toes " << count << " times." << endl;
} // void function don't need return statement
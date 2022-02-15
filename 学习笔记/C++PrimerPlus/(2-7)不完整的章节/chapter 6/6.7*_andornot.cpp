// and or not 
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    cout << not false << endl; // not == !

    cout << (true and true) << endl; // and == &&
    cout << (true and false) << endl;

    cout << (true or false) << endl; // or == ||
    cout << (false or false) << endl;
}
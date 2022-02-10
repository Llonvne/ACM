#include <string>
#include <iostream>
using namespace std;
void stringTopper(string & e){
    for (char & i : e){
        i = toupper(i);
    }
}

int main() {
    string e;
    cout << "Enter a string:";
    while (getline(cin,e)){
        stringTopper(e);
        cout << e;
        cout << endl << "Enter a string:";
    }
}
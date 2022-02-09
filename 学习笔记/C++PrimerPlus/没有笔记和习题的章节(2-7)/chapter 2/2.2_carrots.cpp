// carrots.cpp - food processing program
// use and display variable
#include <iostream>

int main(){
    using namespace std;

    int carrots;

    carrots = 25;

    cout << "I have ";
    cout << carrots;
    cout << " carrots.";
    cout << endl;

    carrots = carrots - 1;
    cout << "Crunch, crunch. now I have " << carrots << " carrots" << endl;
}
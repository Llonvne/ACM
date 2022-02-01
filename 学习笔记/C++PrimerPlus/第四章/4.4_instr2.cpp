// instr2.cpp -- reading more than one string
#include <iostream>
int main(){
    using namespace std;
    const int Arsize = 20;
    char name[Arsize];
    char dessert[Arsize];

    cout << "Enter your name:\n";
    cin.getline(name,20); // read through new line
    cout << "Enter your favorite dessert:\n";
    //getline(data,length);
    cin.getline(dessert,20); // read through new line

    cout << "I have some delicious " << dessert;
    cout << " for you " << name << ".\n";
    return 0;
}
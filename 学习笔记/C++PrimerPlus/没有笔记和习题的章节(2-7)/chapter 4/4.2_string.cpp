// string.cpp -- storing string in an array
#include <cstring>
#include <iostream>

int main(){
    using namespace std;
    const int Size = 15;
    char name1[Size]; // empty array;
    char name2[Size] = "C++owboy"; // initialized array

    cout << "Hello I am " << name2 ;
    cout << "! What's your name?" << endl ;
    cin >> name1;
    cout << "Well , " << name1 << ", you name has " 
    << strlen(name1) << " letters and is stored!"<<endl;

    cout << "In a array " << sizeof(name1) << " bytes!\n";
    cout << "You initial is " << name1[0] << ".\n";
    name2[3] = '\0';
    cout << "Here are the first 3 characters of name ";
    cout << name2 << endl ;
    
    return 0;    
}
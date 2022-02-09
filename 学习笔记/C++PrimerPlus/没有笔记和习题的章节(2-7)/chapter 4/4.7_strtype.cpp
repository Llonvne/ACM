// strtype.cpp -- using the C++ string class
#include <iostream>
#include <string>

int main(){
    using namespace std;

    char char1[20];
    char char2[20] = "jaguar";
    string str1;
    string str2 = "panther";

    // C++ {} unified initialization
    string str3 = {"1234 123"};

    cout << "Enter a kind of feline: ";
    cin >> char1;
    cout << "Enter another kind of feline: ";
    cin >> str1;

    cout << "Here are some feline: ";
    cout << char1 << " " << char2 << " "
    << str1 << " " << str2 << " " << endl;

    cout << "The third letter in " << char2 << " is "
    <<  char2[2] << endl;

    cout << "The second letter in " << str2 << " is " << str2[2] << endl;

    return 0;
}
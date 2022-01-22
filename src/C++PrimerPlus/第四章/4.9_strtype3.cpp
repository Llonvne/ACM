// strtype3.cpp -- more string class feature 
#include <iostream>
#include <string>  
#include <cstring> // C-style string library

int main(){
    using namespace std;
    char charr1[20];
    char charr2[20]{"jaguar"};
    string str1;
    string str2{"panther"};

    // assignment for string object adn character array
    str1 += str2;
    strcpy(charr1,charr2);

    // appending
    str1 += "paste";
    strcat(charr1,"juice"); //  危险！！！

    // finding the length
    int len1 = str1.length();
    int len2 = strlen(charr1);

    cout << "The string " << str1 << " contains " << len1 << " characters." << endl;
    cout << "The string " << charr1 << " contains " << len1 << " characters." << endl;

    return 0;
}
// morechar.cpp -- the char type and int type contrasted
#include <iostream>
int main(){
    using namespace std;
    char ch = 'M';
    int i = ch;
    cout << "The ASCII code for " << ch << " is " << i << endl;

    cout << "Add one to character code:" << endl;
    ch = ch+1;
    i = i+1;
    cout << "The ASCII code for " << ch << " is " << i << endl;

    // using the cout.put() member function to display ch;
    cout << "Display charactet ch using cout.put(ch);";
    cout.put(ch);

    // using the cout.put() member function to display '!';
    cout.put('!');

    cout << endl;
    cout << "Done" << endl;

    return 0;
}
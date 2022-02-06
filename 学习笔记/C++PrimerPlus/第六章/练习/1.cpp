#include <iostream>
#include <cctype>

using namespace std;

int main(){
    const char TERMINATED = '@';
    char ch;
    while (TERMINATED !=(ch = cin.get())){
        if (isalpha(ch))
        {
            if (islower(ch))
            {
                cout << (char)toupper(ch);
            }
            else
            {
                cout << (char)tolower(ch);
            }
        }
        else {
            cout << ch;
        }
    }
    return 0;
}
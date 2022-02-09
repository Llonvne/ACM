#include <iostream>
#include <string>
using namespace std;

// Benevolent Order of Programmer name structure
const int SIZE = 1024;
struct bop
{
    string fullname;
    string title;
    string bopname;
    int preference;
};

char menu[] = 
R"(a. display by name b. display by title
c. display by bopname d.display by preference
q. quit)";

int main(){
    bop llonvne;
    llonvne.fullname = "fullname";
    llonvne.title = "title";
    llonvne.bopname = "bopname";
    llonvne.preference = 2;

    cout << menu << endl;
    char choice;
    while ('q' != choice)
    {
        switch (choice)
        {   
            // 这里发现如果不 continue choice 无法生效 
            case 'd': choice = llonvne.preference + 'a' - 1; continue;

            case 'a': cout << llonvne.fullname << endl; break;
            case 'b': cout << llonvne.title << endl; break;
            case 'c': cout << llonvne.bopname << endl; break;
        }
        cin >> choice;
    }
    return 0;
}

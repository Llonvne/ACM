// strtype2.cpp -- assiging adding and appending
#include <iostream>
#include <string>
int main(){
    using namespace std;
    // use C++ style to initialization string 
    string s1{"penguin"};
    string s2{},s3{};

    cout << "You can assign one string object to another : s2 = s1\n";
    s2 = s1;
    cout << "s1 = " << s1 << "\n";
    cout << "s2 = " << s2 << "\n";

    cout << "You can assign a C-style string to a string object : s2 = \"buzzard\"\n";
    s2 = "buzzard";
    cout << "s2 = " << s2 << "\n";

    cout << "You can concatenate strings : s3 = s1 + s2\n";
    cout << (s3 = s2 + s1) << endl;

    cout << "You can append strings : s1 += s2\n";
    s1 += s2;

    cout << "s1+=s2 yields s1 = " << s1 << endl;
    s2 += " for a day ";
    cout << "s2 += \" for a day \" yields s2 = " << s2 << endl;

    return 0;
}
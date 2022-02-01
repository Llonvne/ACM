// delete.cpp -- using the delete operator
#include <iostream>
#include <cstring>
using namespace std;
char * getname();

int main(){
    char * name = getname();
    cout << name << " at " << (int *) name << endl;
    delete [] name;

    name = getname();
    cout << name << " at " << (int *) name << endl;
    delete [] name;
}

char * getname(){
    char temp[200000];
    cout << "Enter you name :";
    cin >> temp;
    char * pn = new char[strlen(temp) + 1];
    strcpy(pn, temp);

    // 删除回车
    cin.get();

    return pn;
}

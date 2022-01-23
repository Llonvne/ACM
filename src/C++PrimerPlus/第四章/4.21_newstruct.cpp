// newstruct.cpp -- using new with a struct;
#include <iostream>
struct inflatable {
    char name[20];
    float volume;
    double price;
};
int main(){
    using namespace std;
    inflatable * ps = new inflatable;
    cout << "Enter name of infatable item : ";
    cin.get(ps->name,20);
    cout << "Enter volume of cubic feet : ";
    cin >> (*ps).price;
    cout << "Enter Price: ";
    cin >> ps->price;

    cout << "Name :" << ps->name << endl;
    cout << "Volume :" << (*ps).volume << endl;
    cout << "Price :" << ps->price << endl;
    delete ps;
    return 0;
}

#include <iostream>
#include <array>
#include <string>
using namespace std;

struct Car{
    string name;
    int madeYear;
};

int main(int argc, char* argv[]){

    cout << "How many cars do you wish to catalog? ";
    int cars;
    cin >> cars;
    cin.get();

    Car * carinfo = new Car[cars];

    for (int i = 0; i < cars; i++)
    {
        printf("Car #%d:\n",i+1);
        cout << "Please enter the car name:";
        getline(cin,carinfo[i].name);
        cout << "Please enter the car made-year:";
        cin >> carinfo[i].madeYear;

        cin.get();
    }

    cout << "Here is your collection :\n";
    for (int i = 0; i < cars; i++)
    {
        printf("%d %s\n",carinfo[i].madeYear,carinfo[i].name.c_str());
    }
    
    delete [] carinfo;
    return 0;
}
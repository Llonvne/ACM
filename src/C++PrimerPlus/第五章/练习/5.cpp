// count
#include <string>
#include <iostream>
#include <array>
using namespace std;

int main(){
    string monthsName[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct","Nov", "Dec"};
    string askForBookNumber = R"(How many "C++ Fools" sell in %s :)";
    array<int,12> sells;
    int totals;
    for(int i = 0; i < 12; i++){
        printf(askForBookNumber.c_str(),monthsName[i].c_str());
        cin >> sells[i];
        totals += sells[i];
    }
    printf("Total year C++ Fools sell %d,the best mouth is %s,the bad mouth is %s\n",totals,monthsName[max_element(sells.begin(),sells.end()) - sells.begin()].c_str(),monthsName[min_element(sells.begin(),sells.end()) - sells.begin()].c_str());
}
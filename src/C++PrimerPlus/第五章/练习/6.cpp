// count 3years use array
#include <array>
#include <iostream>
using namespace std;

int main(){
    array<array<int,12>,3> sells;
    const string monthsName[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct","Nov", "Dec"};
    int totals = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < sells[i].size(); j++)
        {
            printf("How many sell in years %d month %s ?\n:", i + 1, monthsName[j].c_str());
            cin >> sells[i][j];
            totals += sells[i][j];
        }
    }
    printf("Total year C++ Fools sell %d,the best mouth is %s,the bad mouth is %s\n",totals,monthsName[max_element(sells.begin(),sells.end()) - sells.begin()].c_str(),monthsName[min_element(sells.begin(),sells.end()) - sells.begin()].c_str());
}
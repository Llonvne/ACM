#include <iostream>
#include <array>
#include <climits>
using namespace std;

struct TaxLevel{
    int startAt;
    int range;
    int rate;
};
void initTaxSystem(array<TaxLevel,4>& taxSystem){
    // level 0
    taxSystem[0].startAt = 0;
    taxSystem[0].range = 5000;
    taxSystem[0].rate = 0;
    // level 1
    taxSystem[1].startAt = 5001;
    taxSystem[1].range = 10000;
    taxSystem[1].rate = 10;
    // level 2
    taxSystem[2].startAt = 15001;
    taxSystem[2].range = 20000;
    taxSystem[2].rate = 15;
    // level 3
    taxSystem[3].startAt = 35001;
    taxSystem[3].range = INT_MAX - taxSystem[3].startAt;
    taxSystem[3].rate = 20;
}

int main(){
    // tax system init
    array<TaxLevel,4> taxSystem;
    initTaxSystem(taxSystem);
    const double rateFix = 0.01;

    int income,tax,incomeBak;
    while (cin >> income && income >= 0){
        tax = 0;
        incomeBak = income;
        for (int i = 0; (income > 0) && (i < 4); i++)
        {
            if (income > taxSystem[i].range)
            {
                tax += taxSystem[i].rate * taxSystem[i].range;
                income -= taxSystem[i].range;
            }
            else {
                tax += taxSystem[i].rate * income;
                income = 0;
            }
        }
        cout << "income :" << incomeBak << " ,tax: " << tax * rateFix << endl;
    }
    return 0;
}

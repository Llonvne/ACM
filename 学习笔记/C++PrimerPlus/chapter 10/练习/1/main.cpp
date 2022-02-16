#include "BankAccount.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<BankAccount> bankAccountGroup;
    bankAccountGroup.push_back(BankAccount{"Llonvne","00001",0});
    cout << bankAccountGroup[0].name() << " " << bankAccountGroup[0].account() << " "
    << bankAccountGroup[0].deposit_number() << endl;
    bankAccountGroup[0].deposits(10000);
    cout << bankAccountGroup[0].name() << " " << bankAccountGroup[0].account() << " "
         << bankAccountGroup[0].deposit_number() << endl;
    bankAccountGroup[0].withdrawals(9000);
    cout << bankAccountGroup[0].name() << " " << bankAccountGroup[0].account() << " "
         << bankAccountGroup[0].deposit_number() << endl;
}

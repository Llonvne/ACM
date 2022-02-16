#include "Trans.h"
#include <vector>
#include <ostream>
#include <istream>
#include <fstream>

Trans * readFile()
{
    std::ifstream file;
    file.open("currency_transaction.dat");
    std::vector<SingleExchangeRate> singleExchangeRateVector;
    SingleExchangeRate buffer;
    while (file.good()){
        file >> buffer.moneyA >> buffer.moneyB >> buffer.A_TO_B >> buffer.B_TO_A;
        singleExchangeRateVector.push_back(buffer);
    }
    file.close();
    file.open("money.dat");
    double money;
    file >> money;
    std::string money_type;
    file >> money_type;
    auto account = new Trans(singleExchangeRateVector,money_type);
    account->save(money);
    return account;
}

int main()
{

}


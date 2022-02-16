//
// Created by 华邵钶 on 2022/2/16.
//

#ifndef TRANS_H
#define TRANS_H
#include "Trans_Type.h"
#include <map>

class Trans
{
    ExchangeRateMap exchangeRateMap;
    double money_value;
    std::string default_money_type = "RMB";

    void bulitExchangeRateMap(const std::vector<SingleExchangeRate> &);
    static void moneyTypeNotFound(const std::string & moneyType);
    double getExchangeRateFromSourceToDest(const std::string & source, const std::string & dest);
    static bool isValueVaild(double value);
public:
    explicit Trans(const std::vector<SingleExchangeRate> & signleExchangeRateVector,
                   const std::string & default_money_type);
    Trans(SingleExchangeRate singleExchangeRateArr[], int arraySize, const std::string & d_money_type);
    Trans();

    void convertAccountCurrency(const std::string & new_DefaultMoneyType);
    bool isMoneyTypeExist(const std::string & need_to_check_type);

    void save(double value);
    void save(double value, const std::string & moneyType);
    void withdraw(double value);
    void withdraw(double value, const std::string & moneyType);

    double transferToTarget(const std::string & target, double value);
    double transferToDefault(const std::string & source, double value);

    void display();
    void display(const std::string & moneyType);

    void addNewMoneyType(const std::string & newMoneyType, double NewToDefault, double DefaultToNew);
    void saveFile();
};

#endif //TRANS_H

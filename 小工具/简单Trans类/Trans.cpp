//
// Created by 华邵钶 on 2022/2/16.
//

#include "Trans.h"
#include <iostream>
#include <utility>
#include <set>
#include <queue>
#include <fstream>

void Trans::bulitExchangeRateMap(const std::vector<SingleExchangeRate> & mt_v)
{
    for (auto i : mt_v) {
        sourceToDest A_B{i.moneyA, i.moneyB};
        sourceToDest B_A{i.moneyB, i.moneyA};
        sourceToDest A_A{i.moneyA, i.moneyA};
        sourceToDest B_B{i.moneyB, i.moneyB};
        exchangeRateMap[A_B] = i.A_TO_B;
        exchangeRateMap[B_A] = i.B_TO_A;
        exchangeRateMap[A_A] = 1.0;
        exchangeRateMap[B_B] = 1.0;
    }
}

void Trans::convertAccountCurrency(const std::string & new_DefaultMoneyType)
{
    if (!isMoneyTypeExist(new_DefaultMoneyType)) {
        moneyTypeNotFound(new_DefaultMoneyType);
    }
    else {
        double target_money = transferToTarget(new_DefaultMoneyType, money_value);
        std::cout << "Your balance " << money_value << "(" << default_money_type << ") was transfer to";
        std::cout << " " << target_money << "(" << new_DefaultMoneyType << ")." << std::endl;
        this->default_money_type = new_DefaultMoneyType;
        money_value = target_money;
    }
}

bool Trans::isMoneyTypeExist(const string & need_to_check_type)
{
    if (exchangeRateMap.find({need_to_check_type, need_to_check_type}) == exchangeRateMap.end()) {
        return false;
    }
    return true;
}

void Trans::moneyTypeNotFound(const std::string & moneyType)
{
    using std::cout;
    using std::endl;
    cout << "Your entered " << moneyType << " not found!" << endl;
    exit(-1);
}

double Trans::getExchangeRateFromSourceToDest(const string & source, const string & dest)
{
    if (exchangeRateMap.find({source, dest}) == exchangeRateMap.end()) {
        // todo BFS
    }
    return exchangeRateMap[{source, dest}];
}

bool Trans::isValueVaild(double value)
{
    return value > 0;
}

Trans::Trans(SingleExchangeRate singleExchangeRateArr[], int arraySize, const std::string & d_money_type)
{
    std::vector<SingleExchangeRate> mt_v{singleExchangeRateArr, singleExchangeRateArr + arraySize};
    bulitExchangeRateMap(mt_v);
    money_value = 0;
    convertAccountCurrency(d_money_type);
}

Trans::Trans(const std::vector<SingleExchangeRate> & signleExchangeRateVector,
             const std::string & default_money_type)
{
    bulitExchangeRateMap(signleExchangeRateVector);
    money_value = 0;
    convertAccountCurrency(default_money_type);
}

Trans::Trans()
{
    money_value = 0;
}

void Trans::save(double value)
{
    save(value, default_money_type);
}

void Trans::save(double value, const string & moneyType)
{
    if (!isValueVaild(value)) {
        std::cout << "value is negative" << std::endl;
        return;
    }
    money_value += transferToDefault(moneyType, value);
}

void Trans::withdraw(double value)
{
    withdraw(value, default_money_type);
}

void Trans::withdraw(double value, const string & moneyType)
{
    if (value < 0) {
        std::cout << "value is negative" << std::endl;
    }
    double withdrawMoney = transferToDefault(moneyType, value);
    if (withdrawMoney > money_value) {
        std::cout << "Sorry, your credit is running low" << std::endl;
        return;
    }
    money_value -= withdrawMoney;
}

double Trans::transferToTarget(const string & target, double value)
{
    if (!isMoneyTypeExist(target)) {
        moneyTypeNotFound(target);
    }
    return value * getExchangeRateFromSourceToDest(default_money_type, target);
}

double Trans::transferToDefault(const string & source, double value)
{
    if (!isMoneyTypeExist(source)) {
        moneyTypeNotFound(source);
    }
    return value * getExchangeRateFromSourceToDest(source, default_money_type);
}

void Trans::display()
{
    std::cout << "Your money type is " << default_money_type << std::endl;
    std::cout << "credit: " << money_value << std::endl;
}

void Trans::display(const string & moneyType)
{
    if (!isMoneyTypeExist(moneyType)) {
        std::cout << "Money type not found" << std::endl;
        return;
    }
    std::cout << "Money type is " << moneyType << std::endl;
    std::cout << "credit: " << transferToTarget(moneyType, money_value) << std::endl;
}

void Trans::addNewMoneyType(const string & newMoneyType, double defaultToNew, double newToDefault)
{
    if (isMoneyTypeExist(newMoneyType)) {
        std::cout << "Money type already exists!" << std::endl;
        return;
    }
    std::vector<SingleExchangeRate> buffer;
    buffer.push_back({newMoneyType, default_money_type, defaultToNew, newToDefault});
    bulitExchangeRateMap(buffer);
}

void Trans::saveFile()
{
    std::ofstream file;
    file.open("currency_transaction.dat");
    for (const auto & i : exchangeRateMap) {
        file << i.first.first << std::endl<< i.first.second << std::endl
             << getExchangeRateFromSourceToDest(i.first.first, i.first.second) << std::endl
             << getExchangeRateFromSourceToDest(i.first.second, i.first.first) << std::endl;
    }
    file.close();
    file.open("money.dat");
    file << money_value << std::endl;
    file << default_money_type << std::endl;
    file.close();
}


















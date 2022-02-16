//
// Created by 华邵钶 on 2022/2/16.
//

#include "Trans.h"
#include <iostream>
#include <utility>
// 内建转换函数 将 vector<MoneyTrans>
void Trans::bulitInTrans(const std::vector<MoneyTrans>& mt)
{
    for (auto i : mt){
        sourceToDest A_B{i.moneyA,i.moneyB};
        sourceToDest B_A{i.moneyB,i.moneyA};
        sourceToDest A_A{i.moneyA,i.moneyA};
        sourceToDest B_B{i.moneyB,i.moneyB};
        moneyMap[A_B] = i.A_TO_B;
        moneyMap[B_A] = i.B_TO_A;
        moneyMap[A_A] = 1.0;
        moneyMap[B_B] = 1.0;
    }
}
void Trans::setDefaultMoneyType(const std::string& moneyType)
{
    if (!isMoneyTypeExist(moneyType)){
        moneyTypeNotFound(moneyType);
    }
    else {
        double target_money = transferToTarget(moneyType,money_value);
        std::cout << "Your balance " << money_value << "(" << default_money_type << ") was transfer to";
        std::cout << " " << target_money << "(" << moneyType << ")." << std::endl;
        this->default_money_type = moneyType;
        money_value = target_money;
    }
}
bool Trans::isMoneyTypeExist(const string & moneyType)
{
    if (moneyMap.find({moneyType, moneyType}) == moneyMap.end()){
        return false;
    }
    return true;
}
void Trans::moneyTypeNotFound(const std::string& moneyType)
{
    using std::cout;
    using std::endl;
    cout << "Your entered " << moneyType << " not found!" << endl;
    exit(-1);
}
double Trans::getAToBExchange(const string & moneyTypeA, const string & moneyTypeB)
{
    return moneyMap[{moneyTypeA,moneyTypeB}];
}
bool Trans::checkValuePositive(double value)
{
    return value > 0;
}

Trans::Trans(MoneyTrans * mt, int n,const std::string& moneyType)
{
    std::vector<MoneyTrans> mt_v{mt,mt+n};
    bulitInTrans(mt_v);
    money_value = 0;
    setDefaultMoneyType(moneyType);
}
Trans::Trans(const std::vector<MoneyTrans>& mt,const std::string& moneyType)
{
    bulitInTrans(mt);
    setDefaultMoneyType(moneyType);
    money_value = 0;
}
Trans::Trans()
{
    money_value = 0;
}

void Trans::save(double value)
{
    if (!checkValuePositive(value)){
        std::cout << "value is negative" << std::endl;
        return;
    }
    money_value += value;
}
void Trans::save(double value, const string & moneyType)
{
    if (!checkValuePositive(value)){
        std::cout << "value is negative" << std::endl;
        return;
    }
    money_value += transferToDefault(moneyType,value);
}

void Trans::withdraw(double value)
{
    if (value < 0){
        std::cout << "value is negative" << std::endl;
        return;
    }
    if (value > money_value){
        std::cout << "Sorry, your credit is running low" << std::endl;
        return;
    }
    money_value -= value;
}
void Trans::withdraw(double value, const string & moneyType)
{
    if (value < 0){
        std::cout << "value is negative" << std::endl;
    }
    double withdrawMoney = transferToDefault(moneyType,value);
    if (value > money_value){
        std::cout << "Sorry, your credit is running low" << std::endl;
        return;
    }
    money_value -= value;
}

double Trans::transferToTarget(const string & target, double value)
{
    if (!isMoneyTypeExist(target)){
        moneyTypeNotFound(target);
    }
    return value * getAToBExchange(default_money_type,target);
}
double Trans::transferToDefault(const string & source, double value)
{
    if (!isMoneyTypeExist(source)){
        moneyTypeNotFound(source);
    }
    return value * getAToBExchange(source,default_money_type);
}


void Trans::display()
{
    std::cout << "Your money type is " << default_money_type << std::endl;
    std::cout << "credit: " << money_value << std::endl;
}
void Trans::display(const string & moneyType)
{
    if (!isMoneyTypeExist(moneyType)){
        std::cout << "Money type not found" << std::endl;
        return;
    }
    std::cout << "Money type is " << moneyType << std::endl;
    std::cout << "credit: " << transferToTarget(moneyType,money_value) << std::endl;
}

void Trans::addNewMoneyType(const string & newMoneyType, double NewToDefault, double DefaultToNew)
{
    if (isMoneyTypeExist(newMoneyType)){
        std::cout << "Money type already exists!" << std::endl;
        return;
    }
    std::vector<MoneyTrans> buffer;
    buffer.push_back({newMoneyType,default_money_type,NewToDefault,DefaultToNew});
    bulitInTrans(buffer);
}













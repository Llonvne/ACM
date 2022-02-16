//
// Created by 华邵钶 on 2022/2/16.
//

#ifndef TRANS_DATA_H
#define TRANS_DATA_H
#include <string>
#include <map>
#include <vector>

using std::string;

struct SingleExchangeRate {
    string moneyA;
    string moneyB;
    double A_TO_B;
    double B_TO_A;
};

typedef std::pair<string,string> sourceToDest;
typedef std::map<sourceToDest,double> ExchangeRateMap;

#endif //TRANS_DATA_H

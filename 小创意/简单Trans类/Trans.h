//
// Created by 华邵钶 on 2022/2/16.
//

#ifndef TRANS_H
#define TRANS_H
#include "Trans_Type.h"
#include <map>

class Trans
{
    // 定义汇率转换表
    ExchangeRateMap exchangeRateMap;
    // 当前金钱数量
    double money_value;
    // 当前金钱类型 默认为RMB 
    std::string default_money_type = "RMB";

    // 建立汇率转换表函数
    void bulitExchangeRateMap(const std::vector<SingleExchangeRate> &);

    // 货币类型未找到退出
    static void moneyTypeNotFound(const std::string & moneyType);

    // 从汇率转换表中查询从 source货币到 dest货币到汇率,以double返回
    double getExchangeRateFromSourceToDest(const std::string & source, const std::string & dest);

    // 检查金额是否正确
    static bool isValueVaild(double value);
public:

    // 构造函数 接受单汇率Vector，和默认货币类型，调用汇率转换函数，建立汇率表
    explicit Trans(const std::vector<SingleExchangeRate> & signleExchangeRateVector,
                    const std::string & default_money_type);
    
    // 构造函数 接受单汇率数组，转换为Vector，调用汇率转换函数，建立汇率表
    Trans(SingleExchangeRate singleExchangeRateArr[], int arraySize, const std::string & d_money_type);

    // 默认构造函数
    Trans();

    // 转换当前货币类型到 参数中的货币类型，且金钱数量自动转换
    void convertAccountCurrency(const std::string & new_DefaultMoneyType);

    // 检查用户输入的货币类型是否存在
    bool isMoneyTypeExist(const std::string & need_to_check_type);

    // 以当前货币类型存钱
    void save(double value);
    
    // 以制定货币类型存钱，会被自动转换为当前货币类型
    void save(double value, const std::string & moneyType);

    // 以当前货币类型取钱
    void withdraw(double value);
    // 以指定货币类型取钱，会完成自动转换
    void withdraw(double value, const std::string & moneyType);

    // 将当前金钱转换为目标类型金钱
    double transferToTarget(const std::string & target, double value);
    // 输入的金钱类型转换为默认金钱类型
    double transferToDefault(const std::string & source, double value);

    // 以当前金钱显示
    void display();
    // 以制定类型显示
    void display(const std::string & moneyType);

    // 增加新货币
    void addNewMoneyType(const std::string & newMoneyType, double NewToDefault, double DefaultToNew);
    // 保存文件
    void saveFile();
};

#endif //TRANS_H

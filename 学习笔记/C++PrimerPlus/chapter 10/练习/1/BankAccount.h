//
// Created by 华邵钶 on 2022/2/15.
//

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
using std::string;
typedef long Number;
class BankAccount
{
private:
    string client_name;
    string client_account;
    Number deposit{};

    static bool is_account_available(const BankAccount& bankAccount);
public:
    // 构造函数
    BankAccount();
    BankAccount(const string&, const string& client_account,Number d_number);
    // 后置初始化
    BankAccount & initBankAccount(const string& name, const string& account, Number d_number);
    // 显示函数
    const string& name() const;
    const string& account() const;
    Number deposit_number() const;
    // 存 取
    bool deposits(Number d_number);
    bool withdrawals(Number w_number);
};


#endif //BANKACCOUNT_H

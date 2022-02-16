//
// Created by 华邵钶 on 2022/2/15.
//

#include "BankAccount.h"

BankAccount::BankAccount()
{
    this->client_name = "undefined";
    this->client_account = "undefined";
    this->deposit = 0;
}

BankAccount::BankAccount(const string & client_name, const string & client_account, Number
d_number)
{
    this->client_name = client_name;
    this->client_account = client_account;
    this->deposit = d_number;
}

const string & BankAccount::name() const
{
    return client_name;
}

const string & BankAccount::account() const
{
    return client_account;
}

Number BankAccount::deposit_number() const
{
    return deposit;
}

bool BankAccount::deposits(Number d_number)
{
    if (d_number <= 0 && !is_account_available(*this)){
        return false;
    }
    deposit += d_number;
    return true;
}

bool BankAccount::withdrawals(Number w_number)
{
    if (deposit_number() < w_number && !is_account_available(*this)){
        return false;
    }
    deposit -= w_number;
    return true;
}

bool BankAccount::is_account_available(const BankAccount & bankAccount)
{
    if (bankAccount.client_account == "undefined" && bankAccount.client_account != "undefined"){
        return false;
    }
    return true;
}

BankAccount & BankAccount::initBankAccount(const string & name, const string & account, Number d_number)
{
    this->client_name = name;
    this->client_account = account;
    this->deposit = d_number;
}



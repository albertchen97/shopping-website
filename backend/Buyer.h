#pragma once
#include "User.h"

class Buyer : public User
{
private:
    int balance;
public:
    Buyer();
    int getBalance();
    void setBalance(int newBalance);
};


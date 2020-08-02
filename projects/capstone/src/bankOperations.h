#pragma once
#include "UserDB.h"
#include "UserLogin.h"

class bankOperations
{
    public:
    bankOperations();
    bankOperations(UserDB *users,UserLogin *userLogin);
    ~bankOperations();
    int getBalance(int &balance);
    bool withdraw(int amount);
    bool deposit(int amount);
    
    private:
    int _balance;
    UserDB *users;
    UserLogin *userLogin;
};
#pragma once

class bankOperations
{
    public:
    bankOperations();
    ~bankOperations();
    int getBalance();
    bool withdraw(int amount);
    void deposit(int amount);
    
    private:
    int _balance;
};
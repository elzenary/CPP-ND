#include"class bankOperations.h"

bankOperations::bankOperations(){
}
~bankOperations::bankOperations(){
}
int bankOperations::getBalance()
{
    return _balance;
}
bool bankOperations::withdraw(int amount)
{
    if(amount<_balance)
    {
        _balance-=amount;
        return true;
    }
    else
    {
        return false
    }
}
void bankOperations::deposit(int amount)
{
    _balance+=amount;
}


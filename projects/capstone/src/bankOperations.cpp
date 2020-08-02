#include"bankOperations.h"

bankOperations::bankOperations(){
}
bankOperations::bankOperations(UserDB *users,UserLogin *userLogin)
{
   this->users=users;
   this->userLogin=userLogin;  
}
bankOperations::~bankOperations(){
}
bool bankOperations::deposit(int amount)
{
    string currentUser;
    userInfo_t userInfo;
    if(this->userLogin->getUserLoginStaus(currentUser)==true)
    {
        _balance+=amount;
        users->getUserInfo(currentUser,&userInfo);
        users->setUserBalance(currentUser,(userInfo.balance+amount));     
        return true;
    }
    else
    {
        return false;
    }
}
bool bankOperations::withdraw(int amount)
{
    string currentUser;
    userInfo_t userInfo;
    if(this->userLogin->getUserLoginStaus(currentUser)==true)
    {
        users->getUserInfo(currentUser,&userInfo);
        if(amount<userInfo.balance)
        {
            users->setUserBalance(currentUser,(userInfo.balance-amount)); 
            return true;
        }
        else
        {
            return false;
        }    
    }
    else
    {
        return false;
    }
}

int bankOperations::getBalance(int &balance)
{
    string currentUser;
    userInfo_t userInfo;
    if(this->userLogin->getUserLoginStaus(currentUser)==true)
    {
        users->getUserInfo(currentUser,&userInfo);
        balance=userInfo.balance; 
        return true;
    }
    else
    {
        return false;
    }    
}


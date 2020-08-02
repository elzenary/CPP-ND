// BanksMgmt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;
#include <iostream>
#include<fstream>
#include "sha256.h"
#include <map>
#include"UserDB.h"
#include"UserRegister.h"
#include"UserLogin.h"
#include"bankOperations.h"

using namespace std;

string userInfo;
string userAdd;
int c = 3;
int main()
{

   userAdd = "fady11";
    userInfo= sha256("pass2hannyff11");
  userInfo_t userInfoStruct;
  userInfoStruct.pass=userInfo;//"5401ce06e1f9ca668ac4bc9c6ec3d4be40d355228a4de195dff9844c99c6dc15";
  userInfoStruct.balance=1234;
  /*
    r.RegisterNewUser(userAdd, userInfoStruct);*/
  
   UserDB dbObj;
  string userFady;
  //UserRegister r(&dbObj);
  UserLogin ul(&dbObj);
  bankOperations b(&dbObj,&ul);
  cout<<"login:"<<ul.RequestUserLogin(userAdd,userInfoStruct.pass)<<endl;
  cout <<"get login status:"<< ul.getUserLoginStaus(userFady)<<endl;
  cout<<"logged user name:"<<userFady<<endl;
  b.deposit(1000);
  int bal;
  b.getBalance(bal);
  cout<<"currentBalance:"<<bal<<endl;
  b.withdraw(100);
  b.getBalance(bal);
  cout<<"currentBalance:"<<bal<<endl;
  
  
  
/*  
    userAdd = "fady11";
   userInfo= sha256("pas");
  userInfoStruct.pass=userInfo;//"5401ce06e1f9ca668ac4bc9c6ec3d4be40d355228a4de195dff9844c99c6dc15";
  userInfoStruct.balance=1234;
  
    cout<<"login2:"<<ul.RequestUserLogin(userAdd,userInfoStruct.pass)<<endl;
  cout <<"get login status2:"<< ul.getUserLoginStaus()<<endl;
*/    
    /*userAdd = "fady2";
    userInfo= sha256("pass2hannyff2");
    dbObj.addUserToDB(userAdd, userInfo);*/

   /* userAdd = "hassan";
    userInfo = sha256("pass3");
    r.RegisterNewUser(userAdd, userInfo);
   // db.addUserToDB(userAdd, userInfo);

    userAdd = "ahmed";
    userInfo= sha256("play");
    r.RegisterNewUser(userAdd, userInfo);
    //db.addUserToDB(userAdd, userInfo);

    userAdd = "noIdea";
    userInfo = sha256("noIdea");
    r.RegisterNewUser(userAdd, userInfo);
    //db.addUserToDB(userAdd, userInfo);

    db.getUserInfo(userAdd, &userInfo);*/

    /*UserLogin userLog(&db);
    cout<<"ret "<<userLog.RequestUserLogin("test", "False")<<endl;
    cout << userLog.getUserLoginStaus()<<endl;

    UserLogin userLog2(&db);
    cout<<"ret "<<userLog2.RequestUserLogin("ahmed", "aba4cc9b8af82df5d4efaade764d6a77466453f3e4156bb0b4e489710516b1c3")<<endl;
    cout << userLog2.getUserLoginStaus()<<endl;*/
    /*cout << "gettingUserInfo " << userAdd<<" " << userInfo<< endl;
    std::cout << "Hello World!\n";*/

    return 0;
}







// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

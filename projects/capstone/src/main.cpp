// BanksMgmt.cpp : This file contains the 'main' function. Program execution begins and ends there.

using namespace std;
#include <iostream>
#include<fstream>
#include "sha256.h"
#include <map>
#include"UserDB.h"
#include"UserRegister.h"
#include"UserLogin.h"
#include"bankOperations.h"
#include"FSM.h"

using namespace std;

  /*FSM testing code*/

 /*for testing valid credintial
 
   user:noIdea
   pass:noIdea
   
   user:ahmed
   pass:play
   
   user:wael
   pass:12345
   
   user:test
   pass:test
   
 */

 /*create DB object*/
 UserDB dbObj;
  
 /*create login object*/
 UserLogin ul(&dbObj);

 /*create register object*/
 UserRegister r(&dbObj);

 /*create bank operations object*/
 bankOperations b(&dbObj,&ul);

int main()
{
 
  /*inside infinite loop call FSM manger*/
  while(true)
  {
   	FSM_Manger();
  }
  
    return 0;
}


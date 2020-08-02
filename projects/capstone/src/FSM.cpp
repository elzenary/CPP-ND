#include "sha256.h"
#include"UserDB.h"
#include"UserRegister.h"
#include"UserLogin.h"
#include"bankOperations.h"
#include"FSM.h"
#include<iostream>
using namespace std;

/*global var which holds the currenf state*/
windowStates_t windowStates=windowStates_t::initial_w;

/*helper function which change the state based on user input
this function is called in different states to hadle the program traversing*/
void traverseOptions()
{
   cout<<"traversing options"<<endl;
   cout<<"enter l for login"<<endl;
   cout<<"enter r for register"<<endl;
   cout<<"enter i for initial window"<<endl;
   /*TODO move to login or register window*/
    char userInput;
    bool validInput=true;
   do
       {
       cin>>userInput;
       /*implement transition conditions*/
       switch(userInput)
       {
           case 'l':
           case 'L':
            windowStates=windowStates_t::login_w;
            break;
           case 'r':
           case 'R':
            windowStates=windowStates_t::register_w;
            break;      
           case 'i':
           case 'I':
            windowStates=windowStates_t::initial_w;
            break;     
          default:
            cout<<"please enter valid input"<<endl;
            validInput=false;
            break;
       }
   }while(validInput);
}

/*initial window after launching the program
the initial state handling*/
void initialWindow()
{
   cout<<"welcome to Bank inital window"<<endl;
   traverseOptions();
}

/*this function represent user login state
and handles login operations*/
void loginWindow()
{
    string usr,pass;
   cout<<"welcome to Bank login window"<<endl;
   cout<<"options"<<endl;
   cout<<"enter userName space password"<<endl;
   cout<<"Example: Ahmed pass123"<<endl;
   cin>>usr>>pass;
   /*TODO verify login*/
   /*if login fails*/
   cout<<"login fail"<<endl;
   traverseOptions();
   
   /*if login pass*/
   /*TODO move to user window*/
}

/*this function represet user register state
and handles register operations*/
void registerWindow()
{
    string usr,pass;
    int balance;
    char action;
   cout<<"welcome to Bank register window"<<endl;
   cout<<"options"<<endl;
   cout<<"enter userName  password initialBalance"<<endl;
   cout<<"Example Ahmed pass123 5000"<<endl;
   cin>>usr>>pass>>balance;
   /*TODO verify register and show register output*/
   cout<<"register status is TODO"<<endl;
   
   /*display traversing options*/
   traverseOptions();

}

/*this function should handle user operations after login
deposit withdraw getBalance*/
void userWindow()
{
   char action;
   cout<<"welcome user window"<<endl;
   cout<<"options"<<endl;
   cout<<"enter d for deposit"<<endl;
   cout<<"enter w for withdraw"<<endl;
   cout<<"enter g for get balance"<<endl;
    char userInput;
    bool validInput=true;
   do
       {
       cin>>userInput;
       /*implement transition conditions*/
       switch(userInput)
       {
           case 'd':
           case 'D':
            /*get amount from the user*/
            /*do operation*/
            /*show result*/
            break;
           case 'w':
           case 'W':
            /*get amount from the user*/
            /*do operation*/
            /*show result*/
            break;      
           case 'g':
           case 'G':
            /*do operation*/
            /*show result*/
            break;     
          default:
            cout<<"please enter valid input"<<endl;
            validInput=false;
            break;
       }
   }while(validInput);
    
}
void FSM_Manger()
{
    switch(windowStates)
    {
        case windowStates_t::initial_w:
            initialWindow();
        
        break;
        case windowStates_t::login_w  :
            loginWindow();
        
        break;        
        case windowStates_t::register_w  :
            registerWindow();
        
        break;
        case windowStates_t::user_w  :
            userWindow();
        
        break;
        default:
            /*error*/
            /*show an error occured error*/
            /*go to initial window*/
        break;
        
        break;        
    }
}
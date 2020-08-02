#include"FSM.h"
#include<iostream>
using namespace std;
windowStates_t windowStates=initial_w;

/*helper function which change the state based on user input*/
void traverseOptions()
{
   cout<<"traversing options"<<endl;
   cout<<"enter l for login"<<endl;
   cout<<"enter r for register"<<endl;
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
           case 'i':
            windowStates=windowStates_t::initial_w;
            break;     
          default:
            cout<<"please enter valid input"<<endl;
            validInput=false;
            break;
       }
   }while(validInput);
}

void initialWindow()
{
   cout<<"welcome to Bank inital window"<<endl;
   traverseOptions();

   
}
void loginWindow()
{
    string usr,pass;
   cout<<"welcome to Bank login window"<<endl;
   cout<<"options"<<endl;
   cout<<"enter user name then space then password"<<endl;
   cout<<"Example Ahmed pass123"<<endl;
   cin>>usr>>pass;
   /*TODO verify login*/
   /*if login fails*/
   cout<<"login fail"<<endl";
   traverseOptions();
   
   /*if login pass*/
   /*TODO move to user window*/
}
void registerWindow()
{
    string usr,pass;
    int balance;
    char action;
   cout<<"welcome to Bank register window"<<endl;
   cout<<"options"<<endl;
   cout<<"enter user name then space then password then space initial balance"<<endl;
   cout<<"Example Ahmed pass123 5000"<<endl;
   cin>>usr>>pass>>balance;
   /*TODO verify register and show register output*/
   cout<<"register status is TODO"<<endl;
   
   /*display traversing options*/
   traverseOptions();
   }
}

{
void userWindow()
{
   cout<<"welcome user window"<<endl;
   cout<<"options"<<endl;
   cout<<"enter d for deposit"<<endl;
   cout<<"enter w for withdraw"<<endl;
   cout<<"enter g for get balance"<<endl;
    
}
void FSM_Manger()
{
    
// enum class windowStates_t={initial_w,login_w,register_w,user_w,admin_W};
    /*TODO handling the movement between different states*/
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
        case windowStates_t::admin_W  :
            adminWindow()
        
        break;
        default:
        
        break;
        
        break;        
    }
}
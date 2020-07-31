#include"FSM.h"
#include<iostream>
using namespace std;
windowStates_t windowStates=initial_w;

void initialWindow()
{
   cout<<"welcome to Bank inital window"<<endl;
   cout<<"options"<<endl;
   cout<<"enter l for login"<<endl;
   cout<<"enter r for register"<<endl;
   /*TODO move to login or register window*/
   
}
void loginWindow()
{
   cout<<"welcome to Bank login window"<<endl;
   cout<<"options"<<endl;
   cout<<"enter user name then space then password"<<endl;
   /*TODO verify login*/
}
void registerWindow()
{
   cout<<"welcome to Bank register window"<<endl;
   cout<<"options"<<endl;
   cout<<"enter user name then space then password"<<endl;
   /*TODO verify register then move register status state*/
}
void userWindow()
{
       cout<<"welcome to Bank login window"<<endl;
   cout<<"options"<<endl;
   cout<<"enter user name then space then password"<<endl;
    
}
void adminWindow()
{
    /*TODO to be designed*/
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
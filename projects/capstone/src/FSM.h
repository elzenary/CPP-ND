#pragma once

enum class windowStates_t{initial_w,login_w,register_w,user_w};
extern  UserLogin ul;
extern UserRegister r;
extern bankOperations b;
void  traverseOptions();
void initialWindow();
void loginWindow();
void registerWindow();
void userWindow();
void adminWindow();
void FSM_Manger();
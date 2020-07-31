#pragma once

enum class windowStates_t={initial_w,login_w,register_w,user_w,admin_W};
void initialWindow();
void loginWindow();
void registerWindow();
void userWindow();
void adminWindow();
void FSM_Manger();
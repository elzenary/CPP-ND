#pragma once
#include<string>
#include"UserDB.h"
#include"UserLogin.h"
using namespace std;
class UserLogin
{
public:
	UserLogin(UserDB* usersLoc);
	~UserLogin();
	UserLogin(UserLogin& u);
	bool RequestUserLogin(string user, string pass);
	bool getUserLoginStaus();
	bool userLoginOut();
private:

private:
	UserDB* users;
	bool loginStatus;
	
};


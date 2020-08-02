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
	bool RequestUserLogin(string user, string userInfo);
	bool getUserLoginStaus(string &userID_ref);
	void userLogOut();
private:

private:
	UserDB* users;
	bool loginStatus;
	string userName;
};


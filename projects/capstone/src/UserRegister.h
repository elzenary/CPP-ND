#pragma once
#include<string>
#include<map>
#include<fstream>
#include"UserDB.h"

using namespace std;

class UserRegister
{
public:
	UserRegister(UserDB* users);
	~UserRegister();
	bool RegisterNewUser(string usr, userInfo_t userInfo);
	
private:
	UserDB *users;

};


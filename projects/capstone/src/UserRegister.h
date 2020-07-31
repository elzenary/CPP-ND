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
	//UserRegister(UserRegister& usr);
	bool RegisterNewUser(string usr, string pass);
	bool deleteUserResister(string usr);
	
private:
	UserDB *users;

};


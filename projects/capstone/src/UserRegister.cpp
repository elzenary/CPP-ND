#include "UserRegister.h"

UserRegister::UserRegister(UserDB* usersLoc)
{
	this->users = usersLoc;
}

UserRegister::~UserRegister()
{
}
/*
UserRegister::UserRegister(UserRegister& usr)
{
}*/

bool UserRegister::RegisterNewUser(string usr, string pass)
{
	if (this->users->isUserExist(usr))
	{
		return false;
	}
	else
	{
		if (this->users->addUserToDB(usr, pass))
			return true;
		else
			return false;
		
	}
	
}

bool UserRegister::deleteUserResister(string usr)
{
	return false;
}



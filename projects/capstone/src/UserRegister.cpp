
#include "UserRegister.h"
#include "UserDB.h"

UserRegister::UserRegister(UserDB* usersLoc)
{
	this->users = usersLoc;
}

UserRegister::~UserRegister()
{
}

bool UserRegister::RegisterNewUser(string usr, userInfo_t userInfo)
{
	if (this->users->isUserExist(usr))
	{
		return false;
	}
	else
	{
		if (this->users->addUserToDB(usr, userInfo))
			return true;
		else
			return false;
		
	}
	
}

bool UserRegister::deleteUserResister(string usr)
{
	return false;
}



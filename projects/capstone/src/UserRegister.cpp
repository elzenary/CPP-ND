
#include "UserRegister.h"
#include "UserDB.h"
#include "sha256.h"

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
    	userInfo.pass=sha256(userInfo.pass);
		this->users->addUserToDB(usr, userInfo);
        this->users->StoreDbToRom();
        //this->users->loadDbToRam();
        return true;
	}
	
}



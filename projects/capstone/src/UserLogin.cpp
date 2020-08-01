#include "UserLogin.h"


UserLogin::UserLogin(UserDB* usersLoc)
{
	this->users = usersLoc;
	loginStatus = false;
}

UserLogin::~UserLogin()
{
}
bool UserLogin::RequestUserLogin(string userID, string pass)
{
  userInfo_t userInfoGet;
  this->users->getUserInfo(userID, &userInfoGet);
  if (userInfoGet.pass == pass)
  {
    loginStatus = true;
    return	true;
  }
  else
  {
    loginStatus = false;
    return false;
  }

}

bool UserLogin::getUserLoginStaus()
{
	return loginStatus;
}
bool UserLogin::userLoginOut()
{
	if (loginStatus == false)
	{
		return false;
	}
	else
	{
		loginStatus = false;
		return true;
	}
}

UserLogin::UserLogin(UserLogin& u)
{
	loginStatus = false;
	this->users = u.users;
}

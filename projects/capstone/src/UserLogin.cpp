#include "UserLogin.h"
#include "sha256.h"

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
  if (userInfoGet.pass == sha256(pass) )
  {
    loginStatus = true;
    userName=userID;
    return	true;
  }
  else
  {
    loginStatus = false;
    return false;
  }
}
bool UserLogin::getUserLoginStaus(string &userID_ref)
{
    userID_ref=userName;
	return loginStatus;
}
void UserLogin::userLogOut()
{
userName="";
loginStatus=false;
}

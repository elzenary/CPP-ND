#pragma once
#include<string>
#include<map>
#include<fstream>
#include<iterator>
using namespace std;
typedef struct userInfoStruct
{
	string pass;
    int balance;
}userInfo_t;

class UserDB
{
public:
	UserDB();
	~UserDB();
	UserDB(UserDB& usr);
	bool isUserExist(string usr);
	bool getUserInfo(string usrId, userInfo_t* userInfo);
	int getNumbersOfUsers(void);
	bool addUserToDB(string id, userInfo_t userInfo);
    void setUserBalance(string usrId,int amount);

private:
	map<string, userInfo_t> usersBuffer;
	fstream fs;
	string id;
	userInfo_t usrinfo;
	void loadDbToRam();
	void StoreDbToRom();
};
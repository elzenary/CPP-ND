#pragma once
#include<string>
#include<map>
#include<fstream>
#include<iterator>
using namespace std;
typedef struct userInfoStruct
{
	string pass;
}userInfo_t;

class UserDB
{
public:
	UserDB();
	~UserDB();
	UserDB(UserDB& usr);
	bool isUserExist(string usr);
	bool getUserInfo(string usrId, string* userInfo);
	int getNumbersOfUsers(void);
	bool addUserToDB(string id, string userInfo);
protected:
	bool getUsersIterators(map<string, string>::iterator& begin, map<string, string>::iterator& end);
private:
	map<string, string> usersBuffer;
	fstream fs;
	string id;
	string usrinfo;
	void loadDbToRam();
	void StoreDbToRom();
};
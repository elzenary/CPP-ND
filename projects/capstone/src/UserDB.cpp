#include<iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "UserDB.h"

using namespace std;

UserDB::UserDB() {
    cout<<"constructor call"<<endl;
	loadDbToRam();
}
UserDB::~UserDB()
{
	StoreDbToRom();
}
UserDB::UserDB(UserDB& usr)
{
     cout<<"copy constructor call"<<endl;
	loadDbToRam();
}
bool UserDB::isUserExist(string usr)
{
  if(usersBuffer.find(usr) == usersBuffer.end())
	return false;
  else
    return true;
}
bool UserDB::getUserInfo(string usrId, userInfo_t* userInfo)
{
    if(usersBuffer.find(usrId) != usersBuffer.end())
    {
      *userInfo = usersBuffer.find(usrId)->second;
	  return true;
    }
    else
    {
     	return false; 
    }

}
void UserDB::setUserBalance(string usrId, int amount)
{
    if(usersBuffer.find(usrId) != usersBuffer.end())
        usersBuffer.find(usrId)->second.balance=amount;
}
int UserDB::getNumbersOfUsers(void)
{
	return usersBuffer.size();
}
void UserDB::addUserToDB(string idx, userInfo_t userInfoLocal)
{
    usersBuffer.insert(pair<string, userInfo_t>(idx, userInfoLocal));
}

void UserDB::loadDbToRam()
{
    std::cout << "loadDb file not open"<<endl;
    std::string line;
    std::ifstream filestream("../src/authdb.data");
	if (filestream)
	{
         std::cout << "loadDb file open"<<endl;
        while( std::getline(filestream, line) )
        {
            std::istringstream linestream(line);
            linestream >> id >> usrinfo.pass >> usrinfo.balance;
            UserDB::usersBuffer.insert(pair<string, userInfo_t>(UserDB::id, usrinfo));
            /*for debugging*/
            /*std::cout << "constructor inserted id:"<<UserDB::usersBuffer.find(id)->first << " inseted pass:" << (UserDB::usersBuffer.find(id)->second) <<"inserted balance:"<<(UserDB::usersBuffer.find(id)->second).balance << endl;*/
        }
        std::cout << "loadDb eof"<<endl;
	}
}

void UserDB::StoreDbToRom()
{
    std::ofstream ofilestream("../src/authdb.data");
    std::cout << "storeDb file not open"<<endl;
	if (ofilestream)
	{
        std::cout << "storeDb file opened"<<endl;
		map<string, userInfo_t>::iterator it; 
		for (it = usersBuffer.begin(); it != usersBuffer.end(); it++)
		{
			ofilestream <<it->first << " "<< it->second.pass <<  " "<< it->second.balance<< endl;
			cout <<it->first << " "<< it->second.pass <<  " "<< it->second.balance<< endl;
		}
        cout << "destructor writing in file end1"<<endl;

	}
}
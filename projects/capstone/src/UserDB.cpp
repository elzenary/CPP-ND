#include "UserDB.h"
#include<iostream>
using namespace std;

UserDB::UserDB() {
	fs.open("authdb.data");
	loadDbToRam();
	fs.close();
}
UserDB::~UserDB()
{
	fs.open("authdb.data");
	StoreDbToRom();
	fs.close();

}
UserDB::UserDB(UserDB& usr)
{
	fs.open("UsersDB.data");
	loadDbToRam();
}
bool UserDB::isUserExist(string usr)
{
	return false;
}
bool UserDB::getUserInfo(string usrId, string* userInfo)
{
	try
	{
		if(usersBuffer.find(usrId) != usersBuffer.end())
			*userInfo = usersBuffer.find(usrId)->second;
	}
	catch(exception& e)
	{
		cout << e.what() << endl;
		return false;
	}
	catch (...)
	{
		cout << "unhadeled exeption" << endl;
		return false;
	}
	return true;

}
int UserDB::getNumbersOfUsers(void)
{
	return usersBuffer.size();
}
bool UserDB::addUserToDB(string idx, string userInfoLocal)
{
	//cout << "addUserToDB " << userInfoLocal << endl;
	try {
		if (usersBuffer.find(idx) == usersBuffer.end())
		{
			std::pair<std::map<string, string>::iterator, bool> ret;
			ret= usersBuffer.insert(pair<string, string>(idx, userInfoLocal));
			if (ret.second == false)
				//cout << "addUserToDB from map" << usersBuffer.find(idx)->second << endl;
				//else
			{
				cout << "can't inset";
				return false;
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
		return false;
	}
	catch (...)
	{
		cout << "unhadeled exeption" << endl;
		return false;
	}
	
	return false;
}
bool UserDB::getUsersIterators(map<string, string>::iterator& begin, map<string, string>::iterator& end)
{
	//*begin;
	begin = UserDB::usersBuffer.begin();
	end = UserDB::usersBuffer.end();

	return false;
}


void UserDB::loadDbToRam()
{
	if (fs.is_open())
	{
		while (!fs.eof())
		{
			while (!fs.eof())
			{
				fs >> id;
				fs >> usrinfo;
				UserDB::usersBuffer.insert(pair<string, string>(UserDB::id, usrinfo));
				/*for debugging*/
				//std::cout << UserDB::usersBuffer.find(id)->first << " " << (UserDB::usersBuffer.find(id)->second) << endl;
			}
		}
	}
}

void UserDB::StoreDbToRom()
{
	if (fs.is_open())
	{
		map<string, string>::iterator it; 
		for (it = usersBuffer.begin(); it != usersBuffer.end(); it++)
		{
			fs << it->first << " " << it->second << endl;
			//cout << "debugAdd " << it->first << " " << it->second<<endl;
		}

	}
}
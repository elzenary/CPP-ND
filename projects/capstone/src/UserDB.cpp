
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
	//fs.open("authdb.data");
	StoreDbToRom();
	//fs.close();

}
UserDB::UserDB(UserDB& usr)
{
	// fs.open("authdb.data");
	// loadDbToRam();
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
    std::cout << "loadDb file not open"<<endl;
    std::string line;
    std::ifstream filestream("../src/authdb.data");
	if (filestream)
	{
         std::cout << "loadDb file open"<<endl;
        while( std::getline(filestream, line) )
        {
            std::istringstream linestream(line);
            linestream >> id >> usrinfo;
            UserDB::usersBuffer.insert(pair<string, string>(UserDB::id, usrinfo));
            /*for debugging*/
            std::cout << "constructor inserted id:"<<UserDB::usersBuffer.find(id)->first << " inseted pass:" << (UserDB::usersBuffer.find(id)->second) << endl;
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
		map<string, string>::iterator it; 
		for (it = usersBuffer.begin(); it != usersBuffer.end(); it++)
		{
			ofilestream << it->first << " " << it->second << endl;
			cout << "debugAdd destructor id:" << it->first << " pass"" << it->second"<<endl;
		}
        ofilestream << "test" << " " << "end"<< endl;
        cout << "test" << " " << "end"<< endl;

	}
}
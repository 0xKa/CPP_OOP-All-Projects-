//good prctice: seperate the UI code from the Object code
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"; 
#include "clsString.h"; 
#include "clsBankClient.h";
#include "Global.h";
#include "clsDate.h";
#include "clsUtil.h";

using namespace std;

string UsersFile = "Users.txt";
short EncryptionKey = 12;


class clsUser : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	string _Username;
	string _Password;
	int _Permissions;
	bool _MarkForDelete = false;

	static clsUser _ConvertLinetoUserObject(string Line, string Seperator = GlobalSeperator)
	{
		vector <string> vUserData = clsString::Split(Line, Seperator);

		return clsUser(UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5], EncryptionKey), stoi(vUserData[6]));//decrypt the password in v[5]
	}
	static string _ConvertUserObjectToLine(clsUser User, string Seperator = GlobalSeperator)
	{
		string UserRecord = "";
		UserRecord += User.FirstName + Seperator;
		UserRecord += User.LastName + Seperator;
		UserRecord += User.Email + Seperator;
		UserRecord += User.Phone + Seperator;
		UserRecord += User._Username + Seperator;
		UserRecord += clsUtil::EncryptText(User._Password, EncryptionKey) + Seperator; //encrypt here
		UserRecord += to_string(User._Permissions);
		
		return UserRecord;
	}

	static vector <clsUser> _LoadUsersDataFromFile()
	{
		vector <clsUser> vUsers;
		fstream MyFile;

		MyFile.open(UsersFile, ios::in);//read mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return vUsers;
	}
	static void _SaveUsersDataToFile(vector <clsUser> vUsers)
	{
		fstream MyFile;
		MyFile.open(UsersFile, ios::out);//overwrite mode

		string Line;

		if (MyFile.is_open())
		{
			for (clsUser C : vUsers)
			{
				if (C.isMarkedForDelete() == false)
				{
					Line = _ConvertUserObjectToLine(C);
					MyFile << Line << endl;
				}
			}

			MyFile.close();
		}
	}

	void _AddLineToFile(string Line)
	{
		fstream MyFile;
		MyFile.open(UsersFile, ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << Line << endl;
			MyFile.close();
		}

	}

	string _PrepareLoginRecord(string Seperator = GlobalSeperator)
	{
		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
		LoginRecord += Username + Seperator;
		LoginRecord += clsUtil::EncryptText(Password, EncryptionKey) + Seperator;
		LoginRecord += to_string(Permissions);

		return LoginRecord;
	}
	//funcs for LoginRegisterScreen
	struct stLoginData; //this is just declration
	static stLoginData _ConvertLinetoLoginDataStruct(string Line, string Seperator = GlobalSeperator)
	{
		vector <string> vLoginData = clsString::Split(Line, Seperator);
		stLoginData LoginData;

		LoginData.LoginDateTime = vLoginData[0];
		LoginData.LoginUsername = vLoginData[1];
		LoginData.LoginPassword = clsUtil::DecryptText(vLoginData[2], EncryptionKey);
		LoginData.LoginPermissions = stoi(vLoginData[3]);

		return LoginData;
	}
	static vector <stLoginData> _LoadLoginDataFromFile()
	{
		vector <stLoginData> vLoginData;
		fstream MyFile;

		MyFile.open("LoginRegister.txt", ios::in);//read mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				stLoginData LoginData = _ConvertLinetoLoginDataStruct(Line);
				vLoginData.push_back(LoginData);
			}
			MyFile.close();
		}
		return vLoginData;
	}


	void _Update()
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& C : _vUsers)
		{
			if (C._Username == _Username)
			{
				C = *this; //puts the current user in the vector, 
				break;
			}
		}

		_SaveUsersDataToFile(_vUsers); //rewrite the txt file after the update

	}
	void _AddNew()
	{
		_AddLineToFile(_ConvertUserObjectToLine(*this));
	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(EmptyMode, "", "", "", "", "", "", 0);
	}

public:
	//parameterized constructor 
	clsUser(enMode Mode, string FirstName, string LastName, string Email
		, string Phone, string Username, string Password, int Permissions)
		: clsPerson(FirstName, LastName, Email, Phone) //send variables to clsPerson
	{
		_Mode = Mode;
		_Username = Username;
		_Password = Password;
		_Permissions = Permissions;
	}

	enum enPermissions {
		pAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClient = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64,
		pLoginRegisterList = 128, pCurrencyExchange = 256
	};

	struct stLoginData
	{
		string LoginDateTime;
		string LoginUsername;
		string LoginPassword;
		int LoginPermissions;
	};


	bool isEmpty()
	{
		return (_Mode == EmptyMode);
	}
	bool isMarkedForDelete()
	{
		return _MarkForDelete;
	}


	string SetUsername(string Username)
	{
		_Username = Username;
	}
	string GetUsername()
	{
		return _Username;
	}
	__declspec(property(get = GetUsername, put = SetUsername)) string Username;

	void SetPassword(string Password)
	{
		_Password = Password;
	}
	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}
	int GetPermissions()
	{
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

	//it calls _LoadUsersDataFromFile() but static and public
	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	static clsUser Find(string Username)
	{
		fstream MyFile;

		MyFile.open(UsersFile, ios::in);//read mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				if (User._Username == Username)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();  //means client not found
	}
	static clsUser Find(string Username, string Password)
	{
		//overload
		clsUser User1 = Find(Username);
		return (User1.Password == Password) ? User1 : _GetEmptyUserObject();
	}
	static bool IsUserExist(string Username)
	{
		clsUser User1 = clsUser::Find(Username);
		return (!User1.isEmpty()); //checks if it is EmptyMode
	}

	bool Delete()
	{
		vector <clsUser> _vUsers = _LoadUsersDataFromFile();

		for (clsUser& C : _vUsers)
		{
			if (C.Username == Username)
			{
				C._MarkForDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(_vUsers);
		*this = _GetEmptyUserObject(); //clearing all data in the current object, with empty _Mode

		return true;
	}

	static clsUser GetAddNewUserObject(string Username)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", Username, "", 0);
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUsernameExists = 2 };
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			return enSaveResults::svFaildEmptyObject;

		case enMode::UpdateMode:
			_Update();
			return enSaveResults::svSucceeded;

		case enMode::AddNewMode:
			if (IsUserExist(_Username))
				return enSaveResults::svFaildUsernameExists;
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode; // changing the mode from AddNew to Update mode
				return enSaveResults::svSucceeded;
			}
		}
	}

	bool CheckAccessPermission(enPermissions Permission)
	{
		if (Permission == pAll)
			return true;

		if ((Permission & this->Permissions) == Permission)
			return true;
		else
			false;
	}

	void RegisterLogin()
	{
		string LoginRecord = _PrepareLoginRecord();

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << LoginRecord << endl;
			MyFile.close();
		}

	}

	//it calls _LoadLoginDataFromFile() but static and public
	static vector <stLoginData> GetLoginRegisterList()
	{
		return _LoadLoginDataFromFile();
	}

};


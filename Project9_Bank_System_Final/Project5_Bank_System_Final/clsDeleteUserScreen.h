#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsUser.h";
#include "clsInputValidate.h";

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{
private:
	static void _PrintUser(clsUser User)
	{
		//every screen has its own _PrintUser() because the layout might change based on the screen
		cout << "\nUser Card:";
		cout << "\n-------------------------------";
		cout << "\nFirst Name  : " << User.FirstName;
		cout << "\nLast Name   : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUsername    : " << User.Username;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n-------------------------------\n";
	}

	static void _PrintHeader()
	{
		clsScreen::_DrawScreenHeader("\t\t      Delete User");
	}
public:

	static void DeleteUser()
	{
		_PrintHeader();

		string Username = clsInputValidate::ReadString("\nPlease Enter Username : ");

		while (!clsUser::IsUserExist(Username))
		{
			cout << "\nUser with Username [" << Username << "] Not Found!";
			Username = clsInputValidate::ReadString("\nEnter Username: ");
		}

		clsUser User1 = clsUser::Find(Username); //object with a Update Mode
		_PrintUser(User1);

		if (clsInputValidate::Confirm_yn("Are You Sure You Want To Delete This User? y/n : "))
		{
			if (User1.Delete())
			{
				cout << "\nUser Deleted Successfully.\n";
				_PrintUser(User1);
			}
		}
		else
			cout << "\nOperation Canceled, User Was Not Deleted.\n";

	}

};


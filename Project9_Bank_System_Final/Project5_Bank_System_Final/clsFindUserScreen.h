#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsUser.h";
#include "clsInputValidate.h";

class clsFindUserScreen : protected clsScreen
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
		clsScreen::_DrawScreenHeader("\t\t      Find User");
	}

public:

	static void FindUser()
	{
		_PrintHeader();

		string Username = clsInputValidate::ReadString("\nPlease Enter User Username : ");

		while (!clsUser::IsUserExist(Username))
		{
			cout << "\nUser with Username [" << Username << "] Not Found!";
			Username = clsInputValidate::ReadString("\nEnter User Username: ");
		}//will not exit the while loop until user is found

		clsUser User1 = clsUser::Find(Username);

		//no need for this code since we already did a validation
		/*if (User1.isEmpty())
			cout << "\nThis User has been deleted\n";
		else
			cout << "\nUser Found :)\n";
		*/

		cout << "User Found :)\n";
		_PrintUser(User1);

	}

};


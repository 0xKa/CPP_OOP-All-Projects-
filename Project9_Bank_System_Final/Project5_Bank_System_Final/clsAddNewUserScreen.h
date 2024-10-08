#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsUser.h";
#include "clsInputValidate.h";

class clsAddNewUserScreen : protected clsScreen
{
private:

	static int _ReadPermissionsToSet()
	{
		int Permissions = 0;

		if (clsInputValidate::Confirm_yn("\nDo You Want To Give This User Full Access? y/n: "))
			return -1; //or clsUser::pAll
		
		cout << "\n=== Choose What Access You Want To Give This User ===\n";

		if (clsInputValidate::Confirm_yn("Show Client List Access? y/n: "))
			Permissions += clsUser::pListClients;

		if (clsInputValidate::Confirm_yn("Add Clients Access? y/n: "))
			Permissions += clsUser::pAddNewClient;

		if (clsInputValidate::Confirm_yn("Delete Clients Access? y/n: "))
			Permissions += clsUser::pDeleteClient;

		if (clsInputValidate::Confirm_yn("Update Clients Access? y/n: "))
			Permissions += clsUser::pUpdateClient;

		if (clsInputValidate::Confirm_yn("Find Client Access? y/n: "))
			Permissions += clsUser::pFindClient;

		if (clsInputValidate::Confirm_yn("Transactions Access? y/n: "))
			Permissions += clsUser::pTransactions;

		if (clsInputValidate::Confirm_yn("Manage Users Access? y/n: "))
			Permissions += clsUser::pManageUsers;

		if (clsInputValidate::Confirm_yn("Login Register List Access? y/n: "))
			Permissions += clsUser::pLoginRegisterList;
		
		if (clsInputValidate::Confirm_yn("Currency Exchange Access? y/n: "))
			Permissions += clsUser::pCurrencyExchange;
		
		if (Permissions == 511) // <-- 511 is the sum of all permissions 
			Permissions = -1;

		return Permissions;

	}

	static void _ReadUserInfo(clsUser& User)
	{
		User.FirstName = clsInputValidate::ReadString("\nEnter First Name: ");
		User.LastName = clsInputValidate::ReadString("Enter Last Name: ");
		User.Email = clsInputValidate::ReadString("Enter Email: ");
		User.Phone = clsInputValidate::ReadString("Enter Phone Number: ");
		User.Password = clsInputValidate::ReadString("Enter Password: ");
		User.Permissions = _ReadPermissionsToSet();
	}

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
		clsScreen::_DrawScreenHeader("\t\t      Add New User");
	}

public:
	static void AddNewUser()
	{
		_PrintHeader();

		string Username = clsInputValidate::ReadString("\nPlease Enter User Username : ");

		while (clsUser::IsUserExist(Username))
		{
			cout << "\nUser with Username [" << Username << "] Already Exists!";
			Username = clsInputValidate::ReadString("\nEnter Another Username: ");
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(Username); //object with a AddNew Mode

		_ReadUserInfo(NewUser);

		clsUser::enSaveResults SaveResult = NewUser.Save(); //Save() will return enum

		switch (SaveResult)
		{
		case clsUser::svSucceeded:
			cout << "\nAccount Added Successfully :)\n";
			_PrintUser(NewUser);
			break;

		case clsUser::svFaildEmptyObject:
			cout << "\nError, Account was Not Saved because it's Empty :(\n";
			break;

		case clsUser::svFaildUsernameExists:
			cout << "\nError, Account was Not Saved because Username Already Exists :(\n";
			break;
		}
	}

};


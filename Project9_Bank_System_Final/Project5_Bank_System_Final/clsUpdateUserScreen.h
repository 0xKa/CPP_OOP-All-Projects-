#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsUser.h";
#include "clsInputValidate.h";


class clsUpdateUserScreen : protected clsScreen
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
		clsScreen::_DrawScreenHeader("\t\t      Update User");
	}

public:
	static void UpdateUser()
	{
		_PrintHeader();

		string Username = clsInputValidate::ReadString("\nPlease Enter User Username : ");

		while (!clsUser::IsUserExist(Username))
		{
			cout << "\nUser with Username [" << Username << "] Not Found!";
			Username = clsInputValidate::ReadString("\nEnter User Username: ");
		}//will not exit the while loop until user is found

		clsUser User1 = clsUser::Find(Username); //object with a Update Mode
		_PrintUser(User1);

		cout << "\n\nUpdate User Info: ";
		cout << "\n-------------------------------";

		//here we update all the user info// we can update email only, or pincode only, but we  update all 
		_ReadUserInfo(User1); //void ByRef 

		clsUser::enSaveResults SaveResult = User1.Save(); //Save() will return enum

		switch (SaveResult)
		{
		case clsUser::svSucceeded:
			cout << "\nAccount Updated Successfully :)\n";
			_PrintUser(User1);
			break;

		case clsUser::svFaildEmptyObject:
			cout << "\nError, Account was Not Saved because it's Empty:(\n";
			break;
		}

	}


};


#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsUsersListScreen.h";
#include "clsAddNewUserScreen.h";
#include "clsDeleteUserScreen.h";
#include "clsUpdateUserScreen.h";
#include "clsFindUserScreen.h";

using namespace std;

class clsManageUsersScreen : protected clsScreen
{
private:
	enum _enManageUsersMenuOption
	{
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eBackToMainMenu = 6
	};
	static _enManageUsersMenuOption _ReadManageUsersMenuOption()
	{
		cout << clsUtil::Tabs(5) << "     ";
		short choice = clsInputValidate::ReadNumberBetween <int> (1, 6, "Choose What To Do (1 - 6) : ");
		return _enManageUsersMenuOption(choice);

	}

	static void _GoBackToManageUsersMenu()
	{
		cout << "Press any key to go back to Manage Users Menu...";
		system("pause>0");
		ShowManageUsersMenu();
	}

	static void _ShowUsersListScreen()
	{
		clsUsersListScreen::PrintUsersList();
	}

	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::AddNewUser();
	}

	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::DeleteUser();
	}

	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::UpdateUser();
	}

	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::FindUser();
	}

	static void _PerformManageUsersOption(_enManageUsersMenuOption Option)
	{
		switch (Option)
		{
		case clsManageUsersScreen::eListUsers:
			system("cls");
			_ShowUsersListScreen();
			break;
			
		case clsManageUsersScreen::eAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			break;

		case clsManageUsersScreen::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			break;

		case clsManageUsersScreen::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			break;

		case clsManageUsersScreen::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			break;

		case clsManageUsersScreen::eBackToMainMenu:
			return;

		}

		_GoBackToManageUsersMenu();
	}

public:
	static void ShowManageUsersMenu()
	{
		system("cls");
		clsScreen::_DrawScreenHeader("\t\t       Bank Users");

		cout << setw(37) << left << "" << "\t|======================================|\n";
		cout << setw(37) << left << "" << "\t|             Manage Users             |\n";
		cout << setw(37) << left << "" << "\t|======================================|\n";
		cout << setw(37) << left << "" << "\t|                                      |\n";
		cout << setw(37) << left << "" << "\t|---[1] Show Users List.               |\n";
		cout << setw(37) << left << "" << "\t|---[2] Add New User.                  |\n";
		cout << setw(37) << left << "" << "\t|---[3] Delete User.                   |\n";
		cout << setw(37) << left << "" << "\t|---[4] Update User.                   |\n";
		cout << setw(37) << left << "" << "\t|---[5] Find User.                     |\n";
		cout << setw(37) << left << "" << "\t|---[6] Back To Main Menu.             |\n";
		cout << setw(37) << left << "" << "\t|                                      |\n";
		cout << setw(37) << left << "" << "\t|======================================|\n";

		_PerformManageUsersOption(_ReadManageUsersMenuOption());

	}


};


#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h";
#include "clsScreen.h";
#include "clsClientListScreen.h";
#include "clsAddNewClientScreen.h";
#include "clsDeleteClientScreen.h";
#include "clsUpdateClientScreen.h";
#include "clsFindClientScreen.h";
#include "clsTransactionsScreen.h";
#include "clsManageUsersScreen.h";
#include "clsLoginScreen.h";
#include "Global.h";
#include "clsUser.h";
#include "clsLoginRegisterScreen.h";
#include "clsCurrencyExchangeScreen.h";

using namespace std;

class clsMainScreen : protected clsScreen
{
private:
	enum _enMainMenuOption
	{
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eTransactions = 6,
		eManageUsers = 7, eLoginRegisterList = 8, eCurrencyExchange = 9, eLogout = 10
	};
	static _enMainMenuOption _ReadMainMenuOption()
	{
		cout << clsUtil::Tabs(5) << "     ";
		short choice = clsInputValidate::ReadNumberBetween <int>(1, 10, "Choose What To Do (1 - 10) : ");
		return _enMainMenuOption(choice);
	}

	static void _GoBackToMainMenu()
	{
		cout << "Press any key to go back to Main Menu...";
		system("pause>0");
		ShowMainMenu();
	}

	static void _ShowClientsListScreen()
	{
		clsClientsListScreen::PrintClientList();
	}

	static void _ShowAddNewClientScreen()
	{
		clsAddNewClientScreen::AddNewClient();
	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::DeleteClient();
	}

	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::UpdateClient();
	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::FindClient();
	}

	static void _ShowTransactionsScreen()
	{
		clsTransactionsScreen::ShowTransactionsMenu();
	}

	static void _ShowManageUsersScreen()
	{
		clsManageUsersScreen::ShowManageUsersMenu();
	}
	
	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterScreen::PrintLoginRegisterList();
	}

	static void _ShowCurrencyExchangeScreen()
	{
		clsCurrencyExchangeScreen::ShowCurrencyExchangeMenu();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("",""); //emptying the CuurentUser
		cout << "------User Loged out------\n";

	}

	static void _PerformMainMenuOption(_enMainMenuOption Option)
	{
		system("cls");
		switch (Option)
		{
		case clsMainScreen::eListClients:
			if (!_isAccessAllows(clsUser::enPermissions::pListClients)) break; //checks the permission
			_ShowClientsListScreen();
			break;

		case clsMainScreen::eAddNewClient:
			if (!_isAccessAllows(clsUser::enPermissions::pAddNewClient)) break;
			_ShowAddNewClientScreen();
			break;

		case clsMainScreen::eDeleteClient:
			if (!_isAccessAllows(clsUser::enPermissions::pDeleteClient)) break;
			_ShowDeleteClientScreen();
			break;

		case clsMainScreen::eUpdateClient:
			if (!_isAccessAllows(clsUser::enPermissions::pUpdateClient)) break;
			_ShowUpdateClientScreen();
			break;

		case clsMainScreen::eFindClient:
			if (!_isAccessAllows(clsUser::enPermissions::pFindClient)) break;
			_ShowFindClientScreen();
			break;

		case clsMainScreen::eTransactions:
			if (!_isAccessAllows(clsUser::enPermissions::pTransactions)) break;
			_ShowTransactionsScreen();
			break;

		case clsMainScreen::eManageUsers:
			if (!_isAccessAllows(clsUser::enPermissions::pManageUsers)) break;
			_ShowManageUsersScreen();
			break;

		case clsMainScreen::eLoginRegisterList:
			if (!_isAccessAllows(clsUser::enPermissions::pLoginRegisterList)) break;
			_ShowLoginRegisterScreen();
			break;

		case clsMainScreen::eCurrencyExchange:
			if (!_isAccessAllows(clsUser::enPermissions::pCurrencyExchange)) break;
			_ShowCurrencyExchangeScreen();
			break;

		case clsMainScreen::eLogout:
			_Logout();
			return; //return to exit the func

		}

		_GoBackToMainMenu();
	}

	static void _PrintHeader()
	{
		string Title = "\t\t      Bank Project";
		//string SubTitle = "\t\t  Logged in as \"" + CurrentUser.Username + "\"";

		clsScreen::_DrawScreenHeader(Title);
	}

public:
	static void ShowMainMenu()
	{
		system("cls");
		_PrintHeader();

		cout << setw(37) << left << "" << "\t|======================================|\n";
		cout << setw(37) << left << "" << "\t|            Manage Clients            |\n";
		cout << setw(37) << left << "" << "\t|======================================|\n";
		cout << setw(37) << left << "" << "\t|                                      |\n";
		cout << setw(37) << left << "" << "\t|---[1]  Show CLients List.            |\n";
		cout << setw(37) << left << "" << "\t|---[2]  Add New Client.               |\n";
		cout << setw(37) << left << "" << "\t|---[3]  Delete Client.                |\n";
		cout << setw(37) << left << "" << "\t|---[4]  Update Client.                |\n";
		cout << setw(37) << left << "" << "\t|---[5]  Find Client.                  |\n";
		cout << setw(37) << left << "" << "\t|---[6]  Transactions.                 |\n";
		cout << setw(37) << left << "" << "\t|---[7]  Manage Users.                 |\n";
		cout << setw(37) << left << "" << "\t|---[8]  Login Register List.          |\n";
		cout << setw(37) << left << "" << "\t|---[9]  Currency Exchange.            |\n";
		cout << setw(37) << left << "" << "\t|---[10] Logout.                       |\n";
		cout << setw(37) << left << "" << "\t|                                      |\n";
		cout << setw(37) << left << "" << "\t|======================================|\n";

		_PerformMainMenuOption(_ReadMainMenuOption());
	}

};


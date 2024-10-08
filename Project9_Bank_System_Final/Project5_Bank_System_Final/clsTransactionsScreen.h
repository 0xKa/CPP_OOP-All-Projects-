#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h";
#include "clsScreen.h";
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h";
#include "clsTotalBalancesScreen.h";
#include "clsTransferScreen.h";
#include "clsTransferLogScreen.h";

class clsTransactionsScreen : protected clsScreen
{
private: 
	enum _enTransactionsMenuOption
	{
		eDeposit = 1, eWithdraw = 2, eTotalBalances = 3, eTransfer = 4, eTransferLog = 5, eBackToMainMenu = 6
	};
	static _enTransactionsMenuOption _ReadTransactionsMenuOption()
	{
		cout << clsUtil::Tabs(5) << "     ";
		short choice = clsInputValidate::ReadNumberBetween <int> (1, 6, "Choose What To Do (1 - 6) : ");
		return _enTransactionsMenuOption(choice);
	}
	
	static void _GoBackToTransactionsMenu()
	{
		cout << "Press any key to go back to Transactions Menu...";
		system("pause>0");
		ShowTransactionsMenu();
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::Deposit();
	}
	
	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::Withdraw();
	}
	
	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::PrintTotalBalances();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::Transfer();
	}
	
	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::PrintTransferLog();
	}

	static void _PerformTransactionsMenuOption(_enTransactionsMenuOption Option)
	{
		switch (Option)
		{
		case clsTransactionsScreen::eDeposit:
			system("cls");
			_ShowDepositScreen();
			break;

		case clsTransactionsScreen::eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			break;

		case clsTransactionsScreen::eTotalBalances:
			system("cls");
			_ShowTotalBalancesScreen();
			break;

		case clsTransactionsScreen::eTransfer:
			system("cls");
			_ShowTransferScreen();
			break;

		case clsTransactionsScreen::eTransferLog:
			system("cls");
			_ShowTransferLogScreen();
			break;

		case clsTransactionsScreen::eBackToMainMenu:
			return;
		}
		_GoBackToTransactionsMenu();
	}

public:

	static void ShowTransactionsMenu()
	{
		system("cls");
		clsScreen::_DrawScreenHeader("\t\t    Bank Transactions");

		cout << setw(37) << left << "" << "\t|======================================|\n";
		cout << setw(37) << left << "" << "\t|           Transactions Menu          |\n";
		cout << setw(37) << left << "" << "\t|======================================|\n";
		cout << setw(37) << left << "" << "\t|                                      |\n";
		cout << setw(37) << left << "" << "\t|---[1] Deposit.                       |\n";
		cout << setw(37) << left << "" << "\t|---[2] Withdraw.                      |\n";
		cout << setw(37) << left << "" << "\t|---[3] Total Balances.                |\n";
		cout << setw(37) << left << "" << "\t|---[4] Transfer.                      |\n";
		cout << setw(37) << left << "" << "\t|---[5] Transfer Log.                  |\n";
		cout << setw(37) << left << "" << "\t|---[6] Back To Main Menu.             |\n";
		cout << setw(37) << left << "" << "\t|                                      |\n";
		cout << setw(37) << left << "" << "\t|======================================|\n";

		_PerformTransactionsMenuOption(_ReadTransactionsMenuOption());
	}


};


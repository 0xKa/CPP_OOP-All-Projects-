#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h";
#include "clsScreen.h";
#include "clsBankClient.h"
using namespace std;


class clsTransferScreen : protected clsScreen
{
private:
	static string _ReadAccountNumber()
	{
		string AccountNumber = clsInputValidate::ReadString("\nEnter Client Account Number to Transfer From: ");

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with Account Number [" << AccountNumber << "] Not Found!";
			AccountNumber = clsInputValidate::ReadString("\nEnter Client Account Number to Transfer From: ");
		}//will not exit the while loop until client is found

		return AccountNumber;
	}

	static void _PrintClient(clsBankClient Client)
	{
		//every screen has its own _PrintClient() because the layout might change based on the screen
		cout << "\nClient " << Client.GetAccountNumber() << " Card:";
		cout << "\n-------------------------------";
		cout << "\nAcc. Number : " << Client.GetAccountNumber();
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nBalance     : $" << Client.AccountBalance;
		cout << "\n-------------------------------\n";
	}

	static void _PrintHeader()
	{
		clsScreen::_DrawScreenHeader("\t\t\tTransfer");
	}

public:

	static void Transfer()
	{
		_PrintHeader();

		string AccountNumber = _ReadAccountNumber();

		clsBankClient FromClient = clsBankClient::Find(AccountNumber);
		_PrintClient(FromClient);
		
		AccountNumber = _ReadAccountNumber();

		clsBankClient ToClient = clsBankClient::Find(AccountNumber);
		_PrintClient(ToClient);

		float TransferAmount = clsInputValidate::
			ReadNumberBetween <float> (1, FromClient.AccountBalance, "Please Enter a Suffecient Transfer Amount: ");

		if (clsInputValidate::Confirm_yn("Are You Sure You Want To Perform This Transaction?"))
		{
			FromClient.TransferTo(ToClient, TransferAmount, CurrentUser.Username);
			cout << "\nTransfer Done Successfully. Account Balances Updated.\n";

			_PrintClient(FromClient);
			_PrintClient(ToClient);
		}
		else
			cout << "\nTransfer Operation is Canceled\n";

	}
};


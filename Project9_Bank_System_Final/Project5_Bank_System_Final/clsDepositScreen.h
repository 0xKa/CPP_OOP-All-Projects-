#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h";
#include "clsScreen.h";
#include "clsBankClient.h"
using namespace std;


class clsDepositScreen : protected clsScreen
{
private:
	static string _ReadAccountNumber()
	{
		string AccountNumber = clsInputValidate::ReadString("\nPlease Enter Client Account Number : ");

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with Account Number [" << AccountNumber << "] Not Found!";
			AccountNumber = clsInputValidate::ReadString("\nEnter Client Account Number: ");
		}//will not exit the while loop until client is found

		return AccountNumber;
	}

	static void _PrintClient(clsBankClient Client)
	{
		//every screen has its own _PrintClient() because the layout might change based on the screen
		cout << "\nClient Card:";
		cout << "\n-------------------------------";
		cout << "\nAcc. Number : " << Client.GetAccountNumber();
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nEmail       : " << Client.Email;
		cout << "\nBalance     : $" << Client.AccountBalance;
		cout << "\n-------------------------------\n";
	}

	static void _PrintHeader()
	{
		clsScreen::_DrawScreenHeader("\t\t\t Deposit");
	}

public:
	
	static void Deposit()
	{
		_PrintHeader();

		string AccountNumber = _ReadAccountNumber();

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		float Amount = clsInputValidate::ReadPositiveNumber <float>("Enter Deposit Amount: ");

		if (clsInputValidate::Confirm_yn("Are You Sure You Want To Perform This Transaction?"))
		{
			Client1.Deposit(Amount);
			cout << "\nDeposit Done Successfully. New Balance is $" << Client1.AccountBalance << endl;
		}
		else
			cout << "\nDeposit Operation is Canceled\n";
	}

};


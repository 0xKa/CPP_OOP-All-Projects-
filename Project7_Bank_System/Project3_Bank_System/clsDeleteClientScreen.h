#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsInputValidate.h";

using namespace std;


class clsDeleteClientScreen : protected clsScreen
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
		cout << "\nFirst Name  : " << Client.FirstName;
		cout << "\nLast Name   : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.GetAccountNumber();
		cout << "\nPIN Code    : " << Client.PinCode;
		cout << "\nBalance     : $" << Client.AccountBalance;
		cout << "\n-------------------------------\n";
	}

	static void _PrintHeader()
	{
		clsScreen::_DrawScreenHeader("\t\t      Delete Client");
	}

public:

	static void DeleteClient()
	{
		_PrintHeader();

		string AccountNumber = _ReadAccountNumber();

		clsBankClient Client1 = clsBankClient::Find(AccountNumber); //object with a Update Mode
		_PrintClient(Client1);

		if (clsInputValidate::Confirm_yn("Are You Sure You Want To Delete This Client? y/n : "))
		{
			if (Client1.Delete())
			{
				cout << "\nClient Deleted Successfully.\n";
				_PrintClient(Client1);
			}
		}
		else
			cout << "\nOperation Canceled, Client Was Not Deleted.\n";

	}

};


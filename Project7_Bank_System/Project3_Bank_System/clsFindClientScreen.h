#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsInputValidate.h";


class clsFindClientScreen : protected clsScreen
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
		clsScreen::_DrawScreenHeader("\t\t      Find Client");
	}

public:

	static void FindClient()
	{
		_PrintHeader();

		string AccountNumber = _ReadAccountNumber();

		clsBankClient Client1 = clsBankClient::Find(AccountNumber); 

		//no need for this code since we already did a validation
		/*if (Client1.isEmpty())
			cout << "\nThis Client has been deleted\n";
		else
			cout << "\nClient Found :)\n";
		*/

		cout << "Client Found :)\n";
		_PrintClient(Client1);

	}
};


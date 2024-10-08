#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsInputValidate.h";


class clsUpdateClientScreen : protected clsScreen
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

	static void _ReadClientInfo(clsBankClient& Client)
	{
		//client Account Number must no change
		Client.FirstName = clsInputValidate::ReadString("\nEnter First Name: ");
		Client.LastName = clsInputValidate::ReadString("Enter Last Name: ");
		Client.Email = clsInputValidate::ReadString("Enter Email: ");
		Client.Phone = clsInputValidate::ReadString("Enter Phone Number: ");
		Client.PinCode = clsInputValidate::ReadString("Enter PIN Code: ");
		Client.AccountBalance = clsInputValidate::ReadPositiveNumber <float>("Enter Account Balance: ");
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
		clsScreen::_DrawScreenHeader("\t\t      Update Client");
	}

public:

	static void UpdateClient()
	{
		_PrintHeader();

		string AccountNumber = _ReadAccountNumber();

		clsBankClient Client1 = clsBankClient::Find(AccountNumber); //object with a Update Mode
		_PrintClient(Client1);

		cout << "\n\nUpdate Client Info: ";
		cout << "\n-------------------------------";

		//here we update all the client info// we can update email only, or pincode only, but update all 
		_ReadClientInfo(Client1); //void ByRef 

		clsBankClient::enSaveResults SaveResult = Client1.Save(); //Save() will return enum

		switch (SaveResult)
		{
		case clsBankClient::svSucceeded:
			cout << "\nAccount Updated Successfully :)\n";
			_PrintClient(Client1);
			break;

		case clsBankClient::svFaildEmptyObject:
			cout << "\nError, Account was Not Saved because it's Empty:(\n";
			break;
		}

	}


};


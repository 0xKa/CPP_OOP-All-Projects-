#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsUtil.h";

using namespace std;

class clsClientsListScreen : protected clsScreen
{
private:
	static void _PrintClientRecordLine(clsBankClient C)
	{
		cout << clsUtil::Tabs(2);
		cout << "|" << left << setw(10) << C.GetAccountNumber();
		cout << "|" << left << setw(22) << C.FullName();
		cout << "|" << left << setw(12) << C.Phone;
		cout << "|" << left << setw(18) << C.Email;
		cout << "|" << left << setw(6) << C.PinCode;
		cout << "|" << left << setw(19) << "$" + to_string(C.AccountBalance);
		cout << "|";
	}

	static void _PrintHeader(vector <clsBankClient> vClients)
	{
		string Title = "\t\t      Clients List";
		string SubTitle = "\t\t     [" + to_string(vClients.size()) + "] Client(s).";

		clsScreen::_DrawScreenHeader(Title, SubTitle);
	}

public:
	static void PrintClientList()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		_PrintHeader(vClients);

		if (vClients.size() == 0)
		{
			cout << clsUtil::Tabs(5) << "   No Clients Available In the System!\n\n";
		}
		else
		{
			cout << endl << clsUtil::Tabs(2) << "|============================================================================================|\n" << clsUtil::Tabs(2);

			cout << "|" << left << setw(10) << " Acc. No. ";
			cout << "|" << left << setw(22) << " Client Name ";
			cout << "|" << left << setw(12) << " Phone ";
			cout << "|" << left << setw(18) << " Email ";
			cout << "|" << left << setw(6)  << " PIN ";
			cout << "|" << left << setw(19) << " Balance " << "|";
		
			cout << endl << clsUtil::Tabs(2) << "|============================================================================================|\n";

			for (clsBankClient C : vClients)
			{
				_PrintClientRecordLine(C);
				cout << "\n";
			}

			cout << endl << clsUtil::Tabs(2) <<	"|============================================================================================|\n";
		}

	}


};


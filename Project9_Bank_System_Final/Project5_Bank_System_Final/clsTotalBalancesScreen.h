#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h";
#include "clsScreen.h";
#include "clsBankClient.h"
using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{
private:
	static void _PrintClientBalanceRecordLine(clsBankClient C)
	{
		cout << clsUtil::Tabs(3) <<	"      ";
		cout << "|" << left << setw(12) << C.GetAccountNumber();
		cout << "|" << left << setw(22) << C.FullName();
		cout << "|" << left << setw(23) << "$" + to_string(C.AccountBalance);
		cout << "|";
	}

	static void _PrintHeader(vector <clsBankClient> vClients)
	{
		string Title = "\t\t     Total Balances";
		string SubTitle = "\t\t     [" + to_string(vClients.size()) + "] Client(s).";

		clsScreen::_DrawScreenHeader(Title, SubTitle);
	}

public:
	static void PrintTotalBalances()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		_PrintHeader(vClients);

		if (vClients.size() == 0)
			cout << endl << clsUtil::Tabs(5) << "----No Clients Available In the System!----\n";
		else
		{
			cout << endl << clsUtil::Tabs(6) <<	"     Clients List" ;

			cout << endl << clsUtil::Tabs(3) <<
				"      |===========================================================|\n";

			cout << clsUtil::Tabs(3) << "      ";
			cout << "|" << left << setw(12) << " Acc. No. ";
			cout << "|" << left << setw(22) << " Client Name ";
			cout << "|" << left << setw(23) << " Balance " << "|";
			
			cout << endl << clsUtil::Tabs(3) <<
				"      |===========================================================|\n";

			for (clsBankClient C : vClients)
			{
				_PrintClientBalanceRecordLine(C);
				cout << endl;
			}

			cout << endl << clsUtil::Tabs(3) <<
				"      |===========================================================|\n";

			float TotalBalances = clsBankClient::GetTotalBalances();

			cout << clsUtil::Tabs(3) << "      ";
			cout << "                  Total Balances = $" << TotalBalances << endl;

			cout << clsUtil::Tabs(3) << "     ";
			cout << "( " << clsUtil::NumberToText(TotalBalances) << ")" << endl;

		}

	}

};


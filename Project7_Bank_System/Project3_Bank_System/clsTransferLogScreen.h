#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsUtil.h";

using namespace std;

class clsTransferLogScreen : protected clsScreen
{
private:
	static void _PrintTransferDataRecordLine(clsBankClient::stTransferData TD)
	{
		cout << clsUtil::Tabs(2);
		cout << "|" << left << setw(22) << TD.TransferDateTime;
		cout << "|" << left << setw(6) << TD.SourceAccNum;
		cout << "|" << left << setw(6) << TD.DestinationAccNum;
		cout << "|" << left << setw(14) << to_string(TD.TransferAmount);
		cout << "|" << left << setw(15) << to_string(TD.SourceBalance);
		cout << "|" << left << setw(15) << to_string(TD.DestinationBalance);
		cout << "|" << left << setw(7) << TD.Username;
		cout << " |";
	}

	static void _PrintHeader(vector <clsBankClient::stTransferData> vTransferData)
	{
		string Title = "\t\t      Transfer Log";
		string SubTitle = "\t\t     [" + to_string(vTransferData.size()) + "] Records(s).";

		clsScreen::_DrawScreenHeader(Title, SubTitle);
	}


public:

	static void PrintTransferLog()
	{
		vector <clsBankClient::stTransferData> vTransferData = clsBankClient::GetTransferLog();
		_PrintHeader(vTransferData);

		if (vTransferData.size() == 0)
		{
			cout << clsUtil::Tabs(5) << "  No Records Available In the System!\n\n";
		}
		else
		{
			cout << endl << clsUtil::Tabs(2) << "|============================================================================================|\n" << clsUtil::Tabs(2);

			cout << "|" << left << setw(22) << " Date & Time ";
			cout << "|" << left << setw(6) << "s.Acc ";
			cout << "|" << left << setw(6) << "d.Acc ";
			cout << "|" << left << setw(14) << " Amount ";
			cout << "|" << left << setw(15) << " s.Balance ";
			cout << "|" << left << setw(15) << " d.Balance ";
			cout << "|" << left << setw(7) << " User " << " |";

			cout << endl << clsUtil::Tabs(2) << "|============================================================================================|\n";

			for (clsBankClient::stTransferData TransferData : vTransferData)
			{
				_PrintTransferDataRecordLine(TransferData);
				cout << "\n";
			}

			cout << endl << clsUtil::Tabs(2) << "|============================================================================================|\n";
		}

	}
};


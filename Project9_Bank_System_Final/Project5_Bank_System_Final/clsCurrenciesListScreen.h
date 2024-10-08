#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "clsScreen.h";
#include "clsCurrency.h";

using namespace std;


class clsCurrenciesListScreen : protected clsScreen
{
private:

	static void _PrintCurrencyRecordLine(clsCurrency C)
	{
		cout << clsUtil::Tabs(2);
		cout << "|" << left << setw(35) << C.GetCountry();
		cout << "| " << left << setw(9) << C.GetCode();
		cout << "|" << left << setw(29) << C.GetName();
		cout << "|" << left << setw(15) << to_string(C.GetRate());
		cout << "|";
	}

	static void _PrintHeader(vector <clsCurrency> vCurrencys)
	{
		string Title = "\t\t     Currencies List";
		string SubTitle = "\t\t     [" + to_string(vCurrencys.size()) + "] Currencies.";

		clsScreen::_DrawScreenHeader(Title, SubTitle);
	}

public:

	static void PrintCurrenciesList()
	{
		vector <clsCurrency> vCurrencys = clsCurrency::GetCurrenciesList();
		_PrintHeader(vCurrencys);

		if (vCurrencys.size() == 0)
		{
			cout << clsUtil::Tabs(5) << "  No Currencies Available In the System!\n\n";
		}
		else
		{
			cout << endl << clsUtil::Tabs(2) << "|============================================================================================|\n" << clsUtil::Tabs(2);

			cout << "|" << left << setw(35) << " Country ";
			cout << "|" << left << setw(10) << " Code ";
			cout << "|" << left << setw(29) << " Name ";
			cout << "|" << left << setw(15) << " Rate/(1$) " << "|";

			cout << endl << clsUtil::Tabs(2) << "|============================================================================================|\n";

			for (clsCurrency C : vCurrencys)
			{
				_PrintCurrencyRecordLine(C);
				cout << "\n";
			}

			cout << endl << clsUtil::Tabs(2) << "|============================================================================================|\n";
		}

	}

};


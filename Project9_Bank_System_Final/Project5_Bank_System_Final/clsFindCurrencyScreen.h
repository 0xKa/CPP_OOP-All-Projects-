#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsCurrency.h";
#include "clsInputValidate.h";


class clsFindCurrencyScreen : protected clsScreen
{
private:
	enum _FindingCurrencyMethod { eByCode = 1, eByCountryName = 2 };

	static void _PrintCurrencyInfo(clsCurrency C)
	{
		cout << "\Currency Information:";
		cout << "\n-------------------------------";
		cout << "\nCountry     : " << C.GetCountry();
		cout << "\nCode        : " << C.GetCode();
		cout << "\nName        : " << C.GetName();
		cout << "\nRate(1$)    : " << C.GetRate();
		cout << "\n-------------------------------\n";
	}

	static void _ShowResult(clsCurrency C)
	{
		if (C.isEmpty())
			cout << "\nCurrency Not Found :(\n";
		else
		{
			cout << "\nCurrency Found :)\n";
			_PrintCurrencyInfo(C);
		}
	}

	static void _PrintHeader()
	{
		clsScreen::_DrawScreenHeader("\t\t     Find Currency");
	}
public:

	static void FindCurrency()
	{
		_PrintHeader();

		_FindingCurrencyMethod FindingMethod = (_FindingCurrencyMethod)
			clsInputValidate::ReadNumberBetween <int> (1, 2, "Find By: \n[1]-Currency Code \n[2]-Country Name \nChoose: ");

		if (FindingMethod == eByCode)
		{
			clsCurrency C = clsCurrency::FindByCode(clsInputValidate::ReadString("Enter Currency Code: "));
			_ShowResult(C);
		}
		else /*(FindingMethod == eByCountryName)*/

		{
			clsCurrency C = clsCurrency::FindByCountry(clsInputValidate::ReadString("Enter Country Name: "));
			_ShowResult(C);
		}

	}

};


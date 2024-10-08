#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsCurrency.h";
#include "clsInputValidate.h";

using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:

	static string _ReadCurrencyCode()
	{
		string CurrencyCode = clsInputValidate::ReadString("Enter Currency Code: ");

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Code Not Found!\n";
			CurrencyCode = clsInputValidate::ReadString("Enter Currency Code: ");
		}

		return CurrencyCode;
	}

	static void _PrintCurrencyInfo(clsCurrency C)
	{
		cout << "\nCurrency Information:";
		cout << "\n-------------------------------";
		cout << "\nCountry     : " << C.GetCountry();
		cout << "\nCode        : " << C.GetCode();
		cout << "\nName        : " << C.GetName();
		cout << "\nRate(1$)    : " << C.GetRate();
		cout << "\n-------------------------------\n";
	}

	static void _PrintHeader()
	{
		system("cls");
		clsScreen::_DrawScreenHeader("\t\t   Currency Calculator");
	}

public:

	static void CurrencyCalculator()
	{
		do 
		{
			_PrintHeader();

			string CurrencyCode = _ReadCurrencyCode();
			clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
			_PrintCurrencyInfo(C1);
		
			CurrencyCode = _ReadCurrencyCode();
			clsCurrency C2 = clsCurrency::FindByCode(CurrencyCode);
			_PrintCurrencyInfo(C2);
		
			cout << "\n-------Convert From [" << C1.GetCode() << "] To [" << C2.GetCode() << "]-------\n";

			float C1ExchangeAmount = clsInputValidate::ReadPositiveNumber <float> ("Enter Amount To Exchange: ");

			// C2.amount = C1.amount * (C2.rate/C1.rate)
			float C2ExchangeAmount = C1.ExchangeTo(C2, C1ExchangeAmount);

			cout << "\n[" << C1ExchangeAmount << " " << C1.GetCode()
				<< "] = [" << C2ExchangeAmount << " " << C2.GetCode() << "]\n";

		} while (clsInputValidate::Confirm_yn("Do you want to perform another calcalation? y/n:"));

	}

};


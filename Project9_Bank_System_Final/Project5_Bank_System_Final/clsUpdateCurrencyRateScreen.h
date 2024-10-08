#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsCurrency.h";
#include "clsInputValidate.h";


class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:

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
		clsScreen::_DrawScreenHeader("\t\t   Update Currency Rate");
	}

public:

	static void UpdateCurrencyRate()
	{
		_PrintHeader();

		string CurrencyCode = clsInputValidate::ReadString("Enter Currency Code: ");

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Code Not Found!\n";
			CurrencyCode = clsInputValidate::ReadString("Enter Currency Code: ");
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrencyInfo(Currency);

		if (clsInputValidate::Confirm_yn("Are you sure you want to update the Rate of this Currency? : "))
		{
			cout << "\n-------Updating the Currency Rate...-------\n";
			
			float NewRate = clsInputValidate::ReadPositiveNumber <float>("Enter New Rate: ");
			Currency.UpdateRate(NewRate);

			cout << "\n-------Rate Updated Successfully :)--------\n";
			
			_PrintCurrencyInfo(Currency);
		}
		else
			cout << "\nUpdating Operation Canceled.\n";


	}

};


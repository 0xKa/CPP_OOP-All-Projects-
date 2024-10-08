// Project5: Bank System + Currency Exchange
#include <iostream>
#include "clsLoginScreen.h";
using namespace std;

//temp function, for UI classes later
//static void _PrintCurrency(clsCurrency Currency)
//{
//	cout << "\nCurrency Card:\n";
//	cout << "_____________________________\n";
//	cout << "\nCountry    : " << Currency.GetCountry();
//	cout << "\nCode       : " << Currency.GetCode();
//	cout << "\nName       : " << Currency.GetName();
//	cout << "\nRate(1$) = : " << Currency.GetRate();
//
//	cout << "\n_____________________________\n";
//
//}


#include "clsInputValidate.h";
int main()
{

	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
			break;
	}

	cout << "\n\n\n--[Main End]--";
	return 0;
}

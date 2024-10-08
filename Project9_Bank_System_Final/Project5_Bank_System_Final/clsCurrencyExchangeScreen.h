#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h";
#include "clsCurrenciesListScreen.h";
#include "clsFindCurrencyScreen.h";
#include "clsUpdateCurrencyRateScreen.h";
#include "clsCurrencyCalculatorScreen.h";
using namespace std;

class clsCurrencyExchangeScreen : protected clsScreen
{
private:
	enum _enCurrencyExchangeMenuOption
	{
		eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
		eCurrencyCalculator = 4, eBackToMainMenu = 5
	};
	static _enCurrencyExchangeMenuOption _ReadCurrencyExchangeMenuOption()
	{
		cout << clsUtil::Tabs(5) << "     ";
		short choice = clsInputValidate::ReadNumberBetween <int> (1, 5, "Choose What To Do (1 - 5) : ");
		return _enCurrencyExchangeMenuOption(choice);

	}

	static void _GoBackToCurrencyExchangeMenu()
	{
		cout << "Press any key to go back to Currency Exchange Menu...";
		system("pause>0");
		ShowCurrencyExchangeMenu();
	}

	static void _ShowCurrenciesListScreen()
	{
		clsCurrenciesListScreen::PrintCurrenciesList();
	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::FindCurrency();
	}

	static void _ShowUpdateRateScreen()
	{
		clsUpdateCurrencyRateScreen::UpdateCurrencyRate();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::CurrencyCalculator();
	}

	static void _PerformCurrencyExchangeOption(_enCurrencyExchangeMenuOption Option)
	{

		switch (Option)
		{
		case clsCurrencyExchangeScreen::eListCurrencies:
			system("cls");
			_ShowCurrenciesListScreen();
			break;

		case clsCurrencyExchangeScreen::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			break;

		case clsCurrencyExchangeScreen::eUpdateRate:
			system("cls");
			_ShowUpdateRateScreen();
			break;

		case clsCurrencyExchangeScreen::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			break;

		case clsCurrencyExchangeScreen::eBackToMainMenu:
			return;
		}
		_GoBackToCurrencyExchangeMenu();
	}

public:
	static void ShowCurrencyExchangeMenu()
	{
		system("cls");
		clsScreen::_DrawScreenHeader("\t\t    Currency Exchange");

		cout << setw(37) << left << "" << "\t|======================================|\n";
		cout << setw(37) << left << "" << "\t|           Currency Exchange          |\n";
		cout << setw(37) << left << "" << "\t|======================================|\n";
		cout << setw(37) << left << "" << "\t|                                      |\n";
		cout << setw(37) << left << "" << "\t|---[1] List Currencies.               |\n";
		cout << setw(37) << left << "" << "\t|---[2] Find Currency.                 |\n";
		cout << setw(37) << left << "" << "\t|---[3] Update Currency Rate.          |\n";
		cout << setw(37) << left << "" << "\t|---[4] Currency Calculator.           |\n";
		cout << setw(37) << left << "" << "\t|---[5] Back To Main Menu.             |\n";
		cout << setw(37) << left << "" << "\t|                                      |\n";
		cout << setw(37) << left << "" << "\t|======================================|\n";

		_PerformCurrencyExchangeOption(_ReadCurrencyExchangeMenuOption());

	}

};


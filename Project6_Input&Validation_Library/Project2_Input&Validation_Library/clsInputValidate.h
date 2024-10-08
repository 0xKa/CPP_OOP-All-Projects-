//class for all input & validation functions // all funcs are static 
#pragma once
#include <iostream>
#include"clsString.h"
#include "clsDate.h";

using namespace std;

class clsInputValidate
{
public:

	//validation funcs
	static bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From && Number <= To) ? true : false;
	}
	static bool IsNumberBetween(float Number, float From, float To)
	{
		return (Number >= From && Number <= To) ? true : false;
	}
	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From && Number <= To) ? true : false;
	}

	static bool IsNumberPositive(int Number)
	{
		return (Number > 0) ? true : false;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}
	static bool IsDateBetween(clsDate Date, clsDate Date1, clsDate Date2)
	{
		if (Date1.Before(Date2))
			return (Date.After(Date1) && Date.Before(Date2)) ? true : false;
		else 
			return (Date.After(Date1) && Date.Before(Date2)) ? false : true;
	}

	//input funcs
	static bool Confirm_yn(string massage)
	{
		char Confirm = 'n';
		cout << endl << massage << endl;
		cin >> Confirm;

		return(tolower(Confirm) == 'y' ? true : false);
	}

	static int ReadInteger(string massage = "Please Enter a Number: ")
	{
		int num = 0;
		cout << massage;
		while (!(cin >> num)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input, " << massage;
		}
		return num;
	}
	static int ReadIntegerBetween(int From, int To, string massage = "Please Enter a Number: ")
	{
		int num = ReadInteger(massage);

		while (!IsNumberBetween(num,From,To))
		{
			cout << "Number Out Of Range, ";
			num = ReadInteger(massage);
		}
		return num;
	}
	static int ReadPositiveInteger(string massage = "Please Enter a Positive Number: ")
	{
		int num = ReadInteger(massage);

		while (!IsNumberPositive(num))
		{
			cout << "Number is Not Positive, ";
			num = ReadInteger(massage);
		}
		return num;
	}

	static double ReadDouble(string massage = "Please Enter a Number: ")
	{
		double num = 0;
		cout << massage;
		while (!(cin >> num)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input, " << massage;
		}
		return num;
	}
	static double ReadDoubleBetween(double From, double To, string massage = "Please Enter a Number: ")
	{
		double num = ReadDouble(massage);

		while (!IsNumberBetween(num, From, To))
		{
			cout << "Number Out Of Range, ";
			num = ReadDouble(massage);
		}
		return num;
	}
	static int ReadPositiveDouble(string massage = "Please Enter a Positive Number: ")
	{
		double num = ReadDouble(massage);

		while (!IsNumberPositive(num))
		{
			cout << "Number is Not Positive, ";
			num = ReadDouble(massage);
		}
		return num;
	}
	
	static string ReadString(string massage)
	{
		string s;
		cout << massage;
		cin >> s;
		return s;
	}


};


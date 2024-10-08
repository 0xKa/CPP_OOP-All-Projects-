#pragma once
#include <iostream>
#include "Global.h";
#include "clsUser.h";
#include "clsDate.h";
using namespace std;

// Screen Golden Rules:
// 1. Every screen in the project must have a seperate class
// 2. Every screen class within the project must inherit clsScreen 
class clsScreen
{
private:
protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << setw(37) << left << ""  << "______________________________________________\n\n";
		cout << setw(37) << left << "" << Title << endl;

		if (SubTitle != "")
			cout << setw(37) << left << "" << SubTitle << endl;
		
		
		cout << setw(37) << left << ""  << "______________________________________________\n\n";



		cout << setw(37) << left << "" << "User Logged in: " << CurrentUser.Username << endl;
		cout << setw(37) << left << "" << clsDate::DateToString(clsDate()) << endl << endl;

	}

	static bool  _isAccessAllows(clsUser::enPermissions Permission)
	{
		if (CurrentUser.CheckAccessPermission(Permission))
			return true;
		else
		{
			_DrawScreenHeader("\t    Access Denied! Contact Your Admin");
			return false;
		}

	}


public:

};


#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsUser.h";
using namespace std;

class clsUsersListScreen : protected clsScreen
{
private:
	static void _PrintUserRecordLine(clsUser C)
	{
		cout << clsUtil::Tabs(2);
		cout << "|" << left << setw(10) << C.Username;
		cout << "|" << left << setw(22) << C.FullName();
		cout << "|" << left << setw(12) << C.Phone;
		cout << "|" << left << setw(18) << C.Email;
		cout << "|" << left << setw(10) << C.Password;
		cout << "|" << left << setw(15) << to_string(C.Permissions);
		cout << "|";
	}

	static void _PrintHeader(vector <clsUser> vUsers)
	{
		string Title = "\t\t      Users List";
		string SubTitle = "\t\t     [" + to_string(vUsers.size()) + "] User(s).";

		clsScreen::_DrawScreenHeader(Title, SubTitle);
	}


public:

	static void PrintUsersList()
	{
		vector <clsUser> vUsers = clsUser::GetUsersList();
		_PrintHeader(vUsers);

		if (vUsers.size() == 0)
		{
			cout << clsUtil::Tabs(5) << "   No Users Available In the System!\n\n";
		}
		else
		{
			cout << endl << clsUtil::Tabs(2) << "|============================================================================================|\n" << clsUtil::Tabs(2);

			cout << "|" << left << setw(10) << " Username ";
			cout << "|" << left << setw(22) << " Full Name ";
			cout << "|" << left << setw(12) << " Phone ";
			cout << "|" << left << setw(18) << " Email ";
			cout << "|" << left << setw(10) << " Password ";
			cout << "|" << left << setw(15) << " Permissions " << "|";

			cout << endl << clsUtil::Tabs(2) << "|============================================================================================|\n";

			for (clsUser U : vUsers)
			{
				_PrintUserRecordLine(U);
				cout << "\n";
			}

			cout << endl << clsUtil::Tabs(2) << "|============================================================================================|\n";
		}

	}

};


#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsUser.h";
#include "clsUtil.h";

using namespace std;

class clsLoginRegisterScreen : protected clsScreen
{
private:
	static void _PrintLoginRegisterRecordLine(clsUser::stLoginData LD)
	{
		cout << clsUtil::Tabs(2);
		cout << "|" << left << setw(35) << LD.LoginDateTime;
		cout << "|" << left << setw(23) << LD.LoginUsername;
		cout << "|" << left << setw(15) << LD.LoginPassword;
		cout << "|" << left << setw(15) << to_string(LD.LoginPermissions);
		cout << " |";
	}

	static void _PrintHeader(vector <clsUser::stLoginData> vLoginData)
	{
		string Title = "\t\t      Login Register";
		string SubTitle = "\t\t     [" + to_string(vLoginData.size()) + "] Records(s).";

		clsScreen::_DrawScreenHeader(Title, SubTitle);
	}


public:

	static void PrintLoginRegisterList()
	{
		vector <clsUser::stLoginData> vLoginData = clsUser::GetLoginRegisterList();
		_PrintHeader(vLoginData);

		if (vLoginData.size() == 0)
		{
			cout << clsUtil::Tabs(5) << "  No Records Available In the System!\n\n";
		}
		else
		{
			cout << endl << clsUtil::Tabs(2) << "|============================================================================================|\n" << clsUtil::Tabs(2);

			cout << "|" << left << setw(35) << " Date & Time ";
			cout << "|" << left << setw(23) << " Username ";
			cout << "|" << left << setw(15) << " Password ";
			cout << "|" << left << setw(15) << " Permissions " << " |";

			cout << endl << clsUtil::Tabs(2) << "|============================================================================================|\n";

			for (clsUser::stLoginData LoginData : vLoginData)
			{
				_PrintLoginRegisterRecordLine(LoginData);
				cout << "\n";
			}

			cout << endl << clsUtil::Tabs(2) << "|============================================================================================|\n";
		}

	}
};


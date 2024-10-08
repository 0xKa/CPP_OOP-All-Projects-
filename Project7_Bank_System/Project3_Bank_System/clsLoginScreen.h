#pragma once
#include <iostream>
#include "Global.h";
#include "clsMainScreen.h";
#include "clsUser.h";
#include "clsInputValidate.h";


class clsLoginScreen : clsScreen
{
private:

	static bool _Login()
	{
		bool LoginFaild = false;
		short LoginAttempts = 3;

		string Username, Password;

		do
		{
			if (LoginFaild)
			{
				cout << "\nInvalid Username/Password! \n";
				cout << "You have " << LoginAttempts << " more attempt(s). \n\n";
			}
			if (LoginAttempts == 0)
			{
				cout << "\n---System Locked, no more Attempts---\n";
				return false;
			}


			Username = clsInputValidate::ReadString("Enter Username: ");
			Password = clsInputValidate::ReadString("Enter Password: ");
		
			LoginAttempts--;
			CurrentUser = clsUser::Find(Username, Password);

			LoginFaild = CurrentUser.isEmpty();

		} while (LoginFaild); //will not exit the loop until login success

		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenu();
		return true;
	}


public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t\t\t Login");
		return (_Login()); //will return true/false 
	}

};


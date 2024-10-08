// Project3 Bank System
#include <iostream>
#include "clsLoginScreen.h";
using namespace std;
	
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


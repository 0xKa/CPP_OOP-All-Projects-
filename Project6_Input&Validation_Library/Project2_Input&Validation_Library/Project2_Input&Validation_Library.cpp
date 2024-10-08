// Project2_Input&Validation_Library.cpp 
#include <iostream>
#include "clsInputValidate.h";

using namespace std;

int main()
{

	cout << clsInputValidate::IsNumberBetween(5, 1, 10) << endl; //true
	cout << clsInputValidate::IsNumberBetween(5.32, 4.5, 5.88) << endl; //true


	cout << clsInputValidate::IsValidDate(clsDate(35, 8, 2024)) << endl; //false

	cout << clsInputValidate::IsDateBetween(
		clsDate(6, 8, 2004), clsDate(1, 1 , 2004), clsDate(1, 1, 2005)) 
		<< endl; //true
	
	cout << clsInputValidate::IsDateBetween(
		clsDate(6, 8, 2004), clsDate(1, 1, 2005), clsDate(1, 1, 2004))
		<< endl << endl; //true

	int num1 = clsInputValidate::ReadInteger("Enter a Number: ");
	cout << "num1 = " << num1 << endl << endl;
	
	int num2 = clsInputValidate::ReadIntegerBetween(10, 20, "Enter a Number Between 10 & 20: ");
	cout << "num2 = " << num2 << endl << endl;

	int num5 = clsInputValidate::ReadPositiveInteger();
	cout << "num5 = " << num5 << endl << endl;
	
	double num3 = clsInputValidate::ReadDouble("Enter a Number:");
	cout << "num3 = " << num3 << endl << endl;
	
	double num4 = clsInputValidate::ReadDoubleBetween(1.5, 3.5, "Enter a Number Between 1.5 & 3.5: ");
	cout << "num4 = " << num4 << endl << endl;

	string s1 = clsInputValidate::ReadString("Enter Your Name: ");
	cout << "s1 = " << s1 << endl;


	cout << endl << endl;
	return 0;
}


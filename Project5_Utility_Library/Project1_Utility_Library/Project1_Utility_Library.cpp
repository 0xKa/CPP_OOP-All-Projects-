//course 11, project1 utility class
#include <iostream>
#include "clsUtil.h";
#include "clsDate.h";
using namespace std;

int main()
{
	clsUtil::Srand();

	cout << "Random Number from 1 to 100: " << clsUtil::RandomNumber(1, 100) << endl << endl;

	cout << "Random: \n";
	cout << "Capital Letter    : " << clsUtil::GetRandomCharacter(clsUtil::enCapitalLetter) << endl;
	cout << "Small Letter      : " << clsUtil::GetRandomCharacter(clsUtil::enSamallLetter) << endl;
	cout << "Special Character : " << clsUtil::GetRandomCharacter(clsUtil::enSpecialCharacter) << endl;
	cout << "Digit             : " << clsUtil::GetRandomCharacter(clsUtil::enDigit) << endl << endl;

	cout << "Generate Word : " << clsUtil::GenerateWord(clsUtil::enMixChars, 4) << endl;
	cout << "Generate Key  : " << clsUtil::GenerateKey() << endl;
	cout << "Generate (5) Keys  : \n"; clsUtil::GenerateKeys(5, clsUtil::enCapitalLetter);

	cout << "\n\nSwapping Int\n";
	int x = 10, y = 20;
	cout << x << " - " << y << endl;
	clsUtil::Swap(x, y);
	cout << x << " - " << y << endl << endl;

	cout << "Swapping double\n";
	double d1 = 99.999, d2 = 2.5;
	cout << d1 << " - " << d2 << endl;
	clsUtil::Swap(d1, d2);
	cout << d1 << " - " << d2 << endl << endl;

	cout << "Swapping String\n";
	string s1 = "Reda", s2 = "Bassam";
	cout << s1 << " - " << s2 << endl;
	clsUtil::Swap(s1, s2);
	cout << s1 << " - " << s2 << endl << endl;

	cout << "Swapping Dates\n";
	clsDate date1(1, 1, 2024), date2(6, 8, 2004);
	cout << clsDate::DateToString(date1) << " - " << clsDate::DateToString(date2) << endl;
	clsUtil::Swap(date1, date2);
	cout << clsDate::DateToString(date1) << " - " << clsDate::DateToString(date2) << endl;

	cout << "\nShuffle Array\n";
	string arrKeys[3];

	cout << "Before Shuffle : ";
	clsUtil::FillArrayWithRandomKeys(arrKeys, 3, clsUtil::enCapitalLetter);
	for (string s : arrKeys)
	{
		cout << s << " / ";
	}

	cout << "\nAfter Shuffle  : ";
	clsUtil::ShuffleArray(arrKeys, 3);
	for (string s : arrKeys)
	{
		cout << s << " / ";
	}

	cout << "\nShuffle Array\n";
	string arrNames[6] = { "reda", "mohammed", "khalid", "ali", "omar", "ahmed" };

	cout << "Before Shuffle : ";
	for (string s : arrNames)
	{
		cout << s << " / ";
	}

	cout << "\nAfter Shuffle  : ";
	clsUtil::ShuffleArray(arrNames, 6);
	for (string s : arrNames)
	{
		cout << s << " / ";
	}


	string text = "Hello, my name is reda :)";
	int EncryptionKey = 69;
	cout << "\n\nText         : " << text << endl;

	text = clsUtil::EncryptText(text, EncryptionKey);
	cout << "Encrypt Text : " << text << endl;

	text = clsUtil::DecryptText(text, EncryptionKey);
	cout << "Decrypt Text : " << text << endl;


	system("pause>0");
	return 0;
}


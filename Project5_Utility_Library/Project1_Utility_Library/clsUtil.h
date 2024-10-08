// this is a utility class all functions are static (don't need an object)
#pragma once
#include <iostream>
#include "clsDate.h";
using namespace std;


class clsUtil
{
private:
	//-
public:
	static void Srand()
	{
		//Seeds the random number generator in C++, called only once
		srand((unsigned)time(NULL));
	}
	
	//RNG funcs
	static int RandomNumber(int FROM, int TO)
	{
		//Function to generate a random number
		int randNum = rand() % (TO - FROM + 1) + FROM;
		return randNum;
	}
	enum enCharType {
		enSamallLetter = 1, enCapitalLetter = 2, 
		enDigit = 3, enSpecialCharacter = 4, enMixChars = 5
	};
	static char GetRandomCharacter(enCharType CharType)
	{
		if (CharType == enMixChars)
			CharType = enCharType(RandomNumber(1, 3)); //capital, small, digits only

		switch (CharType)
		{
		case enCharType::enSamallLetter:
			return char(RandomNumber(97, 122));

		case enCharType::enCapitalLetter:
			return char(RandomNumber(65, 90));

		case enCharType::enSpecialCharacter:
			return char(RandomNumber(33, 47));

		case enCharType::enDigit:
			return char(RandomNumber(48, 57));

		default:
			return char(RandomNumber(65, 90));
		}
	}

	//generate funcs
	static string GenerateWord(enCharType CharType, short Length)
	{
		string Word;
		for (int i = 1; i <= Length; i++)
		{
			Word = Word + GetRandomCharacter(CharType);
		}
		return Word;
	}
	static string GenerateKey(enCharType CharType = enCapitalLetter)
	{
		string Key = "";
		Key = GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4);
		return Key;
	}
	static void GenerateKeys(short NumberOfKeys, enCharType CharType)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : ";
			cout << GenerateKey(CharType) << endl;
		}
	}

	//fill array funcs
	static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = RandomNumber(From, To);
	}
	static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, int WordLength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateWord(CharType, WordLength);
	}
	static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateKey(CharType);
	}


	//swap func all overloads
	static void Swap(int& A, int& B)
	{
		int Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(double& A, double& B)
	{
		double Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(bool& A, bool& B)
	{
		bool Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(string& A, string& B)
	{
		string Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(char& A, char& B)
	{
		char Temp;
		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(clsDate& A, clsDate& B)
	{
		clsDate Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	//shuffle array funcs
	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[i],arr[RandomNumber(1, arrLength - 1)]);
		}
	}
	static void ShuffleArray(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[i], arr[RandomNumber(1, arrLength - 1)]);
		}
	}

	//Encrypt, Decrypt funcs
	static string EncryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	}
	static string DecryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}

	//other...
	static string Tabs(short NumberOfTabs)
	{
		string t = "";

		for (int i = 1; i < NumberOfTabs; i++)
		{
			t = t + "\t";
			cout << t;
		}
		return t;

	}

};


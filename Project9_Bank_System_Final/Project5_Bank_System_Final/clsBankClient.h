//good prctice: seperate the UI code from the Object code
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include "clsPerson.h"; 
#include "clsString.h"; //My String library
#include "Global.h";
#include "clsDate.h";

using namespace std;

string ClientsFile = "Clients.txt";
string GlobalSeperator = "#//#";


//clsBankeClient inherit clsPerson
class clsBankClient : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete = false;

	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = GlobalSeperator)
	{
		vector <string> vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]) );
	}
	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = GlobalSeperator)
	{
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client._AccountNumber + Seperator;
		stClientRecord += Client._PinCode + Seperator;
		stClientRecord += to_string(Client._AccountBalance);

		return stClientRecord;
	}

	static vector <clsBankClient> _LoadClientsDataFromFile()
	{
		vector <clsBankClient> vClients;
		fstream MyFile;

		MyFile.open(ClientsFile, ios::in);//read mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}
	static void _SaveClientsDataToFile(vector <clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open(ClientsFile, ios::out);//overwrite mode

		string Line;

		if (MyFile.is_open())
		{
			for (clsBankClient C : vClients)
			{
				if (C.isMarkedForDelete() == false)
				{
					Line = _ConvertClientObjectToLine(C);
					MyFile << Line << endl;
				}
			}
		
			MyFile.close();
		}
	}

	void _AddLineToFile(string Line)
	{
		fstream MyFile;
		MyFile.open(ClientsFile, ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << Line << endl;
			MyFile.close();
		}

	}

	
	string _PrepareTransferRecord(clsBankClient DestinationClient, float TransferAmount, string Username, string Seperator = GlobalSeperator)
	{
		string TransferRecord = "";
		TransferRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferRecord += GetAccountNumber() + Seperator;
		TransferRecord += DestinationClient.GetAccountNumber() + Seperator;
		TransferRecord += to_string(TransferAmount) + Seperator;
		TransferRecord += to_string(AccountBalance) + Seperator;
		TransferRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		TransferRecord += Username;

		return TransferRecord;
	}
	void _AddTransferRecordToFile(clsBankClient DestinationClient, float TransferAmount, string Username)
	{
		string TransferRecord = _PrepareTransferRecord(DestinationClient, TransferAmount, Username);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << TransferRecord << endl;
			MyFile.close();
		}

	}
	//funcs for TransferLogScreen
	struct stTransferData; //just a declration
	static stTransferData _ConvertLinetoTransferDataStruct(string Line, string Seperator = GlobalSeperator)
	{
		vector <string> vTransferData = clsString::Split(Line, Seperator);
		stTransferData TransferData;

		TransferData.TransferDateTime = vTransferData[0];
		TransferData.SourceAccNum = vTransferData[1];
		TransferData.DestinationAccNum = vTransferData[2];
		TransferData.TransferAmount = stof(vTransferData[3]);
		TransferData.SourceBalance = stof(vTransferData[4]);
		TransferData.DestinationBalance = stof(vTransferData[5]);
		TransferData.Username = vTransferData[6];

		return TransferData;
	}
	static vector <stTransferData> _LoadTransferDataFromFile()
	{
		vector <stTransferData> vTransferData;
		fstream MyFile;

		MyFile.open("TransferLog.txt", ios::in);//read mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				stTransferData TransferData = _ConvertLinetoTransferDataStruct(Line);
				vTransferData.push_back(TransferData);
			}
			MyFile.close();
		}
		return vTransferData;
	}


	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C._AccountNumber == _AccountNumber)
			{
				C = *this;
				break;
			}
		}

		_SaveClientsDataToFile(_vClients); //rewrite the txt file after the update

	}
	void _AddNew()
	{
		_AddLineToFile(_ConvertClientObjectToLine(*this));
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(EmptyMode, "", "", "", "", "", "", 0);
	}

public:
	//parameterized constructor 
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email
		, string Phone, string AccountNumber, string PinCode, float AccountBalance) 
		: clsPerson(FirstName, LastName, Email, Phone) //send variables to clsPerson
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	struct stTransferData
	{
		string TransferDateTime;
		string SourceAccNum;
		string DestinationAccNum;
		float TransferAmount;
		float SourceBalance;
		float DestinationBalance;
		string Username;
	};


	bool isEmpty()
	{
		return (_Mode == EmptyMode);
	}
	bool isMarkedForDelete()
	{
		return _MarkForDelete;
	}

	//read-only property
	string GetAccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	//same as _LoadClientsDataFromFile()
	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static float GetTotalBalances()
	{
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();

		float TotalBalances = 0;

		for (clsBankClient C : vClients)
		{
			TotalBalances += C.AccountBalance;
		}
		return TotalBalances;

	}

	static clsBankClient Find(string AccountNumber)
	{
		//vector <clsBankClient> vClients; //no need for vector here
		fstream MyFile;

		MyFile.open(ClientsFile, ios::in);//read mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client._AccountNumber == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();  //means client not found
	}
	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		//overload
		clsBankClient Client1 = Find(AccountNumber);
		return (Client1.PinCode == PinCode) ? Client1 : _GetEmptyClientObject();
		//Abo Hadhoud Code // long and not overloaded so i change it
		// 
		////vector <clsBankClient> vClients; //no need for vector here
		//fstream MyFile;
		// 
		//MyFile.open(ClientsFile, ios::in);//read mode
		//
		//if (MyFile.is_open())
		//{
		//	string Line;
		//	while (getline(MyFile, Line))
		//	{
		//		clsBankClient Client = _ConvertLinetoClientObject(Line);
		//		if (Client._AccountNumber == AccountNumber && Client._PinCode == PinCode)
		//		{
		//			MyFile.close();
		//			return Client;
		//		}
		//	}
		//	MyFile.close();
		//}
		//return _GetEmptyClientObject();  //means client not found
	}
	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		return (!Client1.isEmpty()); //checks if it is EmptyMode
	}

	bool Delete()
	{
		vector <clsBankClient> _vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C._AccountNumber == _AccountNumber)
			{
				C._MarkForDelete = true;
				break;
			}
		}
		_SaveClientsDataToFile(_vClients);
		*this = _GetEmptyClientObject(); //clearing all data in the current object, with empty _Mode

		return true;
	}

	void Deposit(float Amount)
	{
		_AccountBalance += Amount;
		Save();
	}
	bool Withdraw(float Amount)
	{
		if (Amount > _AccountBalance)
			return false;
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}
	bool TransferTo(clsBankClient& ToClient, float TransferAmount, string Username)
	{
		if (TransferAmount > _AccountBalance)
			return false;
		else
		{
			Withdraw(TransferAmount);
			ToClient.Deposit(TransferAmount);
			_AddTransferRecordToFile(ToClient, TransferAmount, Username);
			return true;
		}
	}


	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	//it calls _LoadTransferDataFromFile() but static and public
	static vector <stTransferData> GetTransferLog()
	{
		return _LoadTransferDataFromFile();
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			return enSaveResults::svFaildEmptyObject;

		case enMode::UpdateMode:
			_Update();
			return enSaveResults::svSucceeded;

		case enMode::AddNewMode:
			if (IsClientExist(_AccountNumber))
				return enSaveResults::svFaildAccountNumberExists;
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode; // changing the mode from AddNew to Update mode
				return enSaveResults::svSucceeded;
			}
		}
	}

};


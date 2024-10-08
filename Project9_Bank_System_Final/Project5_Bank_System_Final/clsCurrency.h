#pragma once
#include<iostream>
#include<string>
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsBankClient.h"

string CurrenciesFile = "Currencies.txt";


class clsCurrency
{

private:

    enum enMode { EmptyMode = 0, UpdateMode = 1 };//no AddNewMode since we will not add any new Country/Currency
    enMode _Mode;

    string _Country;
    string _Code;
    string _Name;
    float _Rate;

    static clsCurrency _ConvertLineToCurrencyObject(string Line, string Seperator = GlobalSeperator)
    {
        vector<string> vCurrencyData;
        vCurrencyData = clsString::Split(Line, Seperator);

        return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2],
            stod(vCurrencyData[3]));

    }
    static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = GlobalSeperator)
    {

        string stCurrencyRecord = "";
        stCurrencyRecord += Currency._Country + Seperator;
        stCurrencyRecord += Currency._Code + Seperator;
        stCurrencyRecord += Currency._Name + Seperator;
        stCurrencyRecord += to_string(Currency._Rate);

        return stCurrencyRecord;

    }

    static  vector <clsCurrency> _LoadCurrencysDataFromFile()
    {
        vector <clsCurrency> vCurrencys;

        fstream MyFile;
        MyFile.open(CurrenciesFile, ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                vCurrencys.push_back(Currency);
            }
            MyFile.close();
        }
        return vCurrencys;
    }
    static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencys)
    {
        fstream MyFile;
        MyFile.open(CurrenciesFile, ios::out);//overwrite

        string Line;

        if (MyFile.is_open())
        {

            for (clsCurrency C : vCurrencys)
            {
                Line = _ConverCurrencyObjectToLine(C);
                MyFile << Line << endl;
            }
            MyFile.close();
        }
    }

    void _Update()
    {
        vector <clsCurrency> vCurrencys = _LoadCurrencysDataFromFile();

        for (clsCurrency& C : vCurrencys)
        {
            if (C.GetCode() == GetCode())
            {
                C = *this;
                break;
            }
        }
        _SaveCurrencyDataToFile(vCurrencys);
    }

    static clsCurrency _GetEmptyCurrencyObject()
    {
        return clsCurrency(enMode::EmptyMode, "", "", "", 0);
    }

public:

    clsCurrency(enMode Mode, string Country, string Code, string Name, float Rate)
    {
        _Mode = Mode;
        _Country = Country;
        _Code = Code;
        _Name = Name;
        _Rate = Rate;
    }

    bool isEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    //read-only properties
    string GetCountry()
    {
        return _Country;
    }
    string GetCode()
    {
        return _Code;
    }
    string GetName()
    {
        return _Name;
    }
    float GetRate()
    {
        return _Rate;
    }

    void UpdateRate(float NewRate)
    {
        _Rate = NewRate;
        _Update();
    }

    static vector <clsCurrency> GetCurrenciesList()
    {
        return _LoadCurrencysDataFromFile();
    }

    static clsCurrency FindByCode(string CurrencyCode)
    {

        CurrencyCode = clsString::UpperAllString(CurrencyCode);

        fstream MyFile;
        MyFile.open(CurrenciesFile, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                if (Currency._Code == CurrencyCode) // currency codes in file are already uppercase
                {
                    MyFile.close();
                    return Currency;
                }
            }
            MyFile.close();
        }
        return _GetEmptyCurrencyObject();
    }

    static clsCurrency FindByCountry(string Country)
    {
        Country = clsString::UpperAllString(Country);

        fstream MyFile;
        MyFile.open(CurrenciesFile, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                if (clsString::UpperAllString(Currency._Country) == Country)
                {
                    MyFile.close();
                    return Currency;
                }
            }
            MyFile.close();
        }
        return _GetEmptyCurrencyObject();
    }

    static bool IsCurrencyExist(string CurrencyCode)
    {
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        return (!Currency.isEmpty());
    }

    //abo-hadhoud used this method to convert between any currency
    // C1 to USD, USD to C2
    float ConvertToUSD(float Amount)
    {
        return Amount / GetRate();
    }
    float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
    {
        float AmountInUSD = ConvertToUSD(Amount);

        if (Currency2.GetCode() == "USD")
        {
            return AmountInUSD;
        }
        return (AmountInUSD * Currency2.GetRate());
    }
    
    //I used this method to convert between any currency
    // C2.amount = C1.amount * (C2.rate/C1.rate)
    float ExchangeTo(clsCurrency Currency, float ExchangeAmount)
    {
        return (ExchangeAmount * (Currency.GetRate() / GetRate()));
    }

};

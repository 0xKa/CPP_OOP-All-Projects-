//Project4_Currency_Exchange : after I finish this project I will add it added to Bank System Project as an Extension check project 5!
#include <iostream>
#include "clsCurrency.h"

//temp function, for UI classes later
static void _PrintCurrency(clsCurrency Currency)
{
    cout << "\nCurrency Card:\n";
    cout << "_____________________________\n";
    cout << "\nCountry    : " << Currency.GetCountry();
    cout << "\nCode       : " << Currency.GetCode();
    cout << "\nName       : " << Currency.GetName();
    cout << "\nRate(1$) = : " << Currency.GetRate();

    cout << "\n_____________________________\n";

}

int main()

{
    clsCurrency Currency1 = Currency1.FindByCode("syp");

    if (Currency1.isEmpty())
    {
        cout << "\nCurrency Is Not Found!\n";
    }
    else
    {
        _PrintCurrency(Currency1);
    }

    clsCurrency Currency2 = Currency2.FindByCountry("oman");

    if (Currency2.isEmpty())
    {
        cout << "\nCurrency Is Not Found!\n";
    }
    else
    {
        _PrintCurrency(Currency2);
    }

    return 0;
}




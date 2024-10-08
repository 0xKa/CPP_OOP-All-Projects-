//Project3 Date Library Project, all funcs from course 8

#include <iostream>
#include "clsDate.h";
using namespace std;


int main()
{

	clsDate Date1;
	clsDate Date2("6/8/2004");
	clsDate Date3(15, 6, 1999);
	clsDate Date4(365, 2014);

	cout << "\nDate1: ";
	Date1.Print();
	cout << endl;

	cout << "\nDate2: ";
	Date2.Print();
	cout << endl;

	cout << "\nDate3: ";
	Date3.Print();
	cout << endl;

	cout << "\nDate4: ";
	Date4.Print();
	cout << endl;
	
	
	cout << "Date2 isLeapYaer: " << Date2.isLeapYear() << endl;
	
	cout << "Date2 NumberOfDaysInMonth: " << Date2.NumberOfDaysInMonth() << endl;

	cout << "Date2 DayOfWeekOrder: " << Date2.DayOfWeekOrder() << endl;

	cout << "Date2 Month Short Name: " << Date2.GetMonthShortName() << endl;

	cout << "Date2 Print Month Calendar: ";
	Date2.PrintMonthCalendar();
	
	cout << "Date2 Print Year Calendar: ";
	Date2.PrintYearCalendar();
	
	cout << "Date2 Days From Beginning Year: " << Date2.CalculateDaysFromTheBeginningOfYear() << endl;


	cout << "\nDate3: ";
	Date3.Print();
	Date3 = Date3.AddDays(15);
	cout << "\nDate3 After adding 15 days: ";
	Date3.Print();
	
	cout << "\n\nDate1 Before Date2?: " << Date1.Before(Date2);
	cout << "\nDate1 Equal Date2? : " << Date1.Equals(Date2);
	cout << "\nDate1 After Date2? : " << Date1.After(Date2);
	
	cout << "\n\nDate3 is it last day in month : " << Date3.isLastDayInMonth();

	cout << "\nDate3 is it last month in year : " << Date3.isLastMonthInYear();


	cout << "\n\nDate2: ";
	Date2.Print();
	cout << "\nDate3: ";
	Date3.Print();
	cout << "\nDiffrence in Days Between Date2 & Date3: " << Date2.GetDiffrenceInDays(Date3);

	clsDate Date5(19,7,2024);
	cout << "\n\nDate5: ";
	Date5.Print();

	Date5.AddOneDay();
	cout << "\nDate5 increase by one day: ";
	Date5.Print();
	
	Date5.IncreaseDateByXDays(100);
	cout << "\nDate5 increase by 100 days: ";
	Date5.Print();
	
	Date5.IncreaseDateByXYears(100);
	cout << "\nDate5 increase by 100 Years: ";
	Date5.Print();

	
	Date5.DecreaseDateByOneDay();
	cout << "\nDate5 Decrease by one day: ";
	Date5.Print();
	
	Date5.DecreaseDateByXDays(100);
	cout << "\nDate5 Decrease by 100 days: ";
	Date5.Print();
	
	Date5.DecreaseDateByXYears(100);
	cout << "\nDate5 Decrease by 100 Years: ";
	Date5.Print();

	cout << "\n\nDate1 IsEndOfWeek?   : " << Date1.IsEndOfWeek();
	cout << "\nDate1 IsWeekEnd?     : " << Date1.IsWeekEnd();
	cout << "\nDate1 IsBusinessDay? : " << Date1.IsBusinessDay();

	cout << "\n\nDate1 DaysUntilTheEndOfWeek?  : " << Date1.DaysUntilTheEndOfWeek();
	cout << "\nDate1 DaysUntilTheEndOfMonth? : " << Date1.DaysUntilTheEndOfMonth();
	cout << "\nDate1 DaysUntilTheEndOfYear?  : " << Date1.DaysUntilTheEndOfYear();

	cout << "\n\nVacations Days between Date3 and Date4  : " << Date3.CalculateVacationDays(Date4);

	cout << "\n\nMy Age in Days: " << clsDate::CalculateMyAgeInDays(Date2) << " Days";

	system("pause>0");

	return 0;
}
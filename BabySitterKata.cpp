// BabySitterKata.cpp : This file contains the 'main' function. 
// Program execution begins and ends there.

#include <iostream>
#include "BabySitterKata.h"
#include "BabySitterKataUnitTests.h"

using namespace std;
using namespace BabySitterKataApplication;

// Input:  StartIndex = 0(5PM) to 10(4AM)
// Output: bool true if StartIndex is valid ie. 5PM to 4AM, false otherwise
bool BabySitterPayCalculator::IsStartIndexValid(int StartIndex)
{
	if (StartIndex < 11) //can only work from 5pm to 4am ie. 11 hours
		return true;
	return false;
}

// Input:  StartIndex, StopIndex = 0(5PM) to 10(4AM)
// Output: bool true if StopIndex is valid ie. 5PM to 4AM AND StartIndex is <= StopIndex, 
//         false otherwise
bool BabySitterPayCalculator::IsStopIndexValid(int StartIndex, int StopIndex)
{
	if (StopIndex < 11)
	{
		if (StartIndex > StopIndex)
			return false;  //cant stop before you start!
		return true;
	}
	else
		return false;
}

// Input:  Family ID = 0 to 2
// Output: bool true if StopIndex is valid ie. 5PM to 4AM   AND   StartIndex is <= StopIndex, 
bool BabySitterPayCalculator::IsFamilyValid(int FamilyID)
{
	if (FamilyID >= 3)		//we only have 3 families for now			
		return false;
	return true;
}

// Input:  dTime = double value 5.00(AM) to 4:00(AM), 
//         bStart = true if StartTime, otherwise false 
// Output: integer = an index from 0(5PM) to 10(3AM)
//		   assume working 5 to 8 is ONLY 3 hours, 
//		   ie. 1.00 converted to 12, 1.01 converted to 1
int BabySitterPayCalculator::ConvertTimeToIndex(double dTimeToConvert, bool bStartOrStop)
{
	double integerRepresentation;
	if (!bStartOrStop && (modf(dTimeToConvert, &integerRepresentation) == 0))
		dTimeToConvert = dTimeToConvert - (double)1.00;

	int HourlyIndexIntoPayRates = 0;
	if ((dTimeToConvert >= 5) && (dTimeToConvert < 12.59))
		HourlyIndexIntoPayRates = (int)dTimeToConvert - 5;
	else
		HourlyIndexIntoPayRates = (int)dTimeToConvert + 7;
	return HourlyIndexIntoPayRates;
}

int BabySitterPayCalculator::CalculateTotalPay(double StartTime, double StopTime, int FamilyID)
{
	TotalBabySitterPay = 0;
	StartIndex = ConvertTimeToIndex(StartTime, true);
	StopIndex = ConvertTimeToIndex(StopTime, false);
	if (IsStartIndexValid(StartIndex))
	{
		if (IsStopIndexValid(StartIndex, StopIndex))
		{
			if (IsFamilyValid(FamilyID))
			{
				for (int i = StartIndex; i <= StopIndex; i++)
					TotalBabySitterPay = TotalBabySitterPay + PayRates[FamilyID][i];
				return TotalBabySitterPay;
			}
			else
				return FamilyIDInvalid;
		}
		else
			return StopTimeInvalid;
	}
	else
		return 	StartTimeInvalid;
};

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Parameters may be entered on the command line or by setting debugging parameters
// in Visual Studio IDE project properties

// Input parameters: argv[1] = StartTime, argv[2] = StopTime, argv[3] = FamilyID
int main(int argc, char* argv[])
{
	std::cout << "Hello BabySitter!\n";

	//calculate babysitter pay
	int TotalPay = 0;
	BabySitterPayCalculator *Calculator = new BabySitterPayCalculator();
	TotalPay = Calculator->CalculateTotalPay(atoi(argv[1]), atoi(argv[2]), atoi(argv[3])); //start, stop, family

	BabySitterPayCalculatorUnitTests *CalculatorUnitTests = new BabySitterPayCalculatorUnitTests();
	CalculatorUnitTests->TotalPriceUnitTests(Calculator);

	//display output
	if (TotalPay < 0)
	{
		std::cout << "There was an error in your data entry.\n";
	}
	else
	{
		std::cout << "Your pay today is " << TotalPay << " dollars!\n";
		std::cout << "You worked today from " << argv[1] << " to " << argv[2] << " for family " << argv[3] << "\n";
	}

	delete Calculator;
	delete CalculatorUnitTests;
	std::getchar();
	return 0;
}

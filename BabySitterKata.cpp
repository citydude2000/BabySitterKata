// BabySitterKata.cpp : This file contains the 'main' function. 
// Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class BabySitterPayCalculator
{

protected:
	// Input:  StartIndex = 0(5PM) to 10(4AM)
	// Output: bool true if StartIndex is valid ie. 5PM to 4AM, false otherwise
	bool IsStartIndexValid(int StartIndex)
	{
		if (StartIndex < 11) //can only work from 5pm to 4am ie. 11 hours
			return true;
		return false;
	}

	// Input:  StartIndex, StopIndex = 0(5PM) to 10(4AM)
	// Output: bool true if StopIndex is valid ie. 5PM to 4AM AND StartIndex is <= StopIndex, 
	//         false otherwise
	bool IsStopIndexValid(int StartIndex, int StopIndex)
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
	bool IsFamilyValid(int FamilyID)
	{
		if (FamilyID >= 3)		//we only have 3 families for now			
			return false;
		return true;
	}

	// Input:  dTime = double value 5.00(AM) to 4:00(AM), 
	//         bStart = true if StartTime, otherwise false 
	// Output: integer = an index from 0(5PM) to 10(3AM)
	int ConvertTimeToIndex(double dTime, bool bStart)
	{
		double intPart;
		//we assume working 5 to 8 is ONLY 3 hours, 
		if (!bStart && (modf(dTime, &intPart) == 0))
			dTime = dTime - (double)1.00; //so ie. stoptime 1:00 is really hour 12

		int Index = 0;
		//fix the time from 5 to 3 to be index 0 to 10
		if ((dTime >= 5) && (dTime < 12.59))
			Index = (int)dTime - 5;
		else
			Index = (int)dTime + 7;
		return Index;
	}

	//using this table under the assumption that the sitter is paid based on a full
	//hour of pay for the time sitting starts and for a full hour for any partial hours worked
	int  PayRates[3][11] = { 15, 15, 15, 15, 15, 15, 20, 20, 20, 20, 20,   //family 1
							 12, 12, 12, 12, 12,  8,  8, 16, 16, 16, 16,   //family 2
							 21, 21, 21, 21, 15, 15, 15, 15, 15, 15, 15 }; //family 3
	enum ErrorCode { StartTimeInvalid = -1, StopTimeInvalid = -2, FamilyIDInvalid = -3};

public:
	BabySitterPayCalculator() {};
	~BabySitterPayCalculator() {};

	// Input:  StartTime double value 5.00(AM) to 4:00(AM), 
	//         StopTime double value 5.00(AM) to 4:00(AM), 
	//         FamilyID integer identifying which family is current customer 
	// Output: integer = calculated total pay(in dollars)
	int CalculateTotalPay(double StartTime, double StopTime, int FamilyID)
	{
		int TotalBabySitterPay = 0;
		int StartIndex = ConvertTimeToIndex(StartTime, true);
		int StopIndex = ConvertTimeToIndex(StopTime, false);
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
		;
	}

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
	BabySitterPayCalculator * Calculator = new BabySitterPayCalculator();
	TotalPay = Calculator->CalculateTotalPay(atoi(argv[1]), atoi(argv[2]), atoi(argv[3])); //start, stop, family

	//display output
	if (TotalPay < 0)
		std::cout << "There was an error in your data entry.\n";
	else
	{
		std::cout << "Your pay today is " << TotalPay << " dollars!\n";
		std::cout << "You worked today from " << argv[1] << " to " << argv[2] << " for family " << argv[3] << "\n";
	}
	std::getchar();
}


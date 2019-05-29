// BabySitterKata.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class BabySitterPayCalculator
{

protected:
	// Input:  StartIndex = 0(5PM) to 10(4AM)
	// Output: bool true if StartIndex is valid ie. 5PM to 4AM, false otherwise
	bool IsStartTimeValid(int StartTime)
	{
		if (StartTime < 11) //can only work from 5pm to 4am ie. 11 hours
			return true;
		return false;
	}

	// Input:  StartIndex, StopIndex = 0(5PM) to 10(4AM)
	// Output: bool true if StopIndex is valid ie. 5PM to 4AM AND StartIndex is <= StopIndex, 
	//         false otherwise
	bool IsStopTimeValid(int StartTime, int StopTime)
	{
		if (StopTime < 11)
		{
			if (StartTime > StopTime)
				return false;  //cant stop before you start!
			return true;
		}
		else
			return false;
	}

	// Input:  Family ID = 0 to 2
	// Output: bool true if StopIndex is valid ie. 5PM to 4AM   AND   StartIndex is <= StopIndex, 
	int	 IsFamilyValid(int FamilyID)
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
		//working 5 to 8 is ONLY 3 hours, 
		if (!bStart && (modf(dTime, &intPart) == 0))
			dTime = dTime - (double)1.00; //so ie. stoptime 1:00 is really hour 12
		int Index = 0;
		//fix the time from 5 to 4 to be index 0 to 11
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
		if (IsStartTimeValid(StartIndex))
		{
			if (IsStopTimeValid(StartIndex, StopIndex))
			{
				if (IsFamilyValid(FamilyID))
				{
					for (int i = StartIndex; i <= StopIndex; i++)
						TotalBabySitterPay = TotalBabySitterPay + PayRates[FamilyID][i];
					return TotalBabySitterPay;
				}
				else
					return -3;
			}
			else
				return -2;
		}
		else
			return -1;
	}

};

int Test5x7x2(BabySitterPayCalculator* Calculator)
{
	int TotalPay = Calculator->CalculateTotalPay(5, 7, 2); //start, stop, family
	std::cout << "Your pay today is " << TotalPay << " dollars!\n";
	_ASSERTE(TotalPay == 42);
	return TotalPay;
}

int Test5x1x2(BabySitterPayCalculator* Calculator)
{
	int TotalPay = Calculator->CalculateTotalPay(5, 1, 2); //start, stop, family
	std::cout << "Your pay today is " << TotalPay << " dollars!\n";
	_ASSERTE(TotalPay == 144);
	return TotalPay;
}

int Test5x1p2x2(BabySitterPayCalculator* Calculator)
{
	int TotalPay = Calculator->CalculateTotalPay(5, 1.2, 2); //start, stop(partial hour same as whole), family
	std::cout << "Your pay today is " << TotalPay << " dollars!\n";
	_ASSERTE(TotalPay == 159);
	return TotalPay;
}

int Test5x6x2(BabySitterPayCalculator* Calculator)
{
	int TotalPay = Calculator->CalculateTotalPay(5, 6, 2); //start, stop(partial hour same as whole), family
	std::cout << "Your pay today is " << TotalPay << " dollars!\n";
	_ASSERTE(TotalPay == 21);
	return TotalPay;
}

int Test5x4x2(BabySitterPayCalculator* Calculator)
{
	int TotalPay = Calculator->CalculateTotalPay(5, 4, 2); //start, stop(partial hour same as whole), family
	std::cout << "Your pay today is " << TotalPay << " dollars!\n";
	_ASSERTE(TotalPay == 189);
	return TotalPay;
}

int Test12x12p5x2(BabySitterPayCalculator* Calculator)
{
	int TotalPay = Calculator->CalculateTotalPay(12, 12.5, 2); //start, stop(partial hour same as whole), family
	std::cout << "Your pay today is " << TotalPay << " dollars!\n";
	_ASSERTE(TotalPay == 15);
	return TotalPay;
}

int Test12x1x2(BabySitterPayCalculator* Calculator)
{
	int TotalPay = Calculator->CalculateTotalPay(12, 1, 2); //start, stop(partial hour same as whole), family
	std::cout << "Your pay today is " << TotalPay << " dollars!\n";
	_ASSERTE(TotalPay == 15);
	return TotalPay;
}

int Test12x4x2(BabySitterPayCalculator* Calculator)
{
	int TotalPay = Calculator->CalculateTotalPay(12, 4, 2); //start, stop(partial hour same as whole), family
	std::cout << "Your pay today is " << TotalPay << " dollars!\n";
	_ASSERTE(TotalPay == 60);
	return TotalPay;
}

int Test12x3p59x2(BabySitterPayCalculator* Calculator)
{
	int TotalPay = Calculator->CalculateTotalPay(12, 3.59, 2); //start, stop(partial hour same as whole), family
	std::cout << "Your pay today is " << TotalPay << " dollars!\n";
	_ASSERTE(TotalPay == 60);
	return TotalPay;
}

int Test1x4x2(BabySitterPayCalculator* Calculator)
{
	int TotalPay = Calculator->CalculateTotalPay(1, 4, 2); //start, stop(partial hour same as whole), family
	std::cout << "Your pay today is " << TotalPay << " dollars!\n";
	_ASSERTE(TotalPay == 45);
	return TotalPay;
}

int Test1x3p59x2(BabySitterPayCalculator* Calculator)
{
	int TotalPay = Calculator->CalculateTotalPay(1, 3.59, 2); //start, stop(partial hour same as whole), family
	std::cout << "Your pay today is " << TotalPay << " dollars!\n";
	_ASSERTE(TotalPay == 45);
	return TotalPay;
}

int Test3x4x2(BabySitterPayCalculator* Calculator)
{
	int TotalPay = Calculator->CalculateTotalPay(3, 4, 2); //start, stop(partial hour same as whole), family
	std::cout << "Your pay today is " << TotalPay << " dollars!\n";
	_ASSERTE(TotalPay == 15);
	return TotalPay;
}

int Test3x3p59x2(BabySitterPayCalculator* Calculator)
{
	int TotalPay = Calculator->CalculateTotalPay(3, 3.59, 2); //start, stop(partial hour same as whole), family
	std::cout << "Your pay today is " << TotalPay << " dollars!\n";
	_ASSERTE(TotalPay == 15);
	return TotalPay;
}

int Test5x5p15x2(BabySitterPayCalculator* Calculator)
{
	int TotalPay = Calculator->CalculateTotalPay(5, 5.15, 2); //start, stop(partial hour same as whole), family
	std::cout << "Your pay today is " << TotalPay << " dollars!\n";
	_ASSERTE(TotalPay == 21);
	return TotalPay;
}

int Test5x12p5x2(BabySitterPayCalculator* Calculator)
{
	int TotalPay = Calculator->CalculateTotalPay(5, 12.5, 2); //start, stop(partial hour same as whole), family
	std::cout << "Your pay today is " << TotalPay << " dollars!\n";
	_ASSERTE(TotalPay == 144);
	return TotalPay;
}

int Test5x1p15x2(BabySitterPayCalculator* Calculator)
{
	int TotalPay = Calculator->CalculateTotalPay(5, 1.15, 2); //start, stop(partial hour same as whole), family
	std::cout << "Your pay today is " << TotalPay << " dollars!\n";
	_ASSERTE(TotalPay == 159);
	return TotalPay;
}

int Test5x6x0(BabySitterPayCalculator* Calculator)
{
	int TotalPay = Calculator->CalculateTotalPay(5, 6, 0); //start, stop(partial hour same as whole), family
	std::cout << "Your pay today is " << TotalPay << " dollars!\n";
	_ASSERTE(TotalPay == 15);
	return TotalPay;
}

int Test5x4x0(BabySitterPayCalculator* Calculator)
{
	int TotalPay = Calculator->CalculateTotalPay(5, 4, 0); //start, stop(partial hour same as whole), family
	std::cout << "Your pay today is " << TotalPay << " dollars!\n";
	_ASSERTE(TotalPay == 190);
	return TotalPay;
}

int Test4x6x2(BabySitterPayCalculator* Calculator)
{
	int TotalPay = Calculator->CalculateTotalPay(4, 6, 2); //start, stop(partial hour same as whole), family
	std::cout << "Your pay today is " << TotalPay << " dollars!\n";
	_ASSERTE(TotalPay == -1);
	return TotalPay;
}

int Test5x4p15x2(BabySitterPayCalculator* Calculator)
{
	int TotalPay = Calculator->CalculateTotalPay(5, 4.15, 2); //start, stop(partial hour same as whole), family
	std::cout << "Your pay today is " << TotalPay << " dollars!\n";
	_ASSERTE(TotalPay == -2);
	return TotalPay;
}

int Test6x8x3(BabySitterPayCalculator* Calculator)
{
	int TotalPay = Calculator->CalculateTotalPay(6, 8, 3); //start, stop(partial hour same as whole), family
	std::cout << "Your pay today is " << TotalPay << " dollars!\n";
	_ASSERTE(TotalPay == -3);
	return TotalPay;
}

int Test8x7x3(BabySitterPayCalculator* Calculator)
{
	int TotalPay = Calculator->CalculateTotalPay(8, 7, 3); //start, stop(partial hour same as whole), family
	std::cout << "Your pay today is " << TotalPay << " dollars!\n";
	_ASSERTE(TotalPay == -2);
	return TotalPay;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Input parameters: argv[1] = StartTime, argv[2] = StopTime, argv[3] = FamilyID
int main()
{
	std::cout << "Hello BabySitter!\n";
	
	//calculate babysitter pay
	int TotalPay = 0;
	BabySitterPayCalculator * Calculator = new BabySitterPayCalculator();
	TotalPay = Test5x7x2(Calculator);
	TotalPay = Test5x1x2(Calculator);
	TotalPay = Test5x1p2x2(Calculator);
	TotalPay = Test5x6x2(Calculator);
	TotalPay = Test5x4x2(Calculator);
	TotalPay = Test12x12p5x2(Calculator);
	TotalPay = Test12x1x2(Calculator);
	TotalPay = Test12x4x2(Calculator);
	TotalPay = Test12x3p59x2(Calculator);
	TotalPay = Test1x4x2(Calculator);
	TotalPay = Test1x3p59x2(Calculator);
	TotalPay = Test3x4x2(Calculator);
	TotalPay = Test3x3p59x2(Calculator);
	TotalPay = Test5x5p15x2(Calculator);
	TotalPay = Test5x12p5x2(Calculator);
	TotalPay = Test5x1p15x2(Calculator);
	TotalPay = Test5x6x0(Calculator);
	TotalPay = Test5x4x0(Calculator);
	TotalPay = Test4x6x2(Calculator);
	TotalPay = Test5x4p15x2(Calculator);
	TotalPay = Test6x8x3(Calculator);
	TotalPay = Test8x7x3(Calculator); 

	delete Calculator;
	std::getchar();
}


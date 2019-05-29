// BabySitterKata.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class BabySitterPayCalculator
{

protected:
	// Input:  dTime = double value 5.00(AM) to 4:00(AM), 
	//         bStart = true if StartTime, otherwise false 
	// Output: integer = an index from 0(5PM) to 10(3AM)
	int  ConvertTimeToIndex(double dTime, bool bStart)
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
		for (int i = StartIndex; i <= StopIndex; i++)
			TotalBabySitterPay = TotalBabySitterPay + PayRates[FamilyID][i];
		return TotalBabySitterPay;
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
int main()
{
	int TotalPay = 0;
	std::cout << "Hello BabySitter!\n";

	BabySitterPayCalculator * Calculator = new BabySitterPayCalculator();
	TotalPay = Test5x7x2(Calculator);
	TotalPay = Test5x1x2(Calculator);
	TotalPay = Test5x1p2x2(Calculator); //Next add code to make this pass

	delete Calculator;
	std::getchar();
}


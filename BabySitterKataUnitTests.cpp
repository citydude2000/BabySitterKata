#include <iostream>
#include "BabySitterKata.h"
#include "BabySitterKataUnitTests.h"

using namespace std;

namespace BabySitterKataApplication
{
	int Test5x7x2(BabySitterPayCalculator* CalculatorUnitTests)
	{
		int TotalPay = CalculatorUnitTests->CalculateTotalPay(5, 7, 2); //start, stop, family
		std::cout << "Test 1: Your pay today is " << TotalPay << " dollars!\n";
		_ASSERTE(TotalPay == 42);
		return TotalPay;
	}

	int Test5x1x2(BabySitterPayCalculator* CalculatorUnitTests)
	{
		int TotalPay = CalculatorUnitTests->CalculateTotalPay(5, 1, 2); //start, stop, family
		std::cout << "Test 2: Your pay today is " << TotalPay << " dollars!\n";
		_ASSERTE(TotalPay == 144);
		return TotalPay;
	}

	int Test5x1p2x2(BabySitterPayCalculator* Calculator)
	{
		int TotalPay = Calculator->CalculateTotalPay(5, 1.2, 2); //start, stop(partial hour same as whole), family
		std::cout << "Test 3: Your pay today is " << TotalPay << " dollars!\n";
		_ASSERTE(TotalPay == 159);
		return TotalPay;
	}

	int Test5x6x2(BabySitterPayCalculator* Calculator)
	{
		int TotalPay = Calculator->CalculateTotalPay(5, 6, 2); //start, stop(partial hour same as whole), family
		std::cout << "Test 4: Your pay today is " << TotalPay << " dollars!\n";
		_ASSERTE(TotalPay == 21);
		return TotalPay;
	}

	int Test5x4x2(BabySitterPayCalculator* Calculator)
	{
		int TotalPay = Calculator->CalculateTotalPay(5, 4, 2); //start, stop(partial hour same as whole), family
		std::cout << "Test 5: Your pay today is " << TotalPay << " dollars!\n";
		_ASSERTE(TotalPay == 189);
		return TotalPay;
	}

	int Test12x12p5x2(BabySitterPayCalculator* Calculator)
	{
		int TotalPay = Calculator->CalculateTotalPay(12, 12.5, 2); //start, stop(partial hour same as whole), family
		std::cout << "Test 6: Your pay today is " << TotalPay << " dollars!\n";
		_ASSERTE(TotalPay == 15);
		return TotalPay;
	}

	int Test12x1x2(BabySitterPayCalculator* Calculator)
	{
		int TotalPay = Calculator->CalculateTotalPay(12, 1, 2); //start, stop(partial hour same as whole), family
		std::cout << "Test 7: Your pay today is " << TotalPay << " dollars!\n";
		_ASSERTE(TotalPay == 15);
		return TotalPay;
	}

	int Test12x4x2(BabySitterPayCalculator* Calculator)
	{
		int TotalPay = Calculator->CalculateTotalPay(12, 4, 2); //start, stop(partial hour same as whole), family
		std::cout << "Test 8: Your pay today is " << TotalPay << " dollars!\n";
		_ASSERTE(TotalPay == 60);
		return TotalPay;
	}

	int Test12x3p59x2(BabySitterPayCalculator* Calculator)
	{
		int TotalPay = Calculator->CalculateTotalPay(12, 3.59, 2); //start, stop(partial hour same as whole), family
		std::cout << "Test 9: Your pay today is " << TotalPay << " dollars!\n";
		_ASSERTE(TotalPay == 60);
		return TotalPay;
	}

	int Test1x4x2(BabySitterPayCalculator* Calculator)
	{
	int TotalPay = Calculator->CalculateTotalPay(1, 4, 2); //start, stop(partial hour same as whole), family
		std::cout << "Test 10: Your pay today is " << TotalPay << " dollars!\n";
		_ASSERTE(TotalPay == 45);
		return TotalPay;
	}

	int Test1x3p59x2(BabySitterPayCalculator* Calculator)
	{
		int TotalPay = Calculator->CalculateTotalPay(1, 3.59, 2); //start, stop(partial hour same as whole), family
		std::cout << "Test 11: Your pay today is " << TotalPay << " dollars!\n";
		_ASSERTE(TotalPay == 45);
		return TotalPay;
	}

	int Test3x4x2(BabySitterPayCalculator* Calculator)
	{
		int TotalPay = Calculator->CalculateTotalPay(3, 4, 2); //start, stop(partial hour same as whole), family
		std::cout << "Test 12: Your pay today is " << TotalPay << " dollars!\n";
		_ASSERTE(TotalPay == 15);
		return TotalPay;
	}

	int Test3x3p59x2(BabySitterPayCalculator* Calculator)
	{
		int TotalPay = Calculator->CalculateTotalPay(3, 3.59, 2); //start, stop(partial hour same as whole), family
		std::cout << "Test 13: Your pay today is " << TotalPay << " dollars!\n";
		_ASSERTE(TotalPay == 15);
		return TotalPay;
	}

	int Test5x5p15x2(BabySitterPayCalculator* Calculator)
	{
		int TotalPay = Calculator->CalculateTotalPay(5, 5.15, 2); //start, stop(partial hour same as whole), family
		std::cout << "Test 14: Your pay today is " << TotalPay << " dollars!\n";
		_ASSERTE(TotalPay == 21);
		return TotalPay;
	}

	int Test5x12p5x2(BabySitterPayCalculator* Calculator)
	{
		int TotalPay = Calculator->CalculateTotalPay(5, 12.5, 2); //start, stop(partial hour same as whole), family
		std::cout << "Test 15: Your pay today is " << TotalPay << " dollars!\n";
		_ASSERTE(TotalPay == 144);
		return TotalPay;
	}

	int Test5x1p15x2(BabySitterPayCalculator* Calculator)
	{
		int TotalPay = Calculator->CalculateTotalPay(5, 1.15, 2); //start, stop(partial hour same as whole), family
		std::cout << "Test 16: Your pay today is " << TotalPay << " dollars!\n";
		_ASSERTE(TotalPay == 159);
		return TotalPay;
	}

	int Test5x6x0(BabySitterPayCalculator* Calculator)
	{
		int TotalPay = Calculator->CalculateTotalPay(5, 6, 0); //start, stop(partial hour same as whole), family
		std::cout << "Test 17: Your pay today is " << TotalPay << " dollars!\n";
		_ASSERTE(TotalPay == 15);
		return TotalPay;
	}

	int Test5x4x0(BabySitterPayCalculator* Calculator)
	{
		int TotalPay = Calculator->CalculateTotalPay(5, 4, 0); //start, stop(partial hour same as whole), family
		std::cout << "Test 18: Your pay today is " << TotalPay << " dollars!\n";
		_ASSERTE(TotalPay == 190);
		return TotalPay;
	}

	int Test4x6x2(BabySitterPayCalculator* Calculator)
	{
		int TotalPay = Calculator->CalculateTotalPay(4, 6, 2); //start, stop(partial hour same as whole), family
		std::cout << "Test 19: Error Code is " << TotalPay << "\n";
		_ASSERTE(TotalPay == -1);
		return TotalPay;
	}

	int Test5x4p15x2(BabySitterPayCalculator* Calculator)
	{
		int TotalPay = Calculator->CalculateTotalPay(5, 4.15, 2); //start, stop(partial hour same as whole), family
		std::cout << "Test 20: Error Code is " << TotalPay << "\n";
		_ASSERTE(TotalPay == -2);
		return TotalPay;
	}

	int Test6x8x3(BabySitterPayCalculator* Calculator)
	{
		int TotalPay = Calculator->CalculateTotalPay(6, 8, 3); //start, stop(partial hour same as whole), family
		std::cout << "Test 21: Error Code is " << TotalPay << "\n";
		_ASSERTE(TotalPay == -3);
		return TotalPay;
	}

	int Test8x7x3(BabySitterPayCalculator* Calculator)
	{
		int TotalPay = Calculator->CalculateTotalPay(8, 7, 3); //start, stop(partial hour same as whole), family
		std::cout << "Test 22: Error Code is " << TotalPay << "\n";
		_ASSERTE(TotalPay == -2);
		return TotalPay;
	}

	// Input:  StartIndex = 0(5PM) to 10(4AM)
	// Output: n/a
	void BabySitterPayCalculatorUnitTests::TotalPriceUnitTests(BabySitterPayCalculator *Calculator)
	{
		Test5x7x2(Calculator);
		Test5x1x2(Calculator);
		Test5x1p2x2(Calculator);
		Test5x6x2(Calculator);
		Test5x4x2(Calculator);
		Test12x12p5x2(Calculator);
		Test12x1x2(Calculator);
		Test12x4x2(Calculator);
		Test12x3p59x2(Calculator);
		Test1x4x2(Calculator);
		Test1x3p59x2(Calculator);
		Test3x4x2(Calculator);
		Test3x3p59x2(Calculator);
		Test5x5p15x2(Calculator);
		Test5x12p5x2(Calculator);
		Test5x1p15x2(Calculator);
		Test5x6x0(Calculator);
		Test5x4x0(Calculator);
		Test4x6x2(Calculator);
		Test5x4p15x2(Calculator);
		Test6x8x3(Calculator);
		Test8x7x3(Calculator);
	}
} //end of namespace

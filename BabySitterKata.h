#pragma once

namespace BabySitterKataApplication
{
	class BabySitterPayCalculator
	{
		public: 
			BabySitterPayCalculator() {};
			int CalculateTotalPay(double StartTime, double StopTime, int FamilyID);

		protected:
			~BabySitterPayCalculator() {};
			bool IsStartIndexValid(int StartIndex);
			bool IsStopIndexValid(int StartIndex, int StopIndex);
			bool IsFamilyValid(int FamilyID);
			int  ConvertTimeToIndex(double dTime, bool bStart);

			int TotalBabySitterPay;
			int StartIndex;
			int StopIndex;

		//using this table under the assumption that the sitter is paid based on a full
		//hour of pay for the time sitting starts and for a full hour for any partial hours worked
		int  PayRates[3][11] = { 15, 15, 15, 15, 15, 15, 20, 20, 20, 20, 20,   //family 1
								 12, 12, 12, 12, 12,  8,  8, 16, 16, 16, 16,   //family 2
								 21, 21, 21, 21, 15, 15, 15, 15, 15, 15, 15 }; //family 3
		
		enum ErrorCode { StartTimeInvalid = -1, StopTimeInvalid = -2, FamilyIDInvalid = -3 };
	};
}
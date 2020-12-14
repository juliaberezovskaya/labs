#include <iostream>
#include "Fraction.h"
#include <conio.h>
#include <fstream>
#include <sstream>
#include "CalculateFraction.h"
#include "List.h"
#include "MixedFraction.h"

typedef std::vector<Fraction> TFrVector; //typegef to vector of class Fraction
typedef std::vector<CalculateFraction> CalcVector;
typedef std::vector<MixedFraction> MixedVector;


void RunCalcCreatingTests(TFrVector& v, CalcVector& calcFr)
{
	std::cout << "Test 1: creating objects of class calculated fractions" << std::endl;
	std::cout << std::endl;

	if (calcFr[0].GetDenominator() == 1 && calcFr[0].GetNumerator() == 0 && calcFr[0].GetCalculation() == 0.0)
		std::cout << "subtest 1 success (Default constructor)" << std::endl;
	else std::cout << "subtest 1 fail (Default constructor)" << std::endl;
	double num = v[1].GetNumerator(), den = v[1].GetDenominator();
	if (calcFr[1].GetNumerator() == v[1].GetNumerator() && 
		calcFr[1].GetDenominator() == v[1].GetDenominator() &&
		calcFr[1].GetCalculation() == num/den)
		std::cout << "subtest 2 success (Fraction -> Calculate Fraction constructor)" << std::endl;
	else std::cout << "subtest 2 fail (Fraction -> Calculate Fraction constructor)" << std::endl;
	num = v[2].GetNumerator(), den = v[2].GetDenominator();
	if (calcFr[2].GetNumerator() == v[2].GetNumerator() &&
		calcFr[2].GetDenominator() == v[2].GetDenominator() &&
		calcFr[2].GetCalculation() == num / den)
		std::cout << "subtest 3 success (Fraction -> Calculate Fraction constructor)" << std::endl;
	else std::cout << "subtest 3 FAIL (Fraction -> Calculate Fraction constructor)" << std::endl;
	double calc = 2.0 / 3.0;
	if (calcFr[3].GetNumerator() == 2 && 
		calcFr[3].GetDenominator() == 3 && 
		calcFr[3].GetCalculation() == calc)
		std::cout << "subtest 4 success (settable constructor)" << std::endl;
	else std::cout << "subtest 4 fail (settable constructor)" << std::endl;
	std::cout << std::endl;
}

void RunMixCreatingTests(TFrVector& v, MixedVector& mix)
{
	std::cout << "Test 2: creating objects of class mixed fractions" << std::endl;
	std::cout << std::endl;

	if (mix[0].GetNumerator() == 0 && mix[0].GetDenominator() == 1 && mix[0].GetWhole() == 0)
		std::cout << "subtest 1 success (Default constructor)" << std::endl;
	else
		std::cout << "subtest 1 fail (Default constructor)" << std::endl;

	if (mix[1].GetNumerator() == 1 && mix[1].GetDenominator() == 2 && mix[1].GetWhole() == 0)
		std::cout << "subtest 2 success (Fraction -> Mixed Fraction constructor)" << std::endl;
	else 
		std::cout << "subtest 2 fail (Fraction -> Mixed Fraction constructor)" << std::endl;
	
	if (mix[2].GetNumerator() == 3 && mix[2].GetDenominator() == 4 && mix[2].GetWhole() == 0)
		std::cout << "subtest 3 success (Fraction -> Mixed Fraction constructor)" << std::endl;
	else std::cout << "subtest 3 fail (Fraction -> Mixed Fraction constructor)" << std::endl;
	if (mix[3].GetNumerator() == 2 && mix[3].GetDenominator() == 3 && mix[3].GetWhole() == 0)
		std::cout << "subtest 4 success (settable constructor)" << std::endl;
	else std::cout << "subtest 4 fail (settable constructor)" << std::endl;
	if (mix[4].GetNumerator() == 1 && mix[4].GetDenominator() == 2 && mix[4].GetWhole() == 5)
		std::cout << "subtest 5 success (settable constructor)" << std::endl;
	else std::cout << "subtest 5 fail (settable constructor)" << std::endl;
	if (mix[5].GetNumerator() == 1 && mix[5].GetDenominator() == 2 && mix[5].GetWhole() == 7)
		std::cout << "subtest 6 success (Fraction -> Mixed Fraction constructor)" << std::endl;
	else std::cout << "subtest 6 fail (Fraction -> Mixed Fraction constructor)l" << std::endl;
	std::cout << std::endl;
}

void RunExceptionsTests(TFrVector& f)
{
	std::cout << "Test 3: creating unexceptable fraction" << std::endl << std::endl << "subtest 1 ";
	try
	{
		Fraction err = Fraction::Create(5, 0);
		std::cerr << "ERROR: Created object with zero division" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "success (creating Fraction with zero denominator)" << std::endl;
	}

	std::cout << "subtest 2 ";
	try
	{
		MixedFraction err = MixedFraction::CreateMixedFraction(5, 0, 0);
		std::cerr << "ERROR: Created object with zero division" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "success (creating MixedFraction with zero denominator)" << std::endl;
	}

	std::cout << "subtest 3 ";
	try
	{
		CalculateFraction err = CalculateFraction::CreateCalculate(5, 0);
		std::cerr << "ERROR: Created object with zero division" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "success (creating CalculateFraction with zero denominator)" << std::endl;
	}

	std::cout << "subtest 4 ";
	try
	{
		CalculateFraction err;
		err.SetCalculation(5, 0);
		std::cerr << "ERROR: Created object with zero division" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout  << "success (setting calculation with zero denominator)" << std::endl;
	}

	std::cout << "subtest 5 ";
	try
	{
		Fraction result = f[7].Sum(f[8]);
		std::cerr << "ERROR: Sum is over int" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "success (overloading sum)" << std::endl;
	}

	std::cout << "subtest 6 ";
	try
	{
		Fraction result = f[9].Sub(f[8]);
		std::cerr << "ERROR: Sub is over int" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "success (overloading subtraction)" << std::endl;
	}
	
	std::cout << "subtest 7 ";
	try
	{
		Fraction result = f[7].Mul(f[8]);
		std::cerr << "ERROR: Mul is over int" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "success (overloading multiply)" << std::endl;
	}

	std::cout << "subtest 8 ";
	try
	{
		Fraction result = f[1].Div(f[3]);
		std::cerr << "ERROR: Div is over int" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "success (overloading division)" << std::endl;
	}
}

void RunArithmeticOperationsCalc(TFrVector& v, CalcVector& calcFr)
{
	std::cout << "Test 3: arithmetic operations in Calculate Fraction" << std::endl;
	std::cout << std::endl;

	CalculateFraction boof1 = CalculateFraction(calcFr[1].Sum(calcFr[2]));
	
	if (boof1.GetNumerator() == 539 &&
		boof1.GetDenominator() == 368 &&
		boof1.GetCalculation() == 539.0 / 368.0)
		std::cout << "subtest 1 success (Calculate Fraction + Calculate Fraction)" << std::endl;
	else std::cout << "subtest 1 fail (Calculate Fraction + Calculate Fraction)" << std::endl;

	CalculateFraction boof2 = CalculateFraction(calcFr[1].Sum(v[0]));
	
	if (boof2.GetNumerator() == 5 &&
		boof2.GetDenominator() == 4 &&
		boof2.GetCalculation() == 5.0 / 4.0)
		std::cout << "subtest 2 success (Calculate Fraction + Fraction)" << std::endl;
	else std::cout << "subtest 2 fail (Calculate Fraction + Fraction)" << std::endl;

	CalculateFraction boof3 = CalculateFraction(calcFr[1].Sub(calcFr[3]));

	if (boof3.GetNumerator() == 1 &&
		boof3.GetDenominator() == 12 &&
		boof3.GetCalculation() == 1.0 / 12.0)
		std::cout << "subtest 3 success (Calculate Fraction - Calculate Fraction)" << std::endl;
	else std::cout << "subtest 3 fail (Calculate Fraction - Calculate Fraction)" << std::endl;

	CalculateFraction boof4 = CalculateFraction(calcFr[1].Sub(v[0]));

	if (boof4.GetNumerator() == 1 &&
		boof4.GetDenominator() == 4 &&
		boof4.GetCalculation() == 1.0 / 4.0)
		std::cout << "subtest 4 success (Calculate Fraction - Fraction)" << std::endl;
	else std::cout << "subtest 4 fail (Calculate Fraction - Fraction)" << std::endl;

	CalculateFraction boof5 = CalculateFraction(calcFr[1].Mul(calcFr[3]));

	if (boof5.GetNumerator() == 1 &&
		boof5.GetDenominator() == 2 &&
		boof5.GetCalculation() == 1.0 / 2.0)
		std::cout << "subtest 5 success (Calculate Fraction * Calculate Fraction)" << std::endl;
	else std::cout << "subtest 5 fail (Calculate Fraction * Calculate Fraction)" << std::endl;

	CalculateFraction boof6 = CalculateFraction(calcFr[1].Mul(v[0]));

	if (boof6.GetNumerator() == 3 &&
		boof6.GetDenominator() == 8 &&
		boof6.GetCalculation() == 3.0 / 8.0)
		std::cout << "subtest 6 success (Calculate Fraction * Fraction)" << std::endl;
	else std::cout << "subtest 6 fail (Calculate Fraction * Fraction)" << std::endl;
	
	CalculateFraction boof7 = CalculateFraction(calcFr[1].Div(calcFr[3]));

	if (boof7.GetNumerator() == 9 &&
		boof7.GetDenominator() == 8 &&
		boof7.GetCalculation() == 9.0 / 8.0)
		std::cout << "subtest 7 success (Calculate Fraction / Calculate Fraction)" << std::endl;
	else std::cout << "subtest 7 fail (Calculate Fraction / Calculate Fraction)" << std::endl;

	CalculateFraction boof8 = CalculateFraction(calcFr[1].Div(v[0]));

	if (boof8.GetNumerator() == 3 &&
		boof8.GetDenominator() == 2 &&
		boof8.GetCalculation() == 3.0 / 2.0)
		std::cout << "subtest 8 success (Calculate Fraction / Fraction)" << std::endl;
	else std::cout << "subtest 8 fail (Calculate Fraction / Fraction)" << std::endl;
	std::cout << std::endl;
}

void RunArithmeticOperationsMix(TFrVector& v, MixedVector& mix)
{
	std::cout << "Test 4: arithmetic operations in Mixed Fraction" << std::endl;
	std::cout << std::endl;

	MixedFraction boof1 = MixedFraction(mix[2].Sum(mix[4]));
	if (boof1.GetNumerator() == 1 &&
		boof1.GetDenominator() == 4 &&
		boof1.GetWhole() == 6)
		std::cout << "subtest 1 success (Mixed Fraction + Mixed Fraction)" << std::endl;
	else std::cout << "subtest 1 fail (Mixed Fraction + Mixed Fraction)" << std::endl;

	MixedFraction boof2 = MixedFraction(mix[2].Sum(v[0]));
	if (boof2.GetNumerator() == 1 &&
		boof2.GetDenominator() == 4 &&
		boof2.GetWhole() == 1)
		std::cout << "subtest 2 success (Mixed Fraction + Fraction)" << std::endl;
	else std::cout << "subtest 2 fail (Mixed Fraction + Fraction)" << std::endl;

	MixedFraction boof3 = MixedFraction(mix[2].Sub(mix[4]));
	if (boof3.GetNumerator() == -3 &&
		boof3.GetDenominator() == 4 &&
		boof3.GetWhole() == -4)
		std::cout << "subtest 3 success (Mixed Fraction - Mixed Fraction)" << std::endl;
	else std::cout << "subtest 3 fail (Mixed Fraction - Mixed Fraction)" << std::endl;

	MixedFraction boof4 = MixedFraction(mix[2].Sub(v[0]));
	if (boof4.GetNumerator() == 1 &&
		boof4.GetDenominator() == 4 &&
		boof4.GetWhole() == 0)
		std::cout << "subtest 4 success (Mixed Fraction - Fraction)" << std::endl;
	else std::cout << "subtest 4 fail (Mixed Fraction - Fraction)" << std::endl;

	MixedFraction boof5 = MixedFraction(mix[2].Mul(mix[4]));
	if (boof5.GetNumerator() == 1 &&
		boof5.GetDenominator() == 8 &&
		boof5.GetWhole() == 4)
		std::cout << "subtest 5 success (Mixed Fraction * Mixed Fraction)" << std::endl;
	else std::cout << "subtest 5 fail (Mixed Fraction * Mixed Fraction)" << std::endl;
	
	MixedFraction boof6 = MixedFraction(mix[2].Mul(v[0]));
	if (boof6.GetNumerator() == 3 &&
		boof6.GetDenominator() == 8 &&
		boof6.GetWhole() == 0)
		std::cout << "subtest 6 success (Mixed Fraction * Fraction)" << std::endl;
	else std::cout << "subtest 6 fail (Mixed Fraction * Fraction)" << std::endl;

	MixedFraction boof7 = MixedFraction(mix[2].Div(mix[4]));
	if (boof7.GetNumerator() == 3 &&
		boof7.GetDenominator() == 22 &&
		boof7.GetWhole() == 0)
		std::cout << "subtest 7 success (Mixed Fraction / Mixed Fraction)" << std::endl;
	else std::cout << "subtest 7 fail (Mixed Fraction / Mixed Fraction)" << std::endl;

	MixedFraction boof8 = MixedFraction(mix[2].Div(v[0]));
	if (boof8.GetNumerator() == 1 &&
		boof8.GetDenominator() == 2 &&
		boof8.GetWhole() == 1)
		std::cout << "subtest 8 success (Mixed Fraction / Fraction)" << std::endl;
	else std::cout << "subtest 8 fail (Mixed Fraction / Fraction)" << std::endl;
	std::cout << std::endl;
}

void RunDemonstrationLabFive(TFrVector& v, CalcVector& calcFr, MixedVector& mix)
{
	std::cout << "Test 5 lab" << std::endl << "We Pushed in list three elements and there is demonstration:" << std::endl;
	List list;
	list.PushBegin(v[1]);
	list.PushBack(calcFr[2]);
	list.PushBegin(mix[3]);

	std::cout << list << std::endl;

	std::cout << "Push test:" ;
	
	std::string comparingString = mix[3].ToString() + ' ' + v[1].ToString() + ' ' + calcFr[2].ToString();
	std::stringstream strStr;
	strStr << list;
	if (comparingString == strStr.str()) std::cout << "	Success" << std::endl;
	else std::cout << "	Fail" << std::endl;

	list.Delete();

	std::cout << "Delete test:";
		
	comparingString = v[1].ToString() + ' ' + calcFr[2].ToString();
	std::stringstream strStr1;
	strStr1 << list;
	if (comparingString == strStr1.str()) std::cout << "	Success" << std::endl;
	else std::cout << "	Fail" << std::endl;
	
	list.PushBack(mix[3]);

	std::cout << "Search tests:" << std::endl;

	if (list.IsContain(v[1])) std::cout << "	Success" << std::endl;
	else std::cout << "	Fail" << std::endl;

	if (!list.IsContain(v[2])) std::cout << "	Success" << std::endl;
	else std::cout << "	Fail" << std::endl;

	if (list.IsContain(calcFr[2])) std::cout << "	Success" << std::endl;
	else std::cout << "	Fail" << std::endl;
	
	list.Delete();
	list.Delete();
	list.Delete();

	std::cout << "Empty list test:" << std::endl;
	
	comparingString = "List is empty";
	std::stringstream strStr2;
	strStr2 << list;
	if (comparingString == strStr2.str()) std::cout << "	Success" << std::endl;
	else std::cout << "	Fail" << std::endl;
	}

int main()
{
	
	TFrVector v = {									//creating Fraction vector
		Fraction::Create(1, 2),
		Fraction::Create(3, 4),
		Fraction::Create(526, 736),
		Fraction::Create(0, 57),
		Fraction::Create(45, 6),
		Fraction::Create(7, 9),
		Fraction::Create(25, 4),
		Fraction::Create(2147483640, 2147483642),
		Fraction::Create(2147400640, 2147480042),
		Fraction::Create(-2147400640, 2147480042)
	};

	CalcVector calcFr(4);
	
	calcFr[0];
	calcFr[1] = CalculateFraction(v[1]);
	calcFr[2] = CalculateFraction(v[2]);
	calcFr[3] = CalculateFraction::CreateCalculate(2, 3);

	MixedVector mixFr(6);
	
	mixFr[0];
	mixFr[1] = MixedFraction(v[0]);
	mixFr[2] = MixedFraction(v[1]);
	mixFr[3] = MixedFraction::CreateMixedFraction(2, 3, 0);
	mixFr[4] = MixedFraction::CreateMixedFraction(6, 4, 4);
	mixFr[5] = MixedFraction(v[4]);

	RunDemonstrationLabFive(v, calcFr, mixFr);

	std::cout << std::endl << "Enter a symbol to finish" << std::endl;
	std::getchar();
}
#pragma once
#include "Fraction.h"

class CalculateFraction : public Fraction
{
public:
	CalculateFraction();
	CalculateFraction(Fraction& other); //функция перехода от класса Fraction к классу CalculateFraction
	static CalculateFraction CreateCalculate(int numerator, int denominator);
	void SetCalculation(int numerator, int denominator);
	double GetCalculation();
	CalculateFraction Sum(const Fraction& other);
	CalculateFraction Sub(const Fraction& other);
	CalculateFraction Mul(const Fraction& other);
	CalculateFraction Div(const Fraction& other);
	CalculateFraction Sum(CalculateFraction& other);
	CalculateFraction Sub(CalculateFraction& other);
	CalculateFraction Mul(CalculateFraction& other);
	CalculateFraction Div(CalculateFraction& other);
	
private:
	double c_calculation;
};
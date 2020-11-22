#pragma once
#include "Fraction.h"

class CalculateFraction : public Fraction
{
public:
	void SetCalculation(int numerator, int denominator);
	double GetCalculation();
	CalculateFraction();
	CalculateFraction(Fraction& other); //функция перехода от класса Fraction к классу CalculateFraction
	static CalculateFraction CreateCalculate(int numerator, int denominator);
	CalculateFraction Sum(const Fraction& other);
	CalculateFraction Sub(const Fraction& other);
	CalculateFraction Mul(const Fraction& other);
	CalculateFraction Div(const Fraction& other);
	CalculateFraction Sum(CalculateFraction& other);
	CalculateFraction Sub(CalculateFraction& other);
	CalculateFraction Mul(CalculateFraction& other);
	CalculateFraction Div(CalculateFraction& other);
	std::string ToString(const CalculateFraction& obj);
	
private:
	double c_calculation;
};
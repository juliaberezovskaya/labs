#pragma once
#include "Fraction.h"

class CalculateFraction : public Fraction
{
public:
	void SetCalculation(int numerator, int denominator);
	double GetCalculation();
	CalculateFraction();
	CalculateFraction(Fraction& other); //������� �������� �� ������ Fraction � ������ CalculateFraction
	static CalculateFraction CreateCalculate(int numerator, int denominator);
	CalculateFraction Sum(const Fraction& other);
	CalculateFraction Sub(const Fraction& other);
	CalculateFraction Mul(const Fraction& other);
	CalculateFraction Div(const Fraction& other);
	CalculateFraction Sum(CalculateFraction& other);
	CalculateFraction Sub(CalculateFraction& other);
	CalculateFraction Mul(CalculateFraction& other);
	CalculateFraction Div(CalculateFraction& other);
	virtual  char* ToString() const;
	friend std::ostream& operator << (std::ostream& os, const CalculateFraction& fraction);
	friend bool operator ==(const CalculateFraction& left, const CalculateFraction& right);

	
private:
	double c_calculation;
};
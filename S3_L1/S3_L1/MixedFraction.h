#pragma once
#include "Fraction.h"

class MixedFraction : public Fraction
{
public:
	MixedFraction();
	int GetWhole();
	void SetWholePart(int number);
	MixedFraction(Fraction& other); //функция перехода от класса Fraction к классу MixedFraction
	static MixedFraction CreateMixedFraction(int numerator, int denominator, int whole);

	MixedFraction Sum(const Fraction& other);
	MixedFraction Sub(const Fraction& other);
	MixedFraction Mul(const Fraction& other);
	MixedFraction Div(const Fraction& other);
	MixedFraction Sum(MixedFraction& other);
	MixedFraction Sub(MixedFraction& other);
	MixedFraction Mul(MixedFraction& other);
	MixedFraction Div(MixedFraction& other);

	virtual char* ToString() const;
	
private:
	int m_whole_part;
};
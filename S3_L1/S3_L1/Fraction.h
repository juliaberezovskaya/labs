#pragma once
#include <iostream>
#include <fstream>
#include <vector>

class Fraction
{
public:
	Fraction();
	Fraction(const Fraction& other);
	static Fraction Create(int numerator, int denominator);

	void SetNumerator(int number);
	void SetDenominator(int number);
	
	int GetNumerator();
	int GetDenominator();

	Fraction Sum(const Fraction& other);
	Fraction Sub(const Fraction& other);
	Fraction& Simplify();
	Fraction Mul(const Fraction& other);
	Fraction Div(const Fraction& other);
	Fraction Inverse()const;
	
	virtual std::string ToString() const;
	
	friend std::ostream& operator << (std::ostream& os, const Fraction& fraction);
	friend std::istream& operator >> (std::istream& is, Fraction& fraction);


		
protected:
	int m_numerator;
	int m_denominator;
	Fraction* next;
};

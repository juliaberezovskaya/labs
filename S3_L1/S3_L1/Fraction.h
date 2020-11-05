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
	
	int GetNumerator();
	int GetDenominator();

	Fraction Sum(const Fraction& other);
	Fraction Sub(const Fraction& other);
	Fraction& Simplify();
	Fraction Mul(const Fraction& other);
	Fraction Div(const Fraction& other);
	Fraction Inverse()const;
	
	friend std::ostream& operator << (std::ostream& os, const Fraction& fraction);
	friend std::istream& operator >> (std::istream& is, Fraction& fraction);
	
	/*friend std::fstream& operator << (std::fstream& os, const Fraction& fraction);
	friend std::fstream& operator >> (std::fstream& is, Fraction& fraction);
	friend std::ofstream& operator << (std::ofstream& os, const Fraction& fraction);
	friend std::ifstream& operator >> (std::ifstream& is, Fraction& fraction);
	*/

	
	
private:
	int m_numerator;
	int m_denominator;
};



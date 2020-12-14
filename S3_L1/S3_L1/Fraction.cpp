#include "Fraction.h"
#include "MathUtils.h"
#include <exception>
#include <string>

Fraction::Fraction()
{
	m_numerator = 0;
	m_denominator = 1;
	next = NULL;
}

Fraction::Fraction(const Fraction& other)
{
	m_numerator = other.m_numerator;
	m_denominator = other.m_denominator;
}

Fraction Fraction::Create(int numerator, int denominator)
{
	if (denominator == 0) throw std::exception("	Unacceptable value");
	Fraction res;
	res.m_numerator = numerator;
	res.m_denominator = denominator;
	res.next = NULL;
	return res;
}

void Fraction::SetNumerator(int number)
{
	m_numerator = number;
}

void Fraction::SetDenominator(int number)
{
	m_denominator = number;
}


int Fraction::GetNumerator()
{
	return m_numerator;
}

int Fraction::GetDenominator()
{
	return m_denominator;
}

Fraction Fraction::Sum(const Fraction &other)
{
	if (m_numerator > INT_MAX - other.m_numerator) throw std::exception("Sum overflow");
	int bothDenominator = MathUtils::FindNok(m_denominator, other.m_denominator);
	int n1 = m_numerator * bothDenominator / m_denominator;
	int n2 = other.m_numerator * bothDenominator / other.m_denominator;
	int n = n1 + n2;
	Fraction res;
	res.m_numerator = n;
	res.m_denominator = bothDenominator;
	return res.Simplify();
}

Fraction Fraction::Sub(const Fraction& other)
{
	if (m_numerator < INT_MIN + other.m_numerator) throw std::exception("Sub overflow");
	int bothDenominator = MathUtils::FindNok(m_denominator, other.m_denominator);
	int n1 = m_numerator * bothDenominator / m_denominator;
	int n2 = other.m_numerator * bothDenominator / other.m_denominator;
	int n = n1 - n2;
	Fraction res;
	res.m_numerator = n;
	res.m_denominator = bothDenominator;
	return res.Simplify();
}

Fraction& Fraction::Simplify()
{
	int nod = MathUtils::FindNod(m_numerator, m_denominator);
	m_numerator /= nod;
	m_denominator /= nod;
	return *this;
}

Fraction Fraction::Mul(const Fraction& other)
{
	if (m_numerator >= INT_MAX / other.m_numerator) throw std::exception("Mul overflow");
	int n = m_numerator * other.m_numerator;
	if (m_denominator >= INT_MAX / other.m_denominator) throw std::exception("Mul overflow");
	int d = m_denominator * other.m_denominator;
	Fraction res;
	res.m_numerator = n;
	res.m_denominator = d;
	return res.Simplify();
}

Fraction Fraction::Div(const Fraction& other)
{
	return this->Mul(other.Inverse());
}

Fraction Fraction::Inverse()const
{
	if (m_numerator == 0) throw std::exception("Denominator is zero");
	return Create(m_denominator, m_numerator);
}

std::string Fraction::ToString() const
{
	return std::to_string(m_numerator) + '/' + std::to_string(m_denominator);
}

std::ostream& operator<<(std::ostream& os, const Fraction& fraction)
{
	os << fraction.m_numerator << "/" << fraction.m_denominator;
	return os;
}

std::istream& operator>>(std::istream& is, Fraction& fraction)
{
	char c;
	is.read(&c, sizeof c);
	fraction.m_numerator = 0;

	if (c < 0) return is;
	
	while (isdigit(c) && !is.eof())
	{
		fraction.m_numerator *= 10;
		fraction.m_numerator += c - '0';
		is.read(&c, sizeof c);
	}
	
	while (!isdigit(c) && !is.eof())
	{
		is.read(&c, sizeof c);
	}

	fraction.m_denominator = 0;

	while (isdigit(c) && !is.eof())
	{
		fraction.m_denominator *= 10;
		fraction.m_denominator += c - '0';
		is.read(&c, sizeof c);
	}
	return  is;
}
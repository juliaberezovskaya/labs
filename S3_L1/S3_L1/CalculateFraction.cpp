#include "CalculateFraction.h"
#include <string>

CalculateFraction::CalculateFraction() : Fraction()
{
	c_calculation = 0;
}

CalculateFraction::CalculateFraction(Fraction& other)
{
	m_numerator = other.GetNumerator();
	m_denominator = other.GetDenominator();
	SetCalculation(m_numerator, m_denominator);
}

CalculateFraction CalculateFraction::CreateCalculate(int numerator, int denominator)
{
	if (denominator == 0) throw std::exception("	Unacceptable value");
	CalculateFraction res;
	res.SetNumerator(numerator);
	res.SetDenominator(denominator);
	res.c_calculation = (double)numerator / denominator;
	return res;
}		

void CalculateFraction::SetCalculation(int numerator, int denominator)
{
	if (denominator == 0) throw std::exception("Denominator is zero");
	
	c_calculation = (double)numerator / denominator;
}

double CalculateFraction::GetCalculation()
{
	return c_calculation;
}

CalculateFraction CalculateFraction::Sum(const Fraction& other)
{
	CalculateFraction res;
	Fraction fRes;
	fRes.SetNumerator(this->m_numerator);
	fRes.SetDenominator(this->m_denominator);
	fRes = fRes.Sum(other);
	res.m_numerator = fRes.GetNumerator();
	res.m_denominator = fRes.GetDenominator();
	res.SetCalculation(res.GetNumerator(), res.GetDenominator());
	return res;
}

CalculateFraction CalculateFraction::Sub(const Fraction& other)
{
	CalculateFraction res;
	Fraction fRes;
	fRes.SetNumerator(this->m_numerator);
	fRes.SetDenominator(this->m_denominator);
	fRes = fRes.Sub(other);
	res.m_numerator = fRes.GetNumerator();
	res.m_denominator = fRes.GetDenominator();
	res.SetCalculation(res.GetNumerator(), res.GetDenominator());
	return res;
}

CalculateFraction CalculateFraction::Mul(const Fraction& other)
{
	CalculateFraction res;
	Fraction fRes;
	fRes.SetNumerator(this->m_numerator);
	fRes.SetDenominator(this->m_denominator);
	fRes = fRes.Mul(other);
	res.m_numerator = fRes.GetNumerator();
	res.m_denominator = fRes.GetDenominator();
	res.SetCalculation(res.GetNumerator(), res.GetDenominator());
	return res;
}

CalculateFraction CalculateFraction::Div(const Fraction& other)
{
	CalculateFraction res;
	Fraction fRes;
	fRes.SetNumerator(this->m_numerator);
	fRes.SetDenominator(this->m_denominator);
	fRes = fRes.Div(other);
	res.m_numerator = fRes.GetNumerator();
	res.m_denominator = fRes.GetDenominator();
	res.SetCalculation(res.GetNumerator(), res.GetDenominator());
	return res;
}

CalculateFraction CalculateFraction::Sum(CalculateFraction& other)
{
	CalculateFraction res;
	Fraction fr1, fr2, frRes;
	fr1.SetNumerator(m_numerator);
	fr1.SetDenominator(m_denominator);
	fr2.SetNumerator(other.GetNumerator());
	fr2.SetDenominator(other.GetDenominator());
	frRes = fr1.Sum(fr2);
	res.SetNumerator(frRes.GetNumerator());
	res.SetDenominator(frRes.GetDenominator());
	res.SetCalculation(frRes.GetNumerator(), frRes.GetDenominator());
	return res;
}

CalculateFraction CalculateFraction::Sub(CalculateFraction& other)
{
	CalculateFraction res;
	Fraction fr1, fr2, frRes;
	fr1.SetNumerator(m_numerator);
	fr1.SetDenominator(m_denominator);
	fr2.SetNumerator(other.GetNumerator());
	fr2.SetDenominator(other.GetDenominator());
	frRes = fr1.Sub(fr2);
	res.SetNumerator(frRes.GetNumerator());
	res.SetDenominator(frRes.GetDenominator());
	res.SetCalculation(frRes.GetNumerator(), frRes.GetDenominator());
	return res;
}

CalculateFraction CalculateFraction::Mul(CalculateFraction& other)
{
	CalculateFraction res;
	Fraction fr1, fr2, frRes;
	fr1.SetNumerator(m_numerator);
	fr1.SetDenominator(m_denominator);
	fr2.SetNumerator(other.GetNumerator());
	fr2.SetDenominator(other.GetDenominator());
	frRes = fr1.Mul(fr2);
	res.SetNumerator(frRes.GetNumerator());
	res.SetDenominator(frRes.GetDenominator());
	res.SetCalculation(frRes.GetNumerator(), frRes.GetDenominator());
	return res;
}

CalculateFraction CalculateFraction::Div(CalculateFraction& other)
{
	CalculateFraction res;
	Fraction fr1, fr2, frRes;
	fr1.SetNumerator(m_numerator);
	fr1.SetDenominator(m_denominator);
	fr2.SetNumerator(other.GetNumerator());
	fr2.SetDenominator(other.GetDenominator());
	frRes = fr1.Div(fr2);
	res.SetNumerator(frRes.GetNumerator());
	res.SetDenominator(frRes.GetDenominator());
	res.SetCalculation(frRes.GetNumerator(), frRes.GetDenominator());
	return res;
}

char* CalculateFraction::ToString() const
{
	char* str = new char[150];
	char* buf = Fraction::ToString();
	strcpy_s(str, 150, buf);
	sprintf(buf, " calculation: %f", c_calculation);
	strcat(str, buf);
	return str;
}

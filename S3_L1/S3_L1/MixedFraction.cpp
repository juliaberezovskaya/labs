#include "MixedFraction.h"

#include <string>

#include "MathUtils.h"

MixedFraction::MixedFraction() : Fraction()
{
	m_whole_part = 0;
}

int MixedFraction::GetWhole()
{
	return m_whole_part;
}

void MixedFraction::SetWholePart(int number)
{
	m_whole_part = number;
}

MixedFraction::MixedFraction(Fraction& other)
{
	int numerator = other.GetNumerator(), denominator = other.GetDenominator(), whole = 0;
	MathUtils::PutInPlaces(numerator, denominator, whole);
	m_whole_part = whole;
	m_numerator = numerator;
	m_denominator = denominator;
	Simplify();
}

MixedFraction MixedFraction::CreateMixedFraction(int numerator, int denominator, int whole)
{
	if (denominator == 0) throw std::exception("	Unacceptable value");
	
	MixedFraction newFraction;
	
	MathUtils::PutInPlaces(numerator, denominator, whole);
	
	newFraction.SetWholePart(whole);
	newFraction.SetNumerator(numerator);
	newFraction.SetDenominator(denominator);
	newFraction.Simplify();
	return newFraction;
}

MixedFraction MixedFraction::Sum(const Fraction& other)
{
	Fraction simpleFraction;
	simpleFraction.SetNumerator(MathUtils::ChangeWholePartInSimpleNumerator(m_numerator, m_denominator, m_whole_part));
	simpleFraction.SetDenominator(m_denominator);
	simpleFraction = simpleFraction.Sum(other);
	MixedFraction res = MixedFraction(simpleFraction);
	return res;
}

MixedFraction MixedFraction::Sub(const Fraction& other)
{
	Fraction simpleFraction;
	simpleFraction.SetNumerator(MathUtils::ChangeWholePartInSimpleNumerator(m_numerator, m_denominator, m_whole_part));
	simpleFraction.SetDenominator(m_denominator);
	simpleFraction = simpleFraction.Sub(other);
	MixedFraction res = MixedFraction(simpleFraction);
	return res;
}

MixedFraction MixedFraction::Mul(const Fraction& other)
{
	Fraction simpleFraction;
	simpleFraction.SetNumerator(MathUtils::ChangeWholePartInSimpleNumerator(m_numerator, m_denominator, m_whole_part));
	simpleFraction.SetDenominator(m_denominator);
	simpleFraction = simpleFraction.Mul(other);
	MixedFraction res = MixedFraction(simpleFraction);
	return res;
}

MixedFraction MixedFraction::Div(const Fraction& other)
{
	this->Fraction::Sum(other);
	Fraction simpleFraction;
	simpleFraction.SetNumerator(MathUtils::ChangeWholePartInSimpleNumerator(m_numerator, m_denominator, m_whole_part));
	simpleFraction.SetDenominator(m_denominator);
	simpleFraction = simpleFraction.Div(other);
	MixedFraction res = MixedFraction(simpleFraction);
	return res;
}

MixedFraction MixedFraction::Sum(MixedFraction& other)
{
	Fraction simpleFraction1, simpleFraction2;
	simpleFraction1.SetNumerator(MathUtils::ChangeWholePartInSimpleNumerator(m_numerator, m_denominator, m_whole_part));
	simpleFraction1.SetDenominator(m_denominator);
	simpleFraction2.SetNumerator(MathUtils::ChangeWholePartInSimpleNumerator(other.m_numerator, other.m_denominator, other.m_whole_part));
	simpleFraction2.SetDenominator(other.m_denominator);
	simpleFraction1 = simpleFraction1.Sum(simpleFraction2);
	MixedFraction res = MixedFraction(simpleFraction1);
	return res;
}

MixedFraction MixedFraction::Sub(MixedFraction& other)
{
	Fraction simpleFraction1, simpleFraction2;
	simpleFraction1.SetNumerator(MathUtils::ChangeWholePartInSimpleNumerator(m_numerator, m_denominator, m_whole_part));
	simpleFraction1.SetDenominator(m_denominator);
	simpleFraction2.SetNumerator(MathUtils::ChangeWholePartInSimpleNumerator(other.m_numerator, other.m_denominator, other.m_whole_part));
	simpleFraction2.SetDenominator(other.m_denominator);
	simpleFraction1 = simpleFraction1.Sub(simpleFraction2);
	MixedFraction res = MixedFraction(simpleFraction1);
	return res;
}

MixedFraction MixedFraction::Mul(MixedFraction& other)
{
	Fraction simpleFraction1, simpleFraction2;
	simpleFraction1.SetNumerator(MathUtils::ChangeWholePartInSimpleNumerator(m_numerator, m_denominator, m_whole_part));
	simpleFraction1.SetDenominator(m_denominator);
	simpleFraction2.SetNumerator(MathUtils::ChangeWholePartInSimpleNumerator(other.m_numerator, other.m_denominator, other.m_whole_part));
	simpleFraction2.SetDenominator(other.m_denominator);
	simpleFraction1 = simpleFraction1.Mul(simpleFraction2);
	MixedFraction res = MixedFraction(simpleFraction1);
	return res;
}

MixedFraction MixedFraction::Div(MixedFraction& other)
{
	Fraction simpleFraction1, simpleFraction2;
	simpleFraction1.SetNumerator(MathUtils::ChangeWholePartInSimpleNumerator(m_numerator, m_denominator, m_whole_part));
	simpleFraction1.SetDenominator(m_denominator);
	simpleFraction2.SetNumerator(MathUtils::ChangeWholePartInSimpleNumerator(other.m_numerator, other.m_denominator, other.m_whole_part));
	simpleFraction2.SetDenominator(other.m_denominator);
	simpleFraction1 = simpleFraction1.Div(simpleFraction2);
	MixedFraction res = MixedFraction(simpleFraction1);
	return res;
}

char* MixedFraction::ToString() const
{
	char* str = new char[150];
	char* buf = Fraction::ToString();
	sprintf_s(str, 150, "%d ", m_whole_part);
	strcat(str, buf);
	return str;
}

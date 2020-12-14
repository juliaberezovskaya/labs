#include "Container.h"

BaseContainer::~BaseContainer()
{
	delete next;
}

BaseContainer::BaseContainer()
{
	next = nullptr;
}

void BaseContainer::SetNextPtr(BaseContainer* ptr)
{
	next = ptr;
}

BaseContainer* BaseContainer::GetNextPtr()
{
	return next;
}

Fraction& FrContainer::Get()
{
	return obj;
}

Fraction FrContainer::GetObj()
{
	return obj;
}

FrContainer::FrContainer(Fraction fr)
{
	obj = fr;
}

Fraction& CFrContainer::Get()
{
	return obj;
}

CalculateFraction CFrContainer::GetObj()
{
	return obj;
}

CFrContainer::CFrContainer(CalculateFraction cfr)
{
	obj = cfr;
}

MixedFraction MFrContainer::GetObj()
{
	return obj;
}

MFrContainer::MFrContainer(MixedFraction mfr) 
{
	obj = mfr;
}

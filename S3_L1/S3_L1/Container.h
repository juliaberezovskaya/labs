#pragma once
#include "Fraction.h"
#include "CalculateFraction.h"
#include "MixedFraction.h"
class BaseContainer
{
public:
	BaseContainer();
	virtual ~BaseContainer();
	void SetNextPtr(BaseContainer* ptr);
	virtual Fraction& Get() = 0;
	BaseContainer* GetNextPtr();
	
private:
	BaseContainer* next;
};

class FrContainer: public BaseContainer
{
public:
	virtual Fraction& Get();
	Fraction GetObj();
	FrContainer(Fraction fr);
private:
	Fraction obj;
};

class CFrContainer : public BaseContainer
{
public:
	virtual Fraction& Get();
	CalculateFraction GetObj();
	CFrContainer(CalculateFraction cfr);
private:
	CalculateFraction obj;
};

class MFrContainer : public BaseContainer
{
public:
	
	MixedFraction GetObj();
	MFrContainer(MixedFraction mfr);
	Fraction& Get() override;
private:
	MixedFraction obj;
};

inline Fraction& MFrContainer::Get()
{
	return obj;
}

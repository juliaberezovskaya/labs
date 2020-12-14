#pragma once
#include "Fabric.h"

class List
{
public:
	List();
	void PushBegin(Fraction &f);
	void PushBegin(CalculateFraction &f);
	void PushBegin(MixedFraction &f);
	void PushBack(Fraction &f);
	void PushBack(CalculateFraction &f);
	void PushBack(MixedFraction &f);
	void Delete();
	static std::string ToString(FrContainer& f);
	bool IsContain(const Fraction& f) const;

	friend std::ostream& operator << (std::ostream& stream, const List& list);
	
private:
	BaseContainer *m_firstPtr, *m_lastPtr;
};


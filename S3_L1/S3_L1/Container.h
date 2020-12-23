#pragma once
#include "Fraction.h"

class BaseContainer
{
public:
	BaseContainer();
	BaseContainer(Fraction* f);
	~BaseContainer();
	void SetNextPtr(BaseContainer* ptr);
	Fraction* Get();
	BaseContainer* GetNextPtr();
	Fraction* GetObj();
	
private:
	BaseContainer* next;
	Fraction* obj;
};



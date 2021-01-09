#pragma once
#include "Fraction.h"

template <class Type> class BaseContainer
{
public:
	BaseContainer()
	{
		next = nullptr;
		obj = nullptr;
	}

	BaseContainer(Type* f)
	{
		next = nullptr;
		obj = f;
	}

	~BaseContainer()
	{
		delete next;
	}

	void SetNextPtr(BaseContainer* ptr)
	{
		next = ptr;
	}

	Type* Get()
	{
		return obj;
	}

	BaseContainer* GetNextPtr()
	{
		return next;
	}

	Type* GetObj()
	{
		return obj;
	}

private:
	BaseContainer* next;
	Type* obj;
};





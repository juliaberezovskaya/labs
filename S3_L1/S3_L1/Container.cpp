#include "Container.h"

BaseContainer::~BaseContainer()
{
	delete next;
}

BaseContainer::BaseContainer()
{
	obj = nullptr;
	next = nullptr;
}

BaseContainer::BaseContainer(Fraction* f)
{
	obj = f;
	next = nullptr;
}

void BaseContainer::SetNextPtr(BaseContainer* ptr)
{
	next = ptr;
}

Fraction* BaseContainer::Get()
{
	return obj;
}

BaseContainer* BaseContainer::GetNextPtr()
{
	return next;
}

Fraction* BaseContainer::GetObj()
{
	return obj;
}


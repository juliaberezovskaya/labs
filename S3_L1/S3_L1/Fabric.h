#pragma once
#include "Container.h"

class Fabric
{
public:
	
	template <class Type> static BaseContainer<Type>* CreateContainer (Type* f)
	{
		return new BaseContainer(f);
	}

};


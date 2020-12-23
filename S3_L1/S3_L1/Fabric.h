#pragma once
#include "CalculateFraction.h"
#include "Container.h"
#include "MixedFraction.h"

class Fabric
{
public:
	
	static BaseContainer* CreateContainer(Fraction* f)
	{
		return new BaseContainer(f);
	}

};


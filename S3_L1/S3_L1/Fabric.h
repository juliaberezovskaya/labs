#pragma once
#include "Container.h"

class Fabric
{
public:
	
	static FrContainer* CreateContainer(Fraction& f)
	{
		return new FrContainer(f);
	}
	
	static BaseContainer* CreateContainer(CalculateFraction& cf)
	{
		return new CFrContainer(cf);
	}
	static BaseContainer* CreateContainer(MixedFraction& mf)
	{
		return new MFrContainer(mf);
	}
};


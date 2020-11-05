#include "MathUtils.h"
#include <climits>
#include <exception>


int MathUtils::FindNod(int d1, int d2)
{
	int nod = 1;
	for (int i = 1; i <= d1 && i <= d2; i++)
		if (d1 % i == 0 && d2 % i == 0) nod = i;
	return nod;
}

int MathUtils::FindNok(int d1, int d2)
{
	int nok = d1 / FindNod(d1, d2);
	if (nok > INT_MAX / d2) throw std::exception("nok overflow");
	nok *= d2;
	return nok;
}
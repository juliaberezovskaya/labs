#pragma once
#include <map>

#include "Fraction.h"
#include <queue>
using namespace std;

class CreatingElements
{
public:
	

	static void CreateData(queue<Fraction> &q)
	{
		for (int i = 1; i < 10000; i++)
			q.push(Fraction::Create(i,i+200));
	}

	static void CreateData (map<int,Fraction> &m)
	{
		for (int i = 1; i < 10000; i++)
			m.insert(make_pair(i,Fraction::Create(i,i+200)));
	}
	
};


#pragma once
#include "Fabric.h"

class List
{
public:
	List();
	void PushBegin(Fraction &f);
	void PushBack(Fraction &f);
	void Delete();
	static std::string ToString(BaseContainer& f);
	bool IsContain(const Fraction& f) const;
	BaseContainer* GetFirstPtr();
	char* ToString ();
private:
	BaseContainer *m_firstPtr, *m_lastPtr;
};


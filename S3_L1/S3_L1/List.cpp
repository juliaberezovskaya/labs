#include "List.h"

List::List()
{
	m_firstPtr = nullptr;
	m_lastPtr = nullptr;
}

void List::PushBegin(Fraction& f)
{
	BaseContainer* containerPtr = Fabric::CreateContainer(&f);
	if (m_firstPtr == nullptr && m_lastPtr == nullptr)
	{
		m_firstPtr = containerPtr;
		m_lastPtr = containerPtr;
		
		return;
	}
	containerPtr->SetNextPtr(m_firstPtr);
	m_firstPtr = containerPtr;
}

void List::PushBack(Fraction& f)
{
	BaseContainer* containerPtr = Fabric::CreateContainer(&f);
	if (m_firstPtr == nullptr && m_lastPtr == nullptr)
	{
		m_firstPtr = containerPtr;
		m_lastPtr = containerPtr;
		return;
	}
	m_lastPtr->SetNextPtr(containerPtr);
	m_lastPtr = containerPtr;
}


void List::Delete()
{
	if (m_firstPtr == nullptr) return;
	if (m_firstPtr == m_lastPtr)
	{
		delete m_firstPtr;
		m_firstPtr = nullptr;
		m_lastPtr = nullptr;
		return;
	}
	BaseContainer* buf = m_firstPtr;
	m_firstPtr = m_firstPtr->GetNextPtr();
	buf->SetNextPtr(nullptr);
	delete buf;
}

std::string List::ToString(BaseContainer& f)
{
	return f.GetObj()->ToString();
}

bool List::IsContain(const Fraction& f) const
{
	char* fKey = new char[150];
	fKey = f.ToString();
	for(BaseContainer* curptr = m_firstPtr; curptr != nullptr; curptr=curptr->GetNextPtr())
	{
		char* listItemKey = new char[150];
		listItemKey = curptr->Get()->ToString();
		if (strcmp(fKey, listItemKey) == 0) return true;
	}
	return false;
}

BaseContainer* List::GetFirstPtr()
{
	return m_firstPtr;
}

char* List::ToString() //ß ÍÅ ÏÎÍÈÌÀÞ
{
	char* str = new char[150];
	if (m_firstPtr == nullptr)
	{
		sprintf(str, "List is empty") ;
		return str;
	}

	BaseContainer* curPtr = m_firstPtr;

	
	for (; curPtr != nullptr; curPtr = curPtr->GetNextPtr())
	{
		if (curPtr == m_firstPtr) strcpy(str, curPtr->Get()->ToString());
		else
		{
			strcat(str, " ");
			strcat(str, curPtr->Get()->ToString());
		}
	}
	std::cout << std::endl;
	return str;
}


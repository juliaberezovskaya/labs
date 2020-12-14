#include "List.h"

List::List()
{
	m_firstPtr = nullptr;
	m_lastPtr = nullptr;
}

void List::PushBegin(Fraction& f)
{
	BaseContainer* containerPtr = Fabric::CreateContainer(f);
	if (m_firstPtr == nullptr && m_lastPtr == nullptr)
	{
		m_firstPtr = containerPtr;
		m_lastPtr = containerPtr;
		return;
	}
	containerPtr->SetNextPtr(m_firstPtr);
	m_firstPtr = containerPtr;
}

void List::PushBegin(CalculateFraction& f)
{
	BaseContainer* thisptr = Fabric::CreateContainer(f);
	if (m_firstPtr == nullptr && m_lastPtr == nullptr)
	{
		m_firstPtr = thisptr;
		m_lastPtr = thisptr;
		return;
	}
	thisptr->SetNextPtr(m_firstPtr);
	m_firstPtr = thisptr;
}

void List::PushBegin(MixedFraction& f)
{
	BaseContainer* thisptr = Fabric::CreateContainer(f);
	if (m_firstPtr == nullptr && m_lastPtr == nullptr)
	{
		m_firstPtr = thisptr;
		m_lastPtr = thisptr;
		return;
	}
	thisptr->SetNextPtr(m_firstPtr);
	m_firstPtr = thisptr;
}

void List::PushBack(Fraction& f)
{
	BaseContainer* containerPtr = Fabric::CreateContainer(f);
	if (m_firstPtr == nullptr && m_lastPtr == nullptr)
	{
		m_firstPtr = containerPtr;
		m_lastPtr = containerPtr;
		return;
	}
	m_lastPtr->SetNextPtr(containerPtr);
	m_lastPtr = containerPtr;
}

void List::PushBack(CalculateFraction& f)
{
	BaseContainer* containerPtr = Fabric::CreateContainer(f);
	if (m_firstPtr == nullptr && m_lastPtr == nullptr)
	{
		m_firstPtr = containerPtr;
		m_lastPtr = containerPtr;
		return;
	}
	m_lastPtr->SetNextPtr(containerPtr);
	m_lastPtr = containerPtr;

}

void List::PushBack(MixedFraction& f)
{
	BaseContainer* containerPtr = Fabric::CreateContainer(f);
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

std::string List::ToString(FrContainer& f)
{
	return f.GetObj().ToString();
}

bool List::IsContain(const Fraction& f) const
{
	std::string fKey = f.ToString();
	for(BaseContainer* curptr = m_firstPtr; curptr != nullptr; curptr=curptr->GetNextPtr())
	{
		std::string listItemKey = curptr->Get().ToString();
		if (fKey == listItemKey) return true;
	}
	return false;
}


std::ostream& operator<<(std::ostream& stream, const List& list)
{
	if (list.m_firstPtr == nullptr)
	{
		stream << "List is empty";
		return stream;
	}

	BaseContainer* curPtr = list.m_firstPtr;
	
	for (; curPtr != nullptr; curPtr = curPtr->GetNextPtr())
	{
		if (curPtr != list.m_firstPtr) stream << ' ';
		stream << curPtr->Get().ToString().c_str();
	}
	std::cout << std::endl;
	return stream;
}

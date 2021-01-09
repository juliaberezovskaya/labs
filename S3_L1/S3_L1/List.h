#pragma once
#include "Fabric.h"

template <class Type> class List
{
public:
	List()
	{
		m_firstPtr = nullptr;
		m_lastPtr = nullptr;
	}

	void PushBegin(Type& f)
	{
		BaseContainer<Type>* containerPtr = Fabric::CreateContainer(&f);
		if (m_firstPtr == nullptr && m_lastPtr == nullptr)
		{
			m_firstPtr = containerPtr;
			m_lastPtr = containerPtr;

			return;
		}
		containerPtr->SetNextPtr(m_firstPtr);
		m_firstPtr = containerPtr;
	}

	void PushBack(Type& f)
	{
		BaseContainer<Type>* containerPtr = Fabric::CreateContainer(&f);
		if (m_firstPtr == nullptr && m_lastPtr == nullptr)
		{
			m_firstPtr = containerPtr;
			m_lastPtr = containerPtr;
			return;
		}
		m_lastPtr->SetNextPtr(containerPtr);
		m_lastPtr = containerPtr;
	}

	void Delete()
	{
		if (m_firstPtr == nullptr) return;
		if (m_firstPtr == m_lastPtr)
		{
			delete m_firstPtr;
			m_firstPtr = nullptr;
			m_lastPtr = nullptr;
			return;
		}
		BaseContainer<Type>* buf = m_firstPtr;
		m_firstPtr = m_firstPtr->GetNextPtr();
		buf->SetNextPtr(nullptr);
		delete buf;
	}

	//static std::string ToString(BaseContainer& f);

	bool IsContain(const Type& f) const
	{

	for(BaseContainer<Type>* curptr = m_firstPtr; curptr != nullptr; curptr=curptr->GetNextPtr())
	{
		if (*curptr->Get() == f) return true;
	}
	return false;
	}

	BaseContainer<Type>* GetFirstPtr()
	{
		return m_firstPtr;
	}

	const char* ToString(char* bufString)
	{
		const char* str = {"List is empty"};
		if (m_firstPtr == nullptr) {
			strcpy(bufString, str);
			return bufString;
		}
		
		BaseContainer<Type>* curPtr = m_firstPtr;

		std::stringstream buf;
		for (; curPtr != nullptr; curPtr = curPtr->GetNextPtr())
		{
			if (curPtr == m_firstPtr) buf << *curPtr->Get();//strcpy(str, curPtr->Get()->ToString());
			else
			{
				buf << " " << *curPtr->Get();
				//strcat(str, " ");
				//strcat(str, curPtr->Get()->ToString());
			}
		}
	//	std::cout << buf.str() << std::endl;
		//.s_str
		std::string buf_string = buf.str();
		strcpy(bufString, buf_string.c_str());
		return bufString;
	}

private:
	BaseContainer<Type> *m_firstPtr, *m_lastPtr;
};


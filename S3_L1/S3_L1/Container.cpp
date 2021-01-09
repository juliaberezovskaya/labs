//#include "Container.h"
//
//template <class Type>
//BaseContainer<Type>::BaseContainer()
//{
//	next = nullptr;
//	obj = nullptr;
//}
//
//template <class Type>
//BaseContainer<Type>::BaseContainer(Type* f)
//{
//	next = nullptr;
//	obj = f;
//}
//
//template <class Type>
//BaseContainer<Type>::~BaseContainer()
//{
//	delete next;
//}
//
//template <class Type>
//void BaseContainer<Type>::SetNextPtr(BaseContainer* ptr)
//{
//	next = ptr;
//}
//
//template <class Type>
//Type* BaseContainer<Type>::Get()
//{
//	return obj;
//}
//
//template <class Type>
//BaseContainer<Type>* BaseContainer<Type>::GetNextPtr()
//{
//	return next;
//}
//
//template <class Type>
//Type* BaseContainer<Type>::GetObj()
//{
//	return obj;
//}
//
//
////BaseContainer::~BaseContainer()
////{
////	delete next;
////}
////
////BaseContainer::BaseContainer()
////{
////	obj = nullptr;
////	next = nullptr;
////}
////
////BaseContainer::BaseContainer(Fraction* f)
////{
////	obj = f;
////	next = nullptr;
////}
////
////void BaseContainer::SetNextPtr(BaseContainer* ptr)
////{
////	next = ptr;
////}
////
////Fraction* BaseContainer::Get()
////{
////	return obj;
////}
////
////BaseContainer* BaseContainer::GetNextPtr()
////{
////	return next;
////}
////
////Fraction* BaseContainer::GetObj()
////{
////	return obj;
////}
////

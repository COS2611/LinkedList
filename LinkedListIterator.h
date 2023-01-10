#ifndef LinkedListIterator_h
#define LinkedListIterator_h

#include "NodeType.h"


template <class Type>
class LinkedListIterator
{
public:
	LinkedListIterator();
	// Postcondition: current = NULL;
	
	LinkedListIterator(NodeType<Type> *ptr);
	// Postcondition: current = ptr;
	
	Type operator* ();
	// Returns the info contained in the node.
	
	LinkedListIterator<Type> operator++ ();
	// Postcondition: The iterator is advanced to the next node.
	
	bool operator== (const LinkedListIterator<Type>& right) const;
	// Postcondition: Return true if this iterator is equal to the
	// iterator specified.
	
	bool operator!= (const LinkedListIterator<Type>& right) const;
	// Postcondition: Returns true if this iterator is not equal to
	// the iterator specified.
	
private:
	NodeType<Type> *current;
};


template <class Type>
LinkedListIterator<Type>::LinkedListIterator()
: current (NULL) {}


template <class Type>
LinkedListIterator<Type>::LinkedListIterator(NodeType<Type> *ptr)
	: current (ptr) {}


template <class Type>
Type LinkedListIterator<Type>::operator* ()
{
	return current->info;
}


template <class Type>
LinkedListIterator<Type> LinkedListIterator<Type>::operator++ ()
{
	current = current->link;
	return *this;
}


template <class Type>
bool LinkedListIterator<Type>::operator== (const LinkedListIterator<Type>& right) const
{
	return (current == right.current);
}

template <class Type>
bool LinkedListIterator<Type>::operator!= (const LinkedListIterator<Type>& right) const
{
	return (current != right.current);
}


#endif /* LinkedListIterator_h */

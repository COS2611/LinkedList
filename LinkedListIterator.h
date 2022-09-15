#ifndef LinkedListIterator_h
#define LinkedListIterator_h

#include "NodeType.h"


template <class elemType>
class LinkedListIterator
{
public:
	LinkedListIterator();
	// Postcondition: current = NULL;
	
	LinkedListIterator(NodeType<elemType> *ptr);
	// Postcondition: current = ptr;
	
	elemType operator* ();
	// Returns the info contained in the node.
	
	LinkedListIterator<elemType> operator++ ();
	// Postcondition: The iterator is advanced to the next node.
	
	bool operator== (const LinkedListIterator<elemType>& right) const;
	// Postcondition: Return true if this iterator is equal to the
	// iterator specified.
	
	bool operator!= (const LinkedListIterator<elemType>& right) const;
	// Postcondition: Returns true if this iterator is not equal to
	// the iterator specified.
	
private:
	NodeType<elemType> *current;
};


template <class elemType>
LinkedListIterator<elemType>::LinkedListIterator()
: current (NULL) {}


template <class elemType>
LinkedListIterator<elemType>::LinkedListIterator(NodeType<elemType> *ptr)
	: current (ptr) {}


template <class elemType>
elemType LinkedListIterator<elemType>::operator* ()
{
	return current->info;
}


template <class elemType>
LinkedListIterator<elemType> LinkedListIterator<elemType>::operator++ ()
{
	current = current->link;
	return *this;
}


template <class elemType>
bool LinkedListIterator<elemType>::operator== (const LinkedListIterator<elemType>& right) const
{
	return (current == right.current);
}

template <class elemType>
bool LinkedListIterator<elemType>::operator!= (const LinkedListIterator<elemType>& right) const
{
	return (current != right.current);
}


#endif /* LinkedListIterator_h */

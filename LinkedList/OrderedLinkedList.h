#ifndef OrderedLinkedList_h
#define OrderedLinkedList_h

#include "NodeType.h"
#include "LinkedList.h"

template <class elemType>
class OrderedLinkedList : public LinkedListType<elemType>
{
public:
	bool search(const elemType& searchItem) const;	// returns true if item is in the list
	void insert(const elemType& newItem);			// insert node in place
	void insertFirst(const elemType& newItem);		// insert node at beginning
	void insertLast(const elemType& newItem);		// insert node at the end
	void deleteNode(const elemType& deleteItem);	// delete a node from the list
};


template <class elemType>
bool OrderedLinkedList<elemType>::search(const elemType& searchItem) const
{
	
}


template <class elemType>
void OrderedLinkedList<elemType>::insert(const elemType& newItem)
{
	
}


template <class elemType>
void OrderedLinkedList<elemType>::insertFirst(const elemType& newItem)
{

}


template <class elemType>
void OrderedLinkedList<elemType>::insertLast(const elemType& newItem)
{

}


template <class elemType>
void OrderedLinkedList<elemType>::deleteNode(const elemType& deleteItem)
{

}

#endif /* OrderedLinkedList_h */

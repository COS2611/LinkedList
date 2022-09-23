#ifndef LinkedList_h
#define LinkedList_h

#include "NodeType.h"
#include "LinkedListIterator.h"


template <class elemType>
class LinkedListType
{
public:
	LinkedListType();								// default constructor
	~LinkedListType();								// destructor
	void initializeList();							// initialize list as empty list
	void destroyList();								// deallocate memory
	void print() const;								// print the list
	bool isEmpty() const;							// returns true if list is empty
	int length() const;								// returns the number of nodes in the list
	elemType front() const;							// returns the first node's info
	elemType back() const;							// returns the last node's info
	LinkedListIterator<elemType> begin();			// returns an iterator to the first node
	LinkedListIterator<elemType> end();				// returns an iterator to the last node

	
	// overloaded assignment operator
	const LinkedListType<elemType>& operator= (const LinkedListType<elemType>& otherList);
	void copyList(const LinkedListType<elemType>& otherList);	// make an identical copy of the linked list
	LinkedListType (const LinkedListType<elemType>& otherList);	// copy constructor

	
	/// virtual functions (defined in derived classes)
	virtual bool search(const elemType& searchItem) const = 0;	// returns true if item is in the list
	virtual void insertFirst(const elemType& newItem) = 0;		// insert node at beginning
	virtual void insertLast(const elemType& newItem) = 0;		// insert node at the end
	virtual void deleteNode(const elemType& deleteItem) = 0;	// delete a node from the list

	
protected:
	int count;					// number of elements in the list
	NodeType<elemType> *first;	// pointer to head node
	NodeType<elemType> *last;	// pointer to tail node
};


template <class elemType>
LinkedListType<elemType>::LinkedListType()
	: first (NULL), last (NULL), count (0) {}


template <class elemType>
void LinkedListType<elemType>::destroyList()
{
	NodeType<elemType> *temp;	// pointer to traverse list
	
	while (first != NULL)
	{
		temp = first;
		first = first->link;
		delete temp;
	}
	last = NULL;
	count = 0;
}


template <class elemType>
void LinkedListType<elemType>::initializeList()
{
	destroyList();
}


template <class elemType>
LinkedListType<elemType>::~LinkedListType()
{
	destroyList();
}


template <class elemType>
void LinkedListType<elemType>::print() const
{
	NodeType<elemType> *current {first};
	while (current != NULL)
	{
		std::cout << current->info << " ";
		current = current->link;
	}
}


template <class elemType>
bool LinkedListType<elemType>::isEmpty() const
{
	return first == NULL;
}


template <class elemType>
int LinkedListType<elemType>::length() const
{
	return count;
}


template <class elemType>
elemType LinkedListType<elemType>::front() const
{
	assert(first != NULL);
	return first->info;
}


template <class elemType>
elemType LinkedListType<elemType>::back() const
{
	assert(last != NULL);
	return last->info;
}


template <class elemType>
LinkedListIterator<elemType> LinkedListType<elemType>::begin()
{
	LinkedListIterator<elemType> temp {first};
	return temp;
}


template <class elemType>
LinkedListIterator<elemType> LinkedListType<elemType>::end()
{
	LinkedListIterator<elemType> temp {NULL};
	return temp;
}


template <class elemType>
LinkedListType<elemType>::LinkedListType(const LinkedListType<elemType>& otherList)
{
	first = NULL;
	copyList(otherList);
}


template <class elemType>
void LinkedListType<elemType>::copyList(const LinkedListType<elemType>& otherList)
{
	NodeType<elemType> *newNode = NULL;	// pointer to create a node
	NodeType<elemType> *current = NULL;	// pointer to traverse the list
	
	// make sure the destination list is empty
	if (first != NULL)
	{
		destroyList();
	}
	
	if (otherList.first == NULL)	// if the source list is empty
	{
		first = NULL;
		last = NULL;
		count = 0;
	}
	
	else
	{
		current = otherList.first;
		count = otherList.count;
		
		// copy the first node
		first = new NodeType<elemType>;
		first->info = current->info;
		first->link = NULL;
		last = first;
		current = current->link;
		
		// copy the remaining list
		while (current != NULL)
		{
			newNode	= new NodeType<elemType>;
			newNode->info = current->info;
			newNode->link = NULL;
			last->link = newNode;
			last = newNode;
			current = current->link;
		}
	}
}


template <class elemType>
const LinkedListType<elemType>& LinkedListType<elemType>::operator= (const LinkedListType<elemType>& otherList)
{
	if (this != &otherList)	// avoid self-copy
	{
		copyList(otherList);
	}
	return *this;
}


#endif /* LinkedList_h */



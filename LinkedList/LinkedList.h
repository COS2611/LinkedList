#ifndef LinkedList_h
#define LinkedList_h

#include "NodeType.h"
#include "LinkedListIterator.h"


template <class elemType>
class LinkedListType
{
protected:
	int count;					// number of elements in the list
	NodeType<elemType> *first;	// pointer to head node
	NodeType<elemType> *last;	// pointer to tail node
	
	
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
	
	
	// TODO: create a method to avoid insertion of duplicate elements
	
	// overloaded assignment operator
	const LinkedListType<elemType>& operator= (const LinkedListType<elemType>& otherList);
	void copyList(const LinkedListType<elemType>& otherList);	// make an identical copy of the linked list
	LinkedListType (const LinkedListType<elemType>& otherList);	// copy constructor
	
	// TODO: implement evenOddPArtition
	NodeType<elemType> *evenOddIndexPartition(NodeType<elemType> *head);
	// Arranges the list such that all the even index nodes appear before the odd index nodes
	

	
	/// virtual functions (defined in derived classes)
	virtual bool search(const elemType& searchItem) const = 0;	// returns true if item is in the list
	virtual void insertFirst(const elemType& newItem) = 0;		// insert node at beginning
	virtual void insertLast(const elemType& newItem) = 0;		// insert node at the end
	virtual void deleteNode(const elemType& deleteItem) = 0;	// delete a node from the list
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


//template <class elemType>
//NodeType<elemType> LinkedListType<elemType>::*evenOddIndexPartition(NodeType<elemType> *head)
//// Method 2: fewer pointers
//{
//	NodeType<elemType> *evenPtr = head;			// pointer to the next even node
//	NodeType<elemType> *oddPtr = head->link;	// pointer to the next odd node
//	NodeType<elemType> *oddHead = oddPtr;		// start of the odd sublist
//	
//	// Case 1: The list is empty, or contains only one node
//	if (!head && !head->link)
//	{
//		return head;
//	}
//	
//	// Case 2: The list contains more than one node
//	while (oddPtr && oddPtr->link)
//	{
//		evenPtr->link = oddPtr->link;
//		evenPtr = oddPtr->link;
//		oddPtr->link = evenPtr->link;
//		oddPtr = evenPtr->link;
//	}
//	
//	// join the end of the even list to the beginning of the odd list
//	evenPtr->link = oddHead;
//	
//	return head;
//}



//template <class elemType>
//NodeType<elemType> *evenOddIndexPartition(NodeType<elemType> *head)
//// Method 1: use extra pointers
//{
//	NodeType<elemType> *current = head;	// pointer to traverse the list
//	unsigned int index = 0;				// keep track of the index position
//
//	// Case 1: The list is empty, or contains only one node
//	if (!head && !head->link)
//	{
//		return head;
//	}
//
//	// Case 2: The list contains more than one node
//	NodeType<elemType> *oddDummy = new NodeType<elemType>(-1);
//	NodeType<elemType> *evenDummy = new NodeType<elemType>(-1);
//	NodeType<elemType> *oddTail = oddDummy;
//	NodeType<elemType> *evenTail = evenDummy;
//
//
//	while (current)
//	{
//		if (index % 2 == 0)
//		{
//			evenTail->link = current;
//			evenTail = current;
//		}
//
//		else
//		{
//			oddTail->link = current;
//			oddTail = current;
//		}
//
//		current = current->link;
//		index++;
//	}
//
//	// join the end of the even list to the beginning of the odd list
//	evenTail->link = oddDummy->link;
//	oddTail->link = NULL;
//}

#endif /* LinkedList_h */



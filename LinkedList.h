#ifndef LinkedList_h
#define LinkedList_h

#include "NodeType.h"
#include "LinkedListIterator.h"


template <class Type>
class LinkedListType
{
public:
	/// The following methods are not included in the text book:
//	friend void deleteOc(LinkedListType<Type> &L1, const LinkedListType<Type> &L2);
	NodeType<Type>* getFirst() const;
	NodeType<Type>* getLast() const;
	
//protected:
public:
	int count;				// number of elements in the list
	NodeType<Type> *first;	// pointer to head node
	NodeType<Type> *last;	// pointer to tail node
	
	
public:
	LinkedListType();								// default constructor
	~LinkedListType();								// destructor
	void initializeList();							// initialize list as empty list
	void destroyList();								// deallocate memory
	void print() const;								// print the list
	bool isEmpty() const;							// returns true if list is empty
	int length() const;								// returns the number of nodes in the list
	Type front() const;							// returns the first node's info
	Type back() const;							// returns the last node's info
	Type max() const;	 						// returns the largest element in the list
	Type min() const;							// returns the smallest element in the list
	LinkedListIterator<Type> begin();			// returns an iterator to the first node
	LinkedListIterator<Type> end();				// returns an iterator to the last node
	
	
	// TODO: create a method to avoid insertion of duplicate elements
	// TODO: overload < and > operators for generic Type
	
	// overloaded assignment operator
	const LinkedListType<Type>& operator= (const LinkedListType<Type>& otherList);
	void copyList(const LinkedListType<Type>& otherList);	// make an identical copy of the linked list
	LinkedListType (const LinkedListType<Type>& otherList);	// copy constructor
	
	// TODO: implement evenOddPartition
	NodeType<Type> *evenOddIndexPartition(NodeType<Type> *head);
	// Arranges the list such that all the even index nodes appear before the odd index nodes
	

	
	/// virtual functions (defined in derived classes)
	virtual bool search(const Type& searchItem) const = 0;	// returns true if item is in the list
	virtual void insertFirst(const Type& newItem) = 0;		// insert node at beginning
	virtual void insertLast(const Type& newItem) = 0;		// insert node at the end
	virtual void deleteNode(const Type& deleteItem) = 0;	// delete a node from the list
};

template <class Type>
NodeType<Type>* LinkedListType<Type>::getFirst() const { return first; }

template <class Type>
NodeType<Type>* LinkedListType<Type>::getLast() const { return last; }


template <class Type>
LinkedListType<Type>::LinkedListType()
	: first (NULL), last (NULL), count (0) {}


template <class Type>
void LinkedListType<Type>::destroyList()
{
	NodeType<Type> *temp;	// pointer to traverse list
	
	while (first != NULL)
	{
		temp = first;
		first = first->link;
		delete temp;
	}
	last = NULL;
	count = 0;
}


template <class Type>
void LinkedListType<Type>::initializeList()
{
	destroyList();
}


template <class Type>
LinkedListType<Type>::~LinkedListType()
{
	destroyList();
}


template <class Type>
void LinkedListType<Type>::print() const
{
	NodeType<Type> *current = first;
	while (current != NULL)
	{
		std::cout << current->info << " ";
		current = current->link;
	}
}


template <class Type>
bool LinkedListType<Type>::isEmpty() const
{
	return first == NULL;
}


template <class Type>
int LinkedListType<Type>::length() const
{
	return count;
}


template <class Type>
Type LinkedListType<Type>::front() const
{
	assert(first != NULL);
	return first->info;
}


template <class Type>
Type LinkedListType<Type>::back() const
{
	assert(last != NULL);
	return last->info;
}


template <class Type>
Type LinkedListType<Type>::max() const
{
	NodeType<Type> *current = this->first;
	Type largestElement = current->info;
	
	if (!this->first)
	{
		return NULL;
	}
	
	else
	{
		while(current)
		{
			if (current->info > largestElement)
			{
				largestElement = current->info;
			}
			current = current->link;
		}
	}
	return largestElement;
}


template <class Type>
Type LinkedListType<Type>::min() const
{
	NodeType<Type> *current = this->first;
	Type smallestElement = current->info;
	
	if (!this->first)
	{
		return NULL;
	}
	
	else
	{
		while(current)
		{
			if (current->info < smallestElement)
			{
				smallestElement = current->info;
			}
			current = current->link;
		}
	}
	return smallestElement;
}


template <class Type>
LinkedListIterator<Type> LinkedListType<Type>::begin()
{
	LinkedListIterator<Type> temp {first};
	return temp;
}


template <class Type>
LinkedListIterator<Type> LinkedListType<Type>::end()
{
	LinkedListIterator<Type> temp {NULL};
	return temp;
}


template <class Type>
LinkedListType<Type>::LinkedListType(const LinkedListType<Type>& otherList)
{
	first = NULL;
	copyList(otherList);
}


template <class Type>
void LinkedListType<Type>::copyList(const LinkedListType<Type>& otherList)
{
	NodeType<Type> *newNode = NULL;	// pointer to create a node
	NodeType<Type> *current = NULL;	// pointer to traverse the list
	
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
		first = new NodeType<Type>;
		first->info = current->info;
		first->link = NULL;
		last = first;
		current = current->link;
		
		// copy the remaining list
		while (current != NULL)
		{
			newNode	= new NodeType<Type>;
			newNode->info = current->info;
			newNode->link = NULL;
			last->link = newNode;
			last = newNode;
			current = current->link;
		}
	}
}


template <class Type>
const LinkedListType<Type>& LinkedListType<Type>::operator= (const LinkedListType<Type>& otherList)
{
	if (this != &otherList)	// avoid self-copy
	{
		copyList(otherList);
	}
	return *this;
}


//template <class Type>
//NodeType<Type> LinkedListType<Type>::*evenOddIndexPartition(NodeType<Type> *head)
//// Method 2: fewer pointers
//{
//	NodeType<Type> *evenPtr = head;			// pointer to the next even node
//	NodeType<Type> *oddPtr = head->link;	// pointer to the next odd node
//	NodeType<Type> *oddHead = oddPtr;		// start of the odd sublist
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



//template <class Type>
//NodeType<Type> *evenOddIndexPartition(NodeType<Type> *head)
//// Method 1: use extra pointers
//{
//	NodeType<Type> *current = head;	// pointer to traverse the list
//	unsigned int index = 0;				// keep track of the index position
//
//	// Case 1: The list is empty, or contains only one node
//	if (!head && !head->link)
//	{
//		return head;
//	}
//
//	// Case 2: The list contains more than one node
//	NodeType<Type> *oddDummy = new NodeType<Type>(-1);
//	NodeType<Type> *evenDummy = new NodeType<Type>(-1);
//	NodeType<Type> *oddTail = oddDummy;
//	NodeType<Type> *evenTail = evenDummy;
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



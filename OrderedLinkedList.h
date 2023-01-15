#ifndef OrderedLinkedList_h
#define OrderedLinkedList_h

#include "NodeType.h"
#include "LinkedList.h"

template <class Type>
class OrderedLinkedList : public LinkedListType<Type>
{
//	friend void deleteOc(OrderedLinkedList<Type>& L1, const OrderedLinkedList<Type>& L2);
	// FIXME: declaring deleteOc as a friend results in compilation error
	
public:
	bool search(const Type& searchItem) const;	// returns true if item is in the list
	void insert(const Type& newItem);			// insert node in place
	void insertFirst(const Type& newItem);		// insert node at beginning
	void insertLast(const Type& newItem);		// insert node at the end
	void deleteNode(const Type& deleteItem);	// delete a node from the list
	
	
	void mergeLists(OrderedLinkedList<Type> &list1, OrderedLinkedList<Type> &list2);
//	This function creates a new list by merging the elements
//	of list1 and list2.
//	Postcondition: first points to the merged list; list1 and list2 are empty
	
//	OrderedLinkedList<Type> *mergeLists(OrderedLinkedList<Type> &list1, OrderedLinkedList<Type> &list2);
	// same as void mergeLists, but this method returns the head of the new list
};


template <class Type>
bool OrderedLinkedList<Type>::search(const Type& searchItem) const
{
	
	NodeType<Type> *current = new NodeType<Type>;	// node to traverse the list
	current = this->first;									// start search from first node
	bool found = false;
	
	while (current != NULL && !found)
	{
		if (current->info >= searchItem)
		{
			found = true;
		}
		else
		{
			current = current->link;
		}
	}
	
	if (found)
	{
		found = (current->info == searchItem);	// test for eqaulity
	}
	
	return found;
}


template <class Type>
void OrderedLinkedList<Type>::insert(const Type& newItem)
{
	NodeType<Type> *current = NULL;			// pointer to traverse the list
	NodeType<Type> *trailCurrent = NULL;	// pointer just before current
	NodeType<Type> *newNode = NULL;			// pointer to create a new node
	
	bool found;
	
	newNode = new NodeType<Type>;	// create the node
	newNode->info = newItem;			// store newItem in the node
	newNode->link = NULL;				// redundant, but included for readability
	
	
	// Case 1: The list is initially empty
	if (this->first == NULL)
	{
		this->first = newNode;
		this->last = newNode;
		this->count++;
	}
	
	else	// the list is not empty
	{
		current = this->first;
		found = false;
		
		// search the list
		while (current != NULL && !found)
		{
			if (current->info >= newItem)
			{
				found = true;
			}
			else
			{
				trailCurrent = current;
				current = current->link;
			}
		}
		
		// Case 2: The new item is the smallest item in the list
		if (current == this->first)
		{
			newNode->link = this->first;
			this->first = newNode;
			this->count++;
		}
		
		
		else	// Case 3: The item is to be inserted somewhere in the list
		{
			// Case 3b: The new item is to be inserted somewhere in the middle of the list
			trailCurrent->link = newNode;
			newNode->link = current;
			
			if (current == NULL)	// Case 3a: The new item is larger than all the items in the list
			{
				this->last = newNode;
			}
		}
	}
}


template <class Type>
void OrderedLinkedList<Type>::insertFirst(const Type& newItem)
{
	insert(newItem);
}


template <class Type>
void OrderedLinkedList<Type>::insertLast(const Type& newItem)
{
	insert(newItem);
}


template <class Type>
void OrderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	// TODO: implement me
}


template <class Type>
void OrderedLinkedList<Type>::mergeLists(OrderedLinkedList<Type> &list1, OrderedLinkedList<Type> &list2)
{
	// TODO: implement me
}


// Function deletes every element of L2 found in L1
template <class Type>
void deleteOc(OrderedLinkedList<Type>& L1, const OrderedLinkedList<Type>& L2)
{
	// TODO: implement me
}

#endif /* OrderedLinkedList_h */

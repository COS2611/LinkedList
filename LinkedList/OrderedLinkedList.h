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
	
	NodeType<elemType> *current = new NodeType<elemType>;	// node to traverse the list
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


template <class elemType>
void OrderedLinkedList<elemType>::insert(const elemType& newItem)
{
	NodeType<elemType> *current = NULL;			// pointer to traverse the list
	NodeType<elemType> *trailCurrent = NULL;	// pointer just before current
	NodeType<elemType> *newNode = NULL;			// pointer to create a new node
	
	bool found;
	
	newNode = new NodeType<elemType>;	// create the node
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


template <class elemType>
void OrderedLinkedList<elemType>::insertFirst(const elemType& newItem)
{
	return;
}


template <class elemType>
void OrderedLinkedList<elemType>::insertLast(const elemType& newItem)
{
	return;
}


template <class elemType>
void OrderedLinkedList<elemType>::deleteNode(const elemType& deleteItem)
{
	return;
}

#endif /* OrderedLinkedList_h */

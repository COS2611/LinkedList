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
	insert(newItem);
}


template <class elemType>
void OrderedLinkedList<elemType>::insertLast(const elemType& newItem)
{
	insert(newItem);
}


template <class elemType>
void OrderedLinkedList<elemType>::deleteNode(const elemType& deleteItem)
{
	NodeType<elemType> *current = NULL;
	NodeType<elemType> *trailCurrent = NULL;
	bool found;
	
	if (this->first == NULL)	// Case 1: The list is initially empty
	{
		std::cout << "Cannot delete from an empty list." << std::endl;
	}
	
	else
	{
		current = this->first;
		found = false;
		
		while (current != NULL && !found)
		{
			if (current->info == deleteItem)
			{
				found = true;
			}
			else
			{
				trailCurrent = current;
				current = current->link;
			}
		}
		
		// Case 4: The list is not empty, but the item to be deleted is not in the list.
		if (current == NULL)
		{
			std::cout << "The item to be deleted is not in the list." << std::endl;
		}
		
		else
		{
			if (current->info == deleteItem) // the item is in the list
			{
				// Case 2: The item to be deleted is contained in the first node
				if (this->first == current)
				{
					this->first = this->first->link;
					
					if (this->first == NULL)
					{
						this->last = NULL;
					}
					delete current;
				}
				
				else	// Case 3: The item to be deleted is somewhere else in the list.
				{
					trailCurrent->link = current->link;
					if (current == this->last)
					{
						this->last = trailCurrent;
					}
					delete current;
				}
				this->count--;
			}
			
			else	// Case 4: The list is not empty, but the item to be deleted is not in the list.
			{
				std::cout << "The item to be deleted is not in the list." << std::endl;
			}
		}
	}
}

#endif /* OrderedLinkedList_h */

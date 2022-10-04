#ifndef UnorderedLinkedList_h
#define UnorderedLinkedList_h

#include "NodeType.h"
#include "LinkedList.h"


template <class elemType>
class UnorderedLinkedList : public LinkedListType<elemType>
{
public:
	bool search(const elemType& searchItem) const;	// returns true if item is in the list
	void insertFirst(const elemType& newItem);		// insert node at beginning
	void insertLast(const elemType& newItem);		// insert node at the end
	void deleteNode(const elemType& deleteItem);	// delete a node from the list
	void buildListForward();
	void buildListBackward();
	
	
	// TODO: implement insertAfter
	// TODO: implement method to exchange two nodes
	
	void shareList(const UnorderedLinkedList<elemType>& Orig, UnorderedLinkedList<elemType>& listA, UnorderedLinkedList<elemType>& listB);
	// Copies all elements in an even index position to listA
	// and all elements in an odd index position to listB
	
	
};

template <class elemType>
bool UnorderedLinkedList<elemType>::search(const elemType& searchItem) const
{
	NodeType<elemType> *current = this->first;
	bool found = false;
	
	while (current != NULL && !found)
	{
		if (current->info == searchItem)
		{
			found = true;
		}
		else
		{
			current = current->link;
		}
	}
	return found;
}


template <class elemType>
void UnorderedLinkedList<elemType>::insertFirst(const elemType& newItem)
{
	NodeType<elemType> *newNode = new NodeType<elemType>;
	newNode->info = newItem;
	newNode->link = this->first;	// Point the new node to the head
	this->first = newNode;			// Set the new node as the head
	this->count++;					// Increment the number of elements in the list
}


template <class elemType>
void UnorderedLinkedList<elemType>::insertLast(const elemType& newItem)
{
	NodeType<elemType> *newNode = new NodeType<elemType>;
	newNode->info = newItem;
	newNode->link = NULL;
	
	if (this->first == NULL) 			// if the list is empty
	{
		this->first = newNode;
		this->last = newNode;
	}
	
	else
	{
		this->last->link = newNode; 	// insert newNode after last
		this->last = newNode;			// make newNode the last node
	}
	this->count++;
}


template <class elemType>
void UnorderedLinkedList<elemType>::deleteNode(const elemType& deleteItem)
{
	NodeType<elemType> *current = NULL;
	NodeType<elemType> *trailCurrent = NULL;	// ptr before current ptr
	bool found = false;
	
	if (this->first == NULL)			// the list is empty
	{
		std::cout << "Cannot delete from an empty list." << std::endl;
	}
	
	else
	{
		if (this->first->info == deleteItem)	// the first node is to be deleted
		{
			current = this->first;
			this->first = this->first->link;	// point first to the next node
			
			if (this->first == NULL)			// the list has only one node
			{
				this->last = NULL;
			}
			delete current;
			this->count--;
		}
		
		else									// continue searching list
		{
			trailCurrent = this->first;
			current = this->first->link;		// move to the next node
			
			while (current != NULL && !found)	// continue searching
			{
				if (current->info != deleteItem)
				{
					trailCurrent = current;
					current = current->link;
				}
				
				else
				{
					found = true;
				}
				
				if (found)	// if found, delete node
				{
					trailCurrent->link = current->link;
					this->count--;
					
					if (this->last == current)
					{
						this->last = trailCurrent;
					}
					delete current;
				}
			}
			if (!found)
			{
				std::cout << "The item to be deleted is not in the list." << std::endl;
			}
		}
	}
}


template <class elemType>
void UnorderedLinkedList<elemType>::buildListForward()
{
	// TODO: update buildListForward() to work with all types
	elemType num {};
	std::cout << "Enter a list of elements ending with -999:" << std::endl;
	std::cin >> num;
	while (num != -999)
	{
		insertLast(num);
		std::cin >> num;
	}
}


template <class elemType>
void UnorderedLinkedList<elemType>::buildListBackward()
{
	// TODO: update buildListBackward() to work with all types
	elemType num {};
	std::cout << "Enter a list of elements ending with -999:" << std::endl;
	std::cin >> num;
	while (num != -999)
	{
		insertFirst(num);
		std::cin >> num;
	}
}


/*
template <class elemType>
void insertAfter(NodeType<elemType> *previous, int newValue)
{
	// check if the previous node is NULL
	if (previous == NULL)
	{
		std::cout << "Previous cannot be NULL" << std::endl;
		return;
	}
	
	// create a new node
	NodeType<elemType> *newNode = new NodeType<elemType>();
	newNode->info = newValue;
	
	// insert the new node after the previous node
	newNode->link = previous->link;
	previous->link = newNode;
} */


template <class elemType>
void UnorderedLinkedList<elemType>::shareList(const UnorderedLinkedList<elemType>& Orig, UnorderedLinkedList<elemType>& listA, UnorderedLinkedList<elemType>& listB)
{
	
	// Case 1: The original list is empty
	if (!Orig.first)
	{
		std::cout << "The original list is empty.\n";
	}
	
	else
	{
		NodeType<elemType> *current = Orig.first;
		NodeType<elemType> *headA = listA.first;
		NodeType<elemType> *headB = listB.first;
		unsigned int currentIndex = 0;
		
		while (current)
		{
			if (currentIndex % 2 == 0)	// even index position
			{
				listA.insertLast(current->info);
			}
			else	// odd index position
			{
				listB.insertLast(current->info);
			}
			current = current->link;
			currentIndex++;
		}
	}
}

#endif /* UnorderedLinkedList_h */

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
	
	
//	void mergeLists(OrderedLinkedList<elemType> &list1, OrderedLinkedList<elemType> & list2);
	//This function creates a new list by merging the elements
	//of list1 and list2.
	//Postcondition: first points to the merged list; list1 and list2 are empty
	
	OrderedLinkedList<elemType> *mergeLists(OrderedLinkedList<elemType> &list1, OrderedLinkedList<elemType> &list2);
	// same as void mergeLists, but this method returns the head of the new list
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


//template <class elemType>
//void OrderedLinkedList<elemType>::mergeLists(OrderedLinkedList<elemType> &list1, OrderedLinkedList<elemType> &list2)
//{
//	NodeType<elemType> *current = NULL;
//	NodeType<elemType> *nodeL1 = list1.first;
//	NodeType<elemType> *nodeL2 = list2.first;
//	this->count = list1.count + list2.count;
//
//	if (list1.first == NULL) // list 1 is empty
//	{
//		this->first = list2.first;
//		list2.first = NULL;
//		this->count = list2.count;
//	}
//
//	else if (list2.first == NULL)	// list 2 is empty
//	{
//		this->first = list1.first;
//		list1.first = NULL;
//		this->count = list1.count;
//	}
//
//
//	// there is at least one non-empty list
//	else	// find the head node containing the smallest element
//	{
//		if (nodeL1->info <= nodeL2->info)
//		{
//			this->first = nodeL1;
//			nodeL1 = nodeL1->link;
//		}
//		else
//		{
//			this->first = nodeL2;
//			nodeL2 = nodeL2->link;
//		}
//	}
//	current = this->first;
//
//	while (nodeL1 != NULL && nodeL2 != NULL)
//	{
//		if (nodeL1->info <= nodeL2->info)
//		{
//			current->link = nodeL1;
//			current = current->link;
//			nodeL1 = nodeL1->link;
//		}
//		else
//		{
//			current->link = nodeL2;
//			current = current->link;
//			nodeL2 = nodeL2->link;
//		}
//	}
//
//	if (nodeL1 == NULL)	// list1 is exhausted first
//	{
//		current->link = nodeL2;
//	}
//
//	else	// list2 is exhausted first
//	{
//		current->link = nodeL1;
//	}
//	this->count = list1.count + list2.count;
//
//	// deallocate memory assigned to list1 and list2
//	list1.first = NULL;
//	list1.last = NULL;
//	list2.first = NULL;
//	list2.last = NULL;
//}


template <class elemType>
OrderedLinkedList<elemType> *OrderedLinkedList<elemType>::mergeLists(OrderedLinkedList<elemType> &list1, OrderedLinkedList<elemType> &list2)
{
	NodeType<elemType> *newHead = NULL;
	NodeType<elemType> *current = NULL;
	NodeType<elemType> *nodeL1 = list1.first;
	NodeType<elemType> *nodeL2 = list2.first;
	
	if (list1.isEmpty())
	{
		newHead = list2.first;
		list2.first = NULL;
	}
	
	else if (list2.isEmpty())
	{
		newHead = list1.first;
		list1.first = NULL;
	}
	
	else
	{
		// get the first node of the new list
		if (nodeL1->info <= nodeL2->info)
		{
			newHead = nodeL1;
			nodeL1 = nodeL1->link;
		}
		
		else
		{
			newHead = nodeL2;
			nodeL2 = nodeL2->link;
		}
		current = this->first;
	}
	
	while (nodeL1 && nodeL2)
	{
		if (nodeL1->info <= nodeL2->info)
		{
			current->link = nodeL1;
			current = current->link;
			nodeL1 = nodeL1->link;
		}
		
		else
		{
			current->link = nodeL2;
			current = current->link;
			nodeL2 = nodeL2->link;
		}
	}
	
	if (!nodeL1)	// list 1 exhausts first
	{
		current->link = nodeL2;
	}
	
	else	// list 2 exhausts first
	{
		current->link = nodeL1;
	}
	
	list1.first = NULL;
	list1.last = NULL;
	list2.first = NULL;
	list2.last = NULL;
	
	return newHead;
	// FIXME: build error when tyring to return newHead
}

#endif /* OrderedLinkedList_h */

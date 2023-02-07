#ifndef UnorderedLinkedList_h
#define UnorderedLinkedList_h

#include "NodeType.h"
#include "LinkedList.h"


template <class Type>
class UnorderedLinkedList : public LinkedListType<Type>
{
public:
	bool search(const Type& searchItem) const;	// returns true if item is in the list
	void insertFirst(const Type& newItem);		// insert node at beginning
	void insertLast(const Type& newItem);		// insert node at the end
	void deleteNode(const Type& deleteItem);	// delete a node from the list
	void buildListForward();
	void buildListBackward();
	
	
	// TODO: implement insertAfter
	// TODO: implement method to exchange two nodes
	void exchangeByIndex(const int first, const int second);
	void exchangeTwoFour();
	void deleteAll(const Type& deleteItem);
	
	void shareList(const UnorderedLinkedList<Type>& Orig, UnorderedLinkedList<Type>& listA, UnorderedLinkedList<Type>& listB);
	// Copies all elements in an even index position to listA
	// and all elements in an odd index position to listB
	
	void insertAfter(const Type existingValue, const Type newValue);
	// inserts a node with a given value after the occurrence
	// of a specified value in the list.
	
	void divideAt(LinkedListType<Type>& subList, int pos);
	// divides a given list into two sublists at a given position
	// all nodes from the given position are moved from the
	// list that calls this method to the subList passed as an argument
	
	
};

template <class Type>
bool UnorderedLinkedList<Type>::search(const Type& searchItem) const
{
	NodeType<Type> *current = this->first;
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


template <class Type>
void UnorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
	NodeType<Type> *newNode = new NodeType<Type>;
	newNode->info = newItem;
	newNode->link = this->first;	// Point the new node to the head
	this->first = newNode;			// Set the new node as the head
	this->count++;					// Increment the number of elements in the list
}


template <class Type>
void UnorderedLinkedList<Type>::insertLast(const Type& newItem)
{
	NodeType<Type> *newNode = new NodeType<Type>;
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


template <class Type>
void UnorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	NodeType<Type> *current = NULL;
	NodeType<Type> *trailCurrent = NULL;	// ptr before current ptr
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

template <class Type>
void UnorderedLinkedList<Type>::deleteAll(const Type& deleteItem)
{
	NodeType<Type> *current = NULL;
	NodeType<Type> *tempPtr = NULL;
	
	if (this->first == NULL)
	{
		std::cout << "Cannot delete from empty list.\n";
		return;
	}
	current = this->first;
	
	while (current)
	{
		if (current->info == deleteItem)
		{
			tempPtr = current->link;
			this->deleteNode(current->info);
			current = tempPtr;
		}
		else
		{
			current = current->link;
		}
	}
}

template <class Type>
void UnorderedLinkedList<Type>::buildListForward()
{
	// TODO: update buildListForward() to work with all types
	Type num {};
	std::cout << "Enter a list of elements ending with -999:" << std::endl;
	std::cin >> num;
	while (num != -999)
	{
		insertLast(num);
		std::cin >> num;
	}
}


template <class Type>
void UnorderedLinkedList<Type>::buildListBackward()
{
	// TODO: update buildListBackward() to work with all types
	Type num {};
	std::cout << "Enter a list of elements ending with -999:" << std::endl;
	std::cin >> num;
	while (num != -999)
	{
		insertFirst(num);
		std::cin >> num;
	}
}


template <class Type>
void UnorderedLinkedList<Type>::shareList(const UnorderedLinkedList<Type>& Orig, UnorderedLinkedList<Type>& listA, UnorderedLinkedList<Type>& listB)
{
	NodeType<Type> *current = Orig.first;
	unsigned int currentPosition = 0;
	
	// Case 1: The original list is empty
	if (!Orig.first)
	{
		std::cout << "The original list is empty.\n";
	}
	
	else
	{
		NodeType<Type> *current = Orig.first;
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


template <class Type>
void UnorderedLinkedList<Type>::insertAfter(const Type existingValue, const Type newValue)
{
	NodeType<Type> *current = this->first;
	NodeType<Type> *newNode = new NodeType<Type>(newValue);
	
	if (!this->first)	// if list is empty
	{
		this->first = newNode;
	}
	
	else
	{
		while (current)
		{
			if (current->info == existingValue)
			{
				newNode->link = current->link;
				current->link = newNode;
			}
			current = current->link;
		}
	}
}


template <class Type>
void UnorderedLinkedList<Type>::divideAt(LinkedListType<Type>& subList, int pos)
{
	unsigned int currentIndex = 0;
	NodeType<Type> *mainHead = this->first;	// original list head
	NodeType<Type> *current = mainHead;		// ptr to traverse original list
	NodeType<Type> *mainTail = NULL;		// last node of the original list
	NodeType<Type> *subListHead = NULL;		// sublist head
	NodeType<Type> *subListPtr = NULL;		// ptr to traverse sublist
	
	if (!this->first)	// the original list is empty
	{
		std::cout << "The original list is empty.\n";
	}
	
	else
	{
		while (current && pos >= 1)
		{
			if (currentIndex + 1 == pos)
			{
				subListHead = current->link;
				subListPtr = subListHead;
				mainTail = current;
			}
			
			if (subListPtr)
			{
				subList.insertLast(subListPtr->info);
				subListPtr = subListPtr->link;
			}
			
			current = current->link;
			currentIndex++;
		}
		mainTail->link = NULL;
	}
}


template <class Type>
void UnorderedLinkedList<Type>::exchangeByIndex(const int first, const int second)
{
	// FIXME: this is resulting in an endless cycle
	NodeType<Type> *head = this->first;	// ptr to the head of the linked list
	NodeType<Type> *current = head;	// ptr to traverse the list
	NodeType<Type> *n1prev = NULL;	// ptr to the node before first
	NodeType<Type> *n2prev = NULL;	// ptr to the node before second
	NodeType<Type> *n1 = NULL;
	NodeType<Type> *n2 = NULL;
	unsigned int currentPosition = 0;	// need to keep track of index for index-based node swap
	
	if (!head)
	{
		return;
	}
	
	// assign n1 and n2 pointers to their respective positions
	while (current->link)
	{
		// traverse the list and find the position for n1
		// index starts at zero and we want the node before the node at position
		// so we are looking for the position - 2
		if (currentPosition == first - 2)
		{
			n1prev = current;
			n1 = n1prev->link;	// keep track of n1
		}

		// traverse the list and find the position for n2
		if (currentPosition == second - 2)
		{
			n2prev = current;
			n2 = n2prev->link;	// keep track of n2
		}
		current = current->link;
		currentPosition++;
	}
	
	// swap n1 and n2
	n1prev->link = n2;
	n2->link = n1->link;
	n2->link->link->link->link = n1;
	n1->link = n2->link;

}


/// hardcoded examples for exchange(2,4)

// Method 1:
//template <class Type>
//void UnorderedLinkedList<Type>::exchangeTwoFour()
//{
//	NodeType<Type> *head = this->first;
//	NodeType<Type> *temp = head->link;
//	head->link = temp->link->link;
//	temp->link->link = NULL;
//	head->link->link = temp->link;
//	temp->link = NULL;
//	head->link->link->link = temp;
//}


// Method 2:
template <class Type>
void UnorderedLinkedList<Type>::exchangeTwoFour()
{
	NodeType<Type> *head = this->first;
	NodeType<Type> *temp = head->link;
	head->link = temp->link->link;
	head->link->link = temp->link;
	temp->link->link = temp;
	temp->link = NULL;
}

#endif /* UnorderedLinkedList_h */

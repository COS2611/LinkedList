#include <iostream>
#include "LinkedList.h"


/*
template <class elemType>
struct NodeType
{
	int info {NULL};
	NodeType<elemType> *link {NULL};	
};




template <class elemType>
void insertFirst(NodeType<elemType> *&head, int newValue)
{
	NodeType<elemType> *newNode = new NodeType<elemType>();
	newNode->info = newValue;
	
	// Point the new node to the head
	newNode->link = head;
	
	// Set the new node as the head
	head = newNode;
}

template <class elemType>
void insertLast(NodeType<elemType> **head, int newValue)
{
	// create a new node with newValue
	NodeType<elemType> *newNode = new NodeType<elemType>();
	newNode->info = newValue;
	newNode->link = NULL;
	
	if (*head == NULL) // if the list is empty
	{
		*head = newNode;
		return;
	}
	
	// find the last node
	NodeType<elemType> *lastNode = *head;
	while (lastNode->link != NULL)
	{
		lastNode = lastNode->link;
	}
	
	// insert the new node after the last node
	lastNode->link = newNode;
}

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
}


template <class elemType>
void deleteNode(NodeType<elemType> *head, NodeType<elemType> *theNode)
{
	NodeType<elemType> *p = head->link;
	NodeType<elemType> *q = theNode;
	p->link = q->link;
	delete q;
}


template <class elemType>
NodeType<elemType> *buildListForward()
{
	NodeType<elemType> *first {NULL}, *last {NULL}, *newNode {NULL};
	int num {NULL};
	
	std::cout << "Enter a list of integers ending with -999:" << std::endl;
	std::cin >> num;		// enter the first integer
	
	while (num != -999)
	{
		newNode = new NodeType<elemType>;
		newNode->info = num;
		newNode->link = NULL;
		
		if (first == NULL)	// if the list is empty
		{
			// insert the new node at the beginning
			first = newNode;
			last = newNode;
		}
		
		else	// the list is not empty
		{
			// insert the new node at then end
			last->link = newNode;
			last = newNode;
		}
		std::cin >> num;
	}
	return first;
}


template <class elemType>
NodeType<elemType> *buildListBackward()
{
	NodeType<elemType> *first {NULL}, *newNode {NULL};
	int num {NULL};
	
	std::cout << "Enter a list of integers ending with -999:" << std::endl;
	std::cin >> num;		// enter the first integer
	
	while (num != -999)
	{
		newNode = new NodeType<elemType>;
		newNode->info = num;
		newNode->link = first;
		first = newNode;
		std::cin >> num;
	}
	return first;
}
*/



int main()
{
	LinkedListType<int> myList;
	
	return 0;
}

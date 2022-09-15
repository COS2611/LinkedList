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
	myList.insertLast(2);
	myList.insertLast(15);
	myList.insertLast(8);
	myList.insertLast(24);
	myList.insertLast(34);
	myList.deleteNode(34);
	myList.print();
	
	
	return 0;
}

#include <iostream>
#include "LinkedList.h"


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



int main()
{
	LinkedListType<int> myList;
	
	myList.buildListForward();
	myList.print();
	
	// search the list for a user-entered number
	int number {};
	std::cout << "Enter a number to search for: ";
	std::cin >> number;
	if (myList.search(number))
		std::cout << number << " is in the list." << std::endl;
	else
		std::cout << number << " is not in the list." << std::endl;
	
	
	return 0;
}

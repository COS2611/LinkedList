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
	
	std::cout << std::endl;
	std::cout << "The original list: ";
	myList.print();
	
	// make a copy of myList using copy constructor
	LinkedListType<int> yourList {myList};
	std::cout << "\nSucessfully copied the list." << std::endl;
	std::cout << "\nYour list: ";
	yourList.print();
	std::cout << std::endl;
	
	
	// make a copy of the list using the copyList method
	LinkedListType<int> listCopy;
	listCopy.copyList(yourList);
	std::cout << "\nSucessfully copied the list." << std::endl;
	std::cout << "\nThe copied list: ";
	listCopy.print();
	std::cout << std::endl;
	
	return 0;
}

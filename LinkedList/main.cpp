#include <iostream>
#include "UnorderedLinkedList.h"


int main()
{	
	UnorderedLinkedList<std::string> myList;
	myList.buildListForward();
	std::cout << std::endl;
	std::cout << "The original list: ";
	myList.print();

	// make a copy of myList using copy constructor
	UnorderedLinkedList<std::string> yourList {myList};
	std::cout << "\nSucessfully copied the list." << std::endl;
	std::cout << "\nYour list: ";
	yourList.print();
	std::cout << std::endl;


	// make a copy of the list using the copyList method
	UnorderedLinkedList<std::string> listCopy;
	listCopy.copyList(yourList);
	std::cout << "\nSucessfully copied the list." << std::endl;
	std::cout << "\nThe copied list: ";
	listCopy.print();
	std::cout << std::endl;

	// make a copy of the list using the overloaded assignment operator
	// *Note the difference between initialization and assignment.
	UnorderedLinkedList<std::string> myNewList;
	myNewList = myList;	// assign myList to myNewList
	std::cout << "\nSucessfully copied the list." << std::endl;
	std::cout << "\nThe copied list: ";
	myNewList.print();
	std::cout << std::endl;


	// Test overloaded assignment operator with a linked list of strings
	UnorderedLinkedList<std::string> myShoppingList;
	myShoppingList.insertLast("beans");
	myShoppingList.insertLast("eggs");
	myShoppingList.insertLast("tomatoes");
	myShoppingList.insertLast("milk");
	std::cout << "My shopping list: ";
	myShoppingList.print();
	std::cout << std::endl;

	// create a new UnorderedLinkedList object and allocate memory on the heap
	UnorderedLinkedList<std::string> *yourShoppingList = new UnorderedLinkedList<std::string>;
	*yourShoppingList = myShoppingList;
	std::cout << "Your shopping list: ";
	yourShoppingList->print();
	std::cout << std::endl;
	
	
	
	return 0;
}

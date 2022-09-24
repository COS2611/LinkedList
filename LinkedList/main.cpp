#include <iostream>
#include <cstdlib>
#include "UnorderedLinkedList.h"
#include "OrderedLinkedList.h"


static void printList(const LinkedListType<int> &myNumbers)
{
	std::cout << "The list: ";
	myNumbers.print();
	std::cout << std::endl;
}


static void generateRandomList(OrderedLinkedList<int> &myNumbers)
{
	srand(static_cast<unsigned int>(time(0)));
	for (size_t i = 0; i < 20; i++)
	{
		myNumbers.insert(rand() % 1000);
	}
}

int main()
{
	OrderedLinkedList<int> myNumbers;
	int searchNum;
	generateRandomList(myNumbers);
	printList(myNumbers);
	
	
	// Search for an element
	std::cout << "Enter a number to search for: ";
	std::cin >> searchNum;
	if (myNumbers.search(searchNum))
	{
		std::cout << searchNum << " was found in the list." << std::endl;
	}
	else
	{
		std::cout << searchNum << " is not in the list." << std::endl;
	}
	
	
	// Insert an element
	int insertNum;
	std::cout << "Enter a number to insert: ";
	std::cin >> insertNum;
	myNumbers.insert(insertNum);
	
	// Print the list
	printList(myNumbers);
	
	// Delete an element
	int deleteNum;
	std::cout << "Enter a number to delete from the list: ";
	std::cin >> deleteNum;
	myNumbers.deleteNode(deleteNum);
	
	// Test insertFirst
	{
		int num;
		std::cout << "Enter a number to add to the beginning of the list: ";
		std::cin >> num;
		myNumbers.insertFirst(num);
		printList(myNumbers);
	}
	
	// Test insertLast
	{
		int num;
		std::cout << "Enter a number to add to the end of the list: ";
		std::cin >> num;
		myNumbers.insertLast(num);
		printList(myNumbers);
	}
	

	
// TODO: test buildListForward with std::string
//	UnorderedLinkedList<std::string> myList;
//	myList.buildListForward();
//	std::cout << std::endl;
//	std::cout << "The original list: ";
//	myList.print();

//	// make a copy of myList using copy constructor
//	UnorderedLinkedList<std::string> yourList {myList};
//	std::cout << "\nSucessfully copied the list." << std::endl;
//	std::cout << "\nYour list: ";
//	yourList.print();
//	std::cout << std::endl;

	return 0;
}

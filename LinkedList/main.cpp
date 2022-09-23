#include <iostream>
#include "UnorderedLinkedList.h"
#include "OrderedLinkedList.h"


int main()
{
	OrderedLinkedList<int> myNumbers;
	
	int searchNum;
	int numArray[10] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	for (auto num : numArray)
	{
		myNumbers.insert(numArray[num - 1]);
	}
	
	// Print the list
	std::cout << "The list: ";
	myNumbers.print();
	std::cout << std::endl;
	
	
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
	std::cout << "The list: ";
	myNumbers.print();
	std::cout << std::endl;
	

	
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

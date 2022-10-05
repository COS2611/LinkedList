#include <iostream>
#include "UnorderedLinkedList.h"
#include "OrderedLinkedList.h"


int main()
{
	//	evenOddIndexPartition(myList.first);	// FIXME: need access to head node
	
	UnorderedLinkedList<int> myList;
	UnorderedLinkedList<int> subList;
	
	myList.insertLast(34);
	myList.insertLast(65);
	myList.insertLast(27);
	myList.insertLast(89);
	myList.insertLast(12);
	
	/// Test insertAfter
	myList.print();
	std::cout << std::endl;
	
	/// test max()
	std::cout << "The largest element in the list is " << myList.max() << std::endl;
	
	/// test min()
	std::cout << "The smallest element in the list is " << myList.min() << std::endl;
	
	/// test divideAt
	std::cout << "Before dividing:\n";
	std::cout << "My list: ";
	myList.print();
	std::cout << std::endl;
	std::cout << "Sublist: ";
	subList.print();
	myList.divideAt(subList, 2);
	std::cout << std::endl;
	std::cout << "After dividing:\n";
	std::cout << "My list: ";
	myList.print();
	std::cout << std::endl;
	std::cout << "Sublist: ";
	subList.print();
	std::cout << std::endl;

	return 0;
}

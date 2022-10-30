#include <iostream>
#include "UnorderedLinkedList.h"
#include "OrderedLinkedList.h"


int main()
{
	/// Test Even-Odd partition based on index
//	evenOddIndexPartition(myList.first);	// FIXME: need access to head node

	UnorderedLinkedList<int> myList;
	UnorderedLinkedList<int> subList;
	UnorderedLinkedList<int> listA;
	UnorderedLinkedList<int> listB;

	myList.insertLast(34);
	myList.insertLast(65);
	myList.insertLast(27);
	myList.insertLast(89);
	myList.insertLast(12);

	/// Test insertAfter
	myList.insertAfter(65, 100);
	myList.insertAfter(1000, 222);
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


	/// Test shareLIst
	myList.initializeList();
	myList.insertLast(5);
	myList.insertLast(1);
	myList.insertLast(3);
	myList.insertLast(7);
	myList.insertLast(3);
	myList.shareList(myList, listA, listB);

	std::cout << "original list: ";
	myList.print();
	std::cout << std::endl;

	std::cout << "Even index elements: ";
	listA.print();
	std::cout << std::endl;

	std::cout << "Odd index elements: ";
	listB.print();
	std::cout << std::endl;
	
	
	return 0;
}

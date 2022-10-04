#include <iostream>
#include "UnorderedLinkedList.h"
#include "OrderedLinkedList.h"


int main()
{
	/// Test Even-Odd partition based on index
	UnorderedLinkedList<int> myList;
	UnorderedLinkedList<int> listA;
	UnorderedLinkedList<int> listB;
	
	myList.insertLast(5);
	myList.insertLast(1);
	myList.insertLast(3);
	myList.insertLast(7);
	myList.insertLast(3);
	
	
//	evenOddIndexPartition(myList.first);	// FIXME: need access to head node
	
	// Test shareLIst
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

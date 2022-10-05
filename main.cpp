#include <iostream>
#include "UnorderedLinkedList.h"
#include "OrderedLinkedList.h"


int main()
{
	//	evenOddIndexPartition(myList.first);	// FIXME: need access to head node
	
	UnorderedLinkedList<int> myList;
	
	/// Test insertAfter
	myList.insertLast(32);
	myList.insertLast(87);
	myList.insertAfter(32, 43);
	myList.insertLast(200);
	myList.print();
	std::cout << std::endl;
	
	/// test max()
	std::cout << "The largest element in the list is " << myList.max() << std::endl;
	
	/// test min()
	std::cout << "The smallest element in the list is " << myList.min() << std::endl;

	return 0;
}

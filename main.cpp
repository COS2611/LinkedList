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
	myList.print();
	

	return 0;
}

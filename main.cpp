#include <iostream>
#include <list>
#include "UnorderedLinkedList.h"
#include "OrderedLinkedList.h"
#include "LinkedListSTL.h"
#include "tests.cpp"


int main()
{
	test_deleteSmallest();
	test_deleteAll();
	test_deleteOc();
	test_shareList();
	return 0;
}

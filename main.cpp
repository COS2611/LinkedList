#include <iostream>
#include "UnorderedLinkedList.h"
#include "OrderedLinkedList.h"

static void test_deleteOc()
{
	OrderedLinkedList<int> list1;
	OrderedLinkedList<int> list2;
	
	// TODO: Write all test cases
	// Test case 1: both lists are empty
	// Test case 2: list1 is empty
	// Test case 3: list2 is empty
	// Test case 4: list1 contains one item
	// Test case 5: list2 contains one item
	// Test case 6: both lists contain one item
	
	// Test case 7: both lists contain multiple items
	{
		list1.insert(3);
		list1.insert(5);
		list1.insert(5);
		list1.insert(5);
		list1.insert(7);
		list1.insert(9);
		
		list2.insert(4);
		list2.insert(5);
		list2.insert(6);
		list2.insert(7);
		list2.insert(7);
		
		std::cout << "List 1 before deleteOc: ";
		list1.print();
		std::cout << std::endl;
		
		std::cout << "List 2: ";
		list2.print();
		std::cout << std::endl;
		
		deleteOc(list1, list2);
		
		std::cout << "List 1 after deleteOc: ";
		list1.print();
		std::cout << std::endl;
	}
}

int main()
{
	test_deleteOc();

	return 0;
}

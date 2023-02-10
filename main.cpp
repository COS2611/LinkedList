#include <iostream>
#include <list>
#include "UnorderedLinkedList.h"
#include "OrderedLinkedList.h"
#include "LinkedListSTL.h"

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

static void test_deleteOc_STL()
{
	std::list<int> list1 = {3,5,5,5,7,9};
	std::list<int> list2 = {4,5,6,7,7};
	
	std::cout << "List 1 before deleteOc: ";
	printList_STL(list1);
	
	std::cout << "List 2: ";
	printList_STL(list2);
	
	deleteOc_STL(list1, list2);
	std::cout << "List 1 after deleteOc: ";
	printList_STL(list1);
}

static void test_deleteAll()
{
	// Test 0: print output
	UnorderedLinkedList<int> myList;
	int deleteItem = 3;
	
	myList.insertLast(1);
	myList.insertLast(2);
	myList.insertLast(3);
	myList.insertLast(3);
	myList.insertLast(3);
	myList.insertLast(4);
	myList.insertLast(5);
	myList.insertLast(3);
	
	std::cout << "My list before deleteAll: ";
	myList.print();
	std::cout << std::endl;
	
	std::cout << "Item to be deleted: " << deleteItem << "\n";
	myList.deleteAll(deleteItem);
	
	std::cout << "My list after deleteAll: ";
	myList.print();
	std::cout << std::endl;
	
	assert(myList.length() == 4);
	assert(myList.search(1) == true);
	assert(myList.search(2) == true);
	assert(myList.search(3) == false);
	assert(myList.search(4) == true);
	assert(myList.search(5) == true);
	
	
	// Test 1: Empty list, delete value that doesn't exist
	UnorderedLinkedList<int> list1;
	list1.deleteAll(5);
	assert(list1.isEmpty() == true);

	// Test 2: Non-empty list, delete value that doesn't exist
	UnorderedLinkedList<int> list2;
	list2.insertLast(1);
	list2.insertLast(2);
	list2.insertLast(3);
	list2.deleteAll(5);
	assert(list2.length() == 3);
	assert(list2.search(1) == true);
	assert(list2.search(2) == true);
	assert(list2.search(3) == true);

	// Test 3: Non-empty list, delete value that exists
	UnorderedLinkedList<int> list3;
	list3.insertLast(1);
	list3.insertLast(2);
	list3.insertLast(3);
	list3.deleteAll(2);
	assert(list3.length() == 2);
	assert(list3.search(1) == true);
	assert(list3.search(3) == true);

	// Test 4: Non-empty list, delete multiple occurrences of value
	UnorderedLinkedList<int> list4;
	list4.insertLast(1);
	list4.insertLast(2);
	list4.insertLast(2);
	list4.insertLast(3);
	list4.deleteAll(2);
	assert(list4.length() == 2);
	assert(list4.search(1) == true);
	assert(list4.search(3) == true);

	// Test 5: Empty list, delete all  elements
	UnorderedLinkedList<int> list5;
	list5.deleteAll(5);
	assert(list5.isEmpty() == true);

	// Test 6: Non-empty list, delete all elements in list with one node
	UnorderedLinkedList<int> list6;
	list6.insertFirst(5);
	list6.deleteAll(5);
	assert(list6.isEmpty() == true);

	// Test 7: Non-empty list, delete all elements in list with multiple nodes
	UnorderedLinkedList<int> list7;
	list7.insertFirst(5);
	list7.deleteAll(5);
	assert(list7.isEmpty() == true);

	// Test 8: delete only some elements with mutiple nodes
	UnorderedLinkedList<int> list8;
	list8.insertFirst(5);
	list8.insertFirst(4);
	list8.insertFirst(5);
	list8.deleteAll(5);
	assert(list8.length() == 1);
	assert(list8.front() == 4);

	// Test 9: delete element in list with elements of multiple values
	UnorderedLinkedList<int> list9;
	list9.insertFirst(1);
	list9.insertFirst(2);
	list9.insertFirst(3);
	list9.deleteAll(2);
	assert(list9.length() == 2);
	assert(list9.front() == 3);
	if (list9.last != NULL) { assert(list9.back() == 1); }
}

static void test_deleteSmallest()
{
	// Test case 1: The list is empty
	UnorderedLinkedList<int> list1;
	list1.deleteSmallest();
	assert(list1.count == 0);
	std::cout << "Test case 1 passed!\n";
	
	// Test case 2: The list contains only one node
	UnorderedLinkedList<int> list2;
	list2.insertLast(1);
	list2.deleteSmallest();
	assert(list2.count == 0);
	assert(list2.search(1) == false);
	std::cout << "Test case 2 passed!\n";
	
	// Test case 3: List has more than one node and smallest element is in the first node
	UnorderedLinkedList<int> list3;
	list3.insertLast(1);
	list3.insertLast(100);
	list3.deleteSmallest();
	assert(list3.count == 1);
	assert(list3.search(1) == false);
	assert(list3.search(100) == true);
	std::cout << "Test case 3 passed!\n";
	
	// Test case 4: List has more than one node and smallest element is somewhere in the middle
	UnorderedLinkedList<int> list4;
	list4.insertLast(14);
	list4.insertLast(100);
	list4.insertLast(51);
	list4.insertLast(10);
	list4.insertLast(6);
	list4.insertLast(134);
	list4.insertLast(299);
	list4.deleteSmallest();
	assert(list4.count == 6);
	assert(list4.search(14) == true);
	assert(list4.search(100) == true);
	assert(list4.search(51) == true);
	assert(list4.search(10) == true);
	assert(list4.search(6) == false);
	assert(list4.search(134) == true);
	assert(list4.search(299) == true);
	std::cout << "Test case 4 passed!\n";
	
	// Test case 5: List has more than one node and smallest element is in the last node
	UnorderedLinkedList<int> list5;
	list5.insertLast(5);
	list5.insertLast(4);
	list5.insertLast(3);
	list5.insertLast(2);
	list5.insertLast(1);
	list5.deleteSmallest();
	assert(list5.count == 4);
	assert(list5.search(5) == true);
	assert(list5.search(4) == true);
	assert(list5.search(3) == true);
	assert(list5.search(2) == true);
	assert(list5.search(1) == false);
	std::cout << "Test case 5 passed!\n";
}

int main()
{
	test_deleteSmallest();
	return 0;
}

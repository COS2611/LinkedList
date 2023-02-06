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
	myList.insertLast(1);
	myList.insertLast(2);
	myList.insertLast(3);
	myList.insertLast(3);
	myList.insertLast(3);
	myList.insertLast(4);
	myList.insertLast(5);
	myList.insertLast(3);
	
	std::cout << "\nMy list before deleteAll: ";
	myList.print();
	
	myList.deleteAll(3);
	std::cout << "\nMy list after deleteAll: ";
	myList.print();
	
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


int main()
{
//	std::cout << "\ndeleteOc using Malik OrderedLinkedList:\n";
//	std::cout << "---------------------------------------\n";
//	test_deleteOc();
//
//	std::cout << "\ndeleteOc using STL Linked List:\n";
//	std::cout << "-------------------------------\n";
//	test_deleteOc_STL();
	
	test_deleteAll();
	
	return 0;
}

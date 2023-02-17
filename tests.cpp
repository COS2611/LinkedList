//
//  tests.cpp
//  LinkedList
//
//  Created by Mitch Campbell on 2023/02/10.
//

#pragma once
#include <iostream>
#include <list>
#include "OrderedLinkedList.h"
#include "UnorderedLinkedList.h"
#include "LinkedListSTL.h"

static void test_deleteOc()
{
	// Test case 1: both lists are empty
	{
		OrderedLinkedList<int> list1;
		OrderedLinkedList<int> list2;
		deleteOc(list1, list2);
		assert(list1.first == NULL);
		assert(list1.last == NULL);
		assert(list1.count == 0);
		assert(list2.first == NULL);
		assert(list2.last == NULL);
		assert(list2.count == 0);
//		std::cout << "Test case 1 passed!\n";
	}
	
	// Test case 2: list1 is empty
	{
		OrderedLinkedList<int> list1;
		OrderedLinkedList<int> list2;
		list2.insert(2);
		deleteOc(list1, list2);
		assert(list1.first == NULL);
		assert(list1.last == NULL);
		assert(list1.count == 0);
		assert(list2.first != NULL);
		assert(list2.last != NULL);
		assert(list2.count > 0);
//		std::cout << "Test case 2 passed!\n";
	}
	
	// Test case 3: list2 is empty
	{
		OrderedLinkedList<int> list1;
		OrderedLinkedList<int> list2;
		list1.insert(133);
		deleteOc(list1, list2);
		assert(list1.first != NULL);
		assert(list1.last != NULL);
		assert(list2.first == NULL);
		assert(list2.last == NULL);
		assert(list1.count > 0);
		assert(list2.count == 0);
//		std::cout << "Test case 3 passed!\n";
	}
	
	// Test case 4: list1 contains one item
	{
		OrderedLinkedList<int> list1;
		OrderedLinkedList<int> list2;
		list1.insert(5);
		deleteOc(list1, list2);
		assert(list1.first != NULL);
		assert(list1.last != NULL);
		assert(list1.count == 1);
		assert(list2.first == NULL);
		assert(list2.last == NULL);
		assert(list2.count == 0);
//		std::cout << "Test case 4 passed!\n";
	}

	// Test case 5: list2 contains one item
	{
		OrderedLinkedList<int> list1;
		OrderedLinkedList<int> list2;
		list2.insert(7);
		deleteOc(list1, list2);
		assert(list1.first == NULL);
		assert(list1.last == NULL);
		assert(list1.count == 0);
		assert(list2.first != NULL);
		assert(list2.last != NULL);
		assert(list2.count == 1);
//		std::cout << "Test case 5 passed!\n";
	}

	// Test case 6: both lists contain one item
	{
		OrderedLinkedList<int> list1;
		OrderedLinkedList<int> list2;
		list1.insert(5);
		list2.insert(5);
		deleteOc(list1, list2);
		assert(list1.first == NULL);
		assert(list1.last == NULL);
		assert(list1.count == 0);
		assert(list2.first != NULL);
		assert(list2.last != NULL);
		assert(list2.count == 1);
//		std::cout << "Test case 6 passed!\n";
	}

	// Test case 7: both lists contain multiple items
	{
		OrderedLinkedList<int> list1;
		OrderedLinkedList<int> list2;
		list1.insert(5);
		list1.insert(7);
		list2.insert(2);
		list2.insert(7);
		deleteOc(list1, list2);
		assert(list1.first != NULL);
		assert(list1.last != NULL);
		assert(list1.count == 1);
		assert(list2.first != NULL);
		assert(list2.last != NULL);
		assert(list2.count == 2);
//		std::cout << "Test case 7 passed!\n";
	}

	// Test case 8: list1 contains duplicates
	{
		OrderedLinkedList<int> list1;
		OrderedLinkedList<int> list2;
		list1.insert(1);
		list1.insert(2);
		list1.insert(3);
		list1.insert(2);
		list1.insert(4);
		list2.insert(3);
		list2.insert(4);
		deleteOc(list1, list2);
		assert(list1.count == 3);
		assert(list1.first->info == 1);
		assert(list1.last->info == 2);
		assert(list2.count == 2);
		assert(list2.first->info == 3);
		assert(list2.last->info == 4);
//		std::cout << "Test case 8 passed!\n";
	}

	// Test case 9: list2 contains duplicates
	{
		OrderedLinkedList<int> list1;
		OrderedLinkedList<int> list2;
		list1.insert(1);
		list1.insert(2);
		list1.insert(3);
		list2.insert(3);
		list2.insert(4);
		list2.insert(4);
		deleteOc(list1, list2);
		assert(list1.count == 2);
		assert(list1.first->info == 1);
		assert(list1.last->info == 2);
		assert(list2.count == 3);
		assert(list2.first->info == 3);
		assert(list2.last->info == 4);
//		std::cout << "Test case 9 passed!\n";
	}

	// Test case 10: both lists contain duplicates
	{
		OrderedLinkedList<int> list1;
		OrderedLinkedList<int> list2;
		list1.insert(1);
		list1.insert(2);
		list1.insert(3);
		list1.insert(2);
		list2.insert(3);
		list2.insert(4);
		list2.insert(3);
		deleteOc(list1, list2);
		assert(list1.count == 3);
		assert(list1.first->info == 1);
		assert(list1.last->info == 2);
		assert(list2.count == 3);
		assert(list2.first->info == 3);
		assert(list2.last->info == 4);
//		std::cout << "Test case 10 passed!\n";
	}
	
	// Test case 11: both lists contain items that are in the same order
	{
		OrderedLinkedList<int> list1;
		OrderedLinkedList<int> list2;
		list1.insert(1);
		list1.insert(2);
		list1.insert(3);
		list2.insert(1);
		list2.insert(2);
		list2.insert(3);
		deleteOc(list1, list2);
		assert(list1.first == NULL);
		assert(list1.last == NULL);
		assert(list1.count == 0);
		assert(list2.first != NULL);
		assert(list2.last != NULL);
		assert(list2.count == 3);
//		std::cout << "Test case 11 passed!\n";
	}

	// Test case 12: both lists contain items that are in different order
	{
		OrderedLinkedList<int> list1;
		OrderedLinkedList<int> list2;
		list1.insert(1);
		list1.insert(2);
		list1.insert(3);
		list2.insert(3);
		list2.insert(2);
		list2.insert(1);
		deleteOc(list1, list2);
		assert(list1.first == NULL);
		assert(list1.last == NULL);
		assert(list1.count == 0);
		assert(list2.first != NULL);
		assert(list2.last != NULL);
		assert(list2.count == 3);
//		std::cout << "Test case 12 passed!\n";
	}

	// Test case 13: items in list2 are all unique
	{
		OrderedLinkedList<int> list1;
		OrderedLinkedList<int> list2;
		list1.insert(1);
		list1.insert(2);
		list1.insert(3);
		list2.insert(4);
		list2.insert(5);
		list2.insert(6);
		deleteOc(list1, list2);
		assert(list1.first != NULL);
		assert(list1.last != NULL);
		assert(list1.count == 3);
		assert(list2.first != NULL);
		assert(list2.last != NULL);
		assert(list2.count == 3);
//		std::cout << "Test case 13 passed!\n";
	}
	
	// Test case 14: both lists contain items that are only in one list
	{
		OrderedLinkedList<int> list1;
		OrderedLinkedList<int> list2;
		list1.insert(2);
		list1.insert(4);
		list1.insert(6);
		list1.insert(8);
		list2.insert(1);
		list2.insert(3);
		list2.insert(5);
		list2.insert(7);
		deleteOc(list1, list2);
		assert(list1.first != NULL);
		assert(list1.last != NULL);
		assert(list1.count == 4);
		assert(list2.first != NULL);
		assert(list2.last != NULL);
		assert(list2.count == 4);
//		std::cout << "Test case 14 passed!\n";
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
	
	// Test 10: delete first element
	UnorderedLinkedList<int> list10;
	list10.insertLast(10);
	list10.insertLast(20);
	list10.insertLast(30);
	list10.deleteAll(10);
	assert(list10.length() == 2);
	assert(list10.front() == 20);
	
	// Test 11: delete last element
	UnorderedLinkedList<int> list11;
	list11.insertLast(10);
	list11.insertLast(20);
	list11.insertLast(30);
	list11.deleteAll(30);
	assert(list11.length() == 2);
	assert(list11.front() == 10);
}


static void test_shareList()
{
	// Test case 0: COS2611-06-2020-Q2
	UnorderedLinkedList<int> originalList;
	UnorderedLinkedList<int> listA;
	UnorderedLinkedList<int> listB;
	originalList.insertLast(0);
	originalList.insertLast(1);
	originalList.insertLast(2);
	originalList.insertLast(3);
	originalList.insertLast(4);
	originalList.insertLast(5);
	originalList.shareList(originalList, listA, listB);
	std::cout << "Original list: ";
	printList(originalList);
	std::cout << "List A: ";
	printList(listA);
	std::cout << "List B: ";
	printList(listB);
	
	// Test case 1: empty original list
	UnorderedLinkedList<int> emptyList;
	UnorderedLinkedList<int> evenList, oddList;
	emptyList.shareList(emptyList, evenList, oddList);
	assert(evenList.isEmpty());
	assert(oddList.isEmpty());
	
	// Test case 2: original list with one element
	UnorderedLinkedList<int> oneElementList;
	oneElementList.insertLast(1);
	UnorderedLinkedList<int> oneEvenList, oneOddList;
	oneElementList.shareList(oneElementList, oneEvenList, oneOddList);
	assert(oneEvenList.count == 1 && oneEvenList.search(1));
	assert(oneOddList.isEmpty());
	
	// Test case 3: original list with two elements
	UnorderedLinkedList<int> twoElementList;
	twoElementList.insertLast(2);
	twoElementList.insertLast(4);
	UnorderedLinkedList<int> twoEvenList, twoOddList;
	twoElementList.shareList(twoElementList, twoEvenList, twoOddList);
	assert(twoEvenList.count == 1 && twoEvenList.search(2));
	assert(twoOddList.count == 1 && twoOddList.search(4));
	
	// Test case 4: original list with multiple elements
	UnorderedLinkedList<int> multipleElementList;
	multipleElementList.insertLast(2);
	multipleElementList.insertLast(4);
	multipleElementList.insertLast(6);
	multipleElementList.insertLast(8);
	multipleElementList.insertLast(10);
	UnorderedLinkedList<int> multipleEvenList, multipleOddList;
	multipleElementList.shareList(multipleElementList, multipleEvenList, multipleOddList);
	assert(multipleEvenList.count == 3 && multipleEvenList.search(2) && multipleEvenList.search(6) && multipleEvenList.search(10));
	assert(multipleOddList.count == 2 && multipleOddList.search(4) && multipleOddList.search(8));
	
}


static void test_occurrenceCounter()
{
	// Test case 1: The given value is not in the linked list
	{
		UnorderedLinkedList<int> list;
		list.insertLast(1);
		list.insertLast(2);
		list.insertLast(3);
		list.insertLast(4);
		int occur = 5;
		int count = list.occurrenceCounter(list, occur);
		assert(count == 0);
	}
	
	// Test case 2: The given value appears multiple times in the linked list
	{
		UnorderedLinkedList<int> list;
		list.insertLast(1);
		list.insertLast(2);
		list.insertLast(2);
		list.insertLast(3);
		list.insertLast(2);
		int occur = 2;
		int count = list.occurrenceCounter(list, occur);
		assert(count == 3);
	}
	
	// Test case 3: The given value appears only once in the linked list
	{
		UnorderedLinkedList<int> list;
		list.insertLast(1);
		list.insertLast(2);
		list.insertLast(3);
		int occur = 2;
		int count = list.occurrenceCounter(list, occur);
		assert(count == 1);
	}
	
	// Test case 4: The linked list is empty
	{
		UnorderedLinkedList<int> list;
		int occur = 1;
		int count = list.occurrenceCounter(list, occur);
		assert(count == 0);
	}
	
	// Test case 5: The given value is the only value in the linked list
	{
		UnorderedLinkedList<int> list;
		list.insertLast(5);
		int occur = 5;
		int count = list.occurrenceCounter(list, occur);
		assert(count == 1);
	}
}


static void test_deleteSmallest()
{
	// Test case 1: The list is empty
	{
		UnorderedLinkedList<int> list;
		list.deleteSmallest();
		assert(list.isEmpty());  // list should remain empty
	}
	
	// Test case 2: The list contains only one element
	{
		UnorderedLinkedList<int> list;
		list.insertFirst(42);
		list.deleteSmallest();
		assert(list.isEmpty());  // list should become empty
	}
	
	// Test case 3: The list contains multiple elements, but only one occurrence of the smallest element
	{
		UnorderedLinkedList<int> list;
		list.insertFirst(42);
		list.insertFirst(10);
		list.insertFirst(20);
		list.deleteSmallest();
		assert(!list.isEmpty());  // list should not be empty
		assert(list.length() == 2);  // list should have length 2
		assert(list.search(10) == false);  // the first node with value 10 should have been deleted
	}
	
	// Test case 4: The list contains multiple occurrences of the smallest element
	{
		UnorderedLinkedList<int> list;
		list.insertFirst(42);
		list.insertFirst(10);
		list.insertFirst(20);
		list.insertFirst(10);
		list.insertFirst(30);
		list.deleteSmallest();
		assert(!list.isEmpty());  // list should not be empty
		assert(list.length() == 4);  // list should have length 4
	}
	
	// Test case 5: The smallest element appears at the beginning of the list
	{
		UnorderedLinkedList<int> list;
		list.insertFirst(10);
		list.insertFirst(20);
		list.insertFirst(30);
		list.deleteSmallest();
		assert(!list.isEmpty());  // list should not be empty
		assert(list.length() == 2);  // list should have length 2
		assert(list.search(10) == false);  // the first node with value 10 should have been deleted
	}
	
	// Test case 6: The smallest element appears at the end of the list
	{
		UnorderedLinkedList<int> list;
		list.insertFirst(30);
		list.insertFirst(20);
		list.insertFirst(10);
		list.deleteSmallest();
		assert(!list.isEmpty());  // list should not be empty
		assert(list.length() == 2);  // list should have length 2
		assert(list.search(10) == false);  // the last node with value 10 should have been deleted
	}
}

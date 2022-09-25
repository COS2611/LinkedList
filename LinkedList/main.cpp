#include <iostream>
#include <cstdlib>
#include "UnorderedLinkedList.h"
#include "OrderedLinkedList.h"


static void generateRandomList(OrderedLinkedList<int> &list)
{
	srand(static_cast<unsigned int>(time(0)));
	for (size_t i = 0; i < 10; i++)
	{
		list.insert(rand() % 50);
	}
}


int main()
{
	OrderedLinkedList<int> list1;
	OrderedLinkedList<int> list2;
	
	generateRandomList(list1);
	std::cout << "List1: ";
	list1.print();
	std::cout << std::endl;
	
	list2.insert(6);
	list2.insert(108);
	list2.insert(64);
	list2.insert(17);
	list2.insert(-41);
	std::cout << "List2: ";
	list2.print();
	std::cout << std::endl;
	
	
	// Test mergeLists
	OrderedLinkedList<int> newList;
	newList.mergeLists(list1, list2);
	std::cout << "The merged list: ";
	newList.print();
	std::cout << std::endl;


	return 0;
}

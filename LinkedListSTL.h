//
//  LinkedListSTL.h
//  LinkedList
//
//  Created by Mitch Campbell on 2023/01/30.
//

#ifndef LinkedListSTL_h
#define LinkedListSTL_h

#include <list>

template <class Type>
void deleteOc_STL(std::list<Type>& L1, const std::list<Type>& L2)
{
	auto it1 = L1.begin();
	auto it2 = L2.begin();
	
	while (it1 != L1.end() && it2 != L2.end())
	{
		if (*it1 < *it2)
		{
			it1++;
		}
		else if (*it2 < *it1)
		{
			it2++;
		}
		else
		{
			it1 = L1.erase(it1);
		}
	}
}


template <class Type>
static void printList_STL(const std::list<Type> &list)
{
	for (const auto element : list)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;
}


#endif /* LinkedListSTL_h */

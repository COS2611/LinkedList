#ifndef LinkedList_h
#define LinkedList_h

template <class elemType>
struct NodeType
{
	int info;
	NodeType<elemType> *link;
};


template <class elemType>
class LinkedListType
{
public:
	LinkedListType();			// default constructor
	~LinkedListType();			// destructor
	void initializeList();		// initialize list as empty list
	void destroyList();			// deallocate memory
	void print() const;			// print the list
	bool isEmpty() const;		// returns true if list is empty
	int length() const;			// returns the number of nodes in the list
	elemType front() const;		// returns the first node's info
	elemType back() const;		// returns the last node's info
	void insertFirst(const elemType& newItem);	// insert node at beginning
	void insertLast(const elemType& newItem);	// insert node at the end
	void deleteNode(const elemType& deleteItem);	// delete a node from the list
	void buildListForward();
	void buildListBackward();
	bool search(const elemType& searchItem);	// returns true if item is in the list

	
	
protected:
	int count;					// number of elements in the list
	NodeType<elemType> *first;	// pointer to head node
	NodeType<elemType> *last;	// pointer to tail node
};


template <class elemType>
LinkedListType<elemType>::LinkedListType()
	: first (NULL), last (NULL), count (0) {}


template <class elemType>
void LinkedListType<elemType>::destroyList()
{
	NodeType<elemType> *temp;	// pointer to traverse list
	
	while (first != NULL)
	{
		temp = first;
		first = first->link;
		delete temp;
	}
	last = NULL;
	count = 0;
}


template <class elemType>
void LinkedListType<elemType>::initializeList()
{
	destroyList();
}


template <class elemType>
LinkedListType<elemType>::~LinkedListType()
{
	destroyList();
}


template <class elemType>
void LinkedListType<elemType>::print() const
{
	NodeType<elemType> *current {first};
	while (current != NULL)
	{
		std::cout << current->info << std::endl;
		current = current->link;
	}
}


template <class elemType>
bool LinkedListType<elemType>::isEmpty() const
{
	return first == NULL;
}


template <class elemType>
int LinkedListType<elemType>::length() const
{
	return count;
}


template <class elemType>
elemType LinkedListType<elemType>::front() const
{
	assert(first != NULL);
	return first->info;
}


template <class elemType>
elemType LinkedListType<elemType>::back() const
{
	assert(last != NULL);
	return last->info;
}


template <class elemType>
void LinkedListType<elemType>::insertFirst(const elemType& newItem)
{
	NodeType<elemType> *newNode = new NodeType<elemType>;
	newNode->info = newItem;
	newNode->link = first;	// Point the new node to the head
	first = newNode;		// Set the new node as the head
	count++;				// Increment the number of elements in the list
}


template <class elemType>
void LinkedListType<elemType>::insertLast(const elemType& newItem)
{
	NodeType<elemType> *newNode = new NodeType<elemType>;
	newNode->info = newItem;
	newNode->link = NULL;
	
	if (first == NULL) // if the list is empty
	{
		first = newNode;
		last = newNode;
	}
	
	else
	{
		last->link = newNode; 	// insert newNode after last
		last = newNode;			// point last to newNode
	}
	count++;
}


template <class elemType>
void LinkedListType<elemType>::deleteNode(const elemType& deleteItem)
{
	NodeType<elemType> *current;
	NodeType<elemType> *trailCurrent;	// ptr before current ptr
	bool found = false;
	
	if (first == NULL)	// the list is empty
	{
		std::cout << "Cannot delete from an empty list." << std::endl;
	}
	
	else
	{
		if (first->info == deleteItem)	// the first node is to be deleted
		{
			current = first;
			first = first->link;	// point first to the next node
			
			if (first == NULL)	// the list has only one node
			{
				last = NULL;
			}
			delete current;
			count--;
		}
		
		else	// continue searching list
		{
			trailCurrent = first;
			current = first->link;	// move to the next node
			
			while (current != NULL && !found)	// continue searching
			{
				if (current->info != deleteItem)
				{
					trailCurrent = current;
					current = current->link;
				}
				
				else
				{
					found = true;
				}
				
				if (found)	// if found, delete node
				{
					trailCurrent->link = current->link;
					count--;
					
					if (last == current)
					{
						last = trailCurrent;
					}
					delete current;
				}
			}
			if (!found)
			{
				std::cout << "The item to be deleted is not in the list." << std::endl;
			}
		}
	}
}



template <class elemType>
void LinkedListType<elemType>::buildListForward()
{
	elemType num {};
	std::cout << "Enter a list of integers ending with -999:" << std::endl;
	std::cin >> num;
	while (num != -999)
	{
		insertLast(num);
		std::cin >> num;
	}
}


template <class elemType>
void LinkedListType<elemType>::buildListBackward()
{
	elemType num {};
	std::cout << "Enter a list of integers ending with -999:" << std::endl;
	std::cin >> num;
	while (num != -999)
	{
		insertFirst(num);
		std::cin >> num;
	}
}


template <class elemType>
bool LinkedListType<elemType>::search(const elemType& searchItem)
{
	NodeType<elemType> *current = first;
	bool found = false;
	
	while (current != NULL && !found)
	{
		if (current->info == searchItem)
		{
			found = true;
		}
		else
		{
			current = current->link;
		}
	}
	return found;
}

#endif /* LinkedList_h */

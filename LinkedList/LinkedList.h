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
	LinkedListType();		// default constructor
	~LinkedListType();		// destructor
	void initializeList();	// initialize list as empty list
	void destroyList();		// deallocate memory
	void print() const;		// print the list
	bool isEmpty() const;	// returns true if list is empty
	int length() const;		// returns the number of nodes in the list
	elemType front() const;	// returns the first node's info
	elemType back() const;	// returns the last node's info
	
	
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
	NodeType<elemType> *current;
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


#endif /* LinkedList_h */

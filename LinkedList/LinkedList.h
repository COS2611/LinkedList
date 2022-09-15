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



#endif /* LinkedList_h */

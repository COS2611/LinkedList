#include <iostream>


struct Node
{
	int info {NULL};	// default: initialize to NULL
	Node *link {NULL};	// default: initialize to NULL
};


void printList(Node *start)
{
	while (start != NULL)
	{
		std::cout << start->info << std::endl;
		start = start->link;
	}
	return;
}


void insertFirst(Node *&head, int newValue)
{
	Node *newNode = new Node();
	newNode->info = newValue;
	
	// Point the new node to the head
	newNode->link = head;
	
	// Set the new node as the head
	head = newNode;
}


void insertLast(Node **head, int newValue)
{
	// create a new node with newValue
	Node *newNode = new Node();
	newNode->info = newValue;
	newNode->link = NULL;
	
	if (*head == NULL) // if the list is empty
	{
		*head = newNode;
		return;
	}
	
	// find the last node
	Node *lastNode = *head;
	while (lastNode->link != NULL)
	{
		lastNode = lastNode->link;
	}
	
	// insert the new node after the last node
	lastNode->link = newNode;
}


void insertAfter(Node *previous, int newValue)
{
	// check if the previous node is NULL
	if (previous == NULL)
	{
		std::cout << "Previous cannot be NULL" << std::endl;
		return;
	}
	
	// create a new node
	Node *newNode = new Node();
	newNode->info = newValue;
	
	// insert the new node after the previous node
	newNode->link = previous->link;
	previous->link = newNode;
}


void deleteNode(Node *head, Node *theNode)
{
	Node *p = head->link;
	Node *q = theNode;
	p->link = q->link;
	delete q;
}


int main()
{
	// building a linked list (forward)
	Node *first {NULL}, *last {NULL}, *newNode {NULL};
	int num {NULL};
	
	std::cin >> num;		// user enters an integer
	newNode = new Node;		// allocate memory on the heap
	
	// build first node
	newNode->info = num;
	newNode->link = NULL;	
	
	return 0;
}

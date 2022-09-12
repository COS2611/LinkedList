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


Node *buildListForward()
{
	Node *first {NULL}, *last {NULL}, *newNode {NULL};
	int num {NULL};
	
	std::cout << "Enter a list of integers ending with -999:" << std::endl;
	std::cin >> num;		// enter the first integer
	
	while (num != -999)
	{
		newNode = new Node;
		newNode->info = num;
		newNode->link = NULL;
		
		if (first == NULL)	// if the list is empty
		{
			// insert the new node at the beginning
			first = newNode;
			last = newNode;
		}
		
		else	// the list is not empty
		{
			// insert the new node at then end
			last->link = newNode;
			last = newNode;
		}
		std::cin >> num;
	}
	return first;
}


Node *buildListBackward()
{
	Node *first {NULL}, *newNode {NULL};
	int num {NULL};
	
	std::cout << "Enter a list of integers ending with -999:" << std::endl;
	std::cin >> num;		// enter the first integer
	
	while (num != -999)
	{
		newNode = new Node;
		newNode->info = num;
		newNode->link = first;
		first = newNode;
		std::cin >> num;
	}
	return first;
}


int main()
{
	// building a list backwards
	Node *first = buildListBackward();
	
	std::cout << "\nThe linked list:" << std::endl;
	printList(first);
	
	return 0;
}

#include <iostream>


struct Node
{
	int data;
	Node *link;
};


void printList(Node *start)
{
	while (start != NULL)
	{
		std::cout << start->data << std::endl;
		start = start->link;
	}
	return;
}


void insertFirst(Node *&head, int newValue)
{
	Node *newNode = new Node();
	newNode->data = newValue;
	
	// Point the new node to the head
	newNode->link = head;
	
	// Set the new node as the head
	head = newNode;
}


void insertLast(Node **head, int newValue)
{
	// create a new node with newValue
	Node *newNode = new Node();
	newNode->data = newValue;
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
	newNode->data = newValue;
	
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
	Node *head = new Node();
	Node *second = new Node();
	Node *third = new Node();
	Node *fourth = new Node();
	
	head->data = 45;
	head->link = second;
	second->data = 65;
	second->link = third;
	third->data = 34;
	third->link = fourth;
	fourth->data = 76;
	fourth->link = NULL;
	
	// print the linked list
	std::cout << "Original linked list:\n";
	printList(head);
	
	// insert a node at the beginning of the list and print the list
//	insertFirst(head, 99);
//	std::cout << "Linked list after adding node at the beginning:\n";
//	printList(head);
	
	// insert a node at the end of the linked list
//	insertLast(&head, 50);
//	std::cout << "\nLinked list after adding node at the end:\n";
//	printList(head);
	
	// insert a node at a specified location
//	insertAfter(head->link, 50);
//	std::cout << "The linked list after inserting the new node:\n";
//	printList(head);
	
	// delete a node
	deleteNode(head, head->link->link);
	
	std::cout << "Linked list after deleting the node:\n";
	printList(head);
	
	
	return 0;
}

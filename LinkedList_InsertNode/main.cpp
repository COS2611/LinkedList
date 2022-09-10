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


void insertFirst(Node *&head)
{
	Node *newNode = new Node();
	newNode->data = 99;
	
	// Point the new node to the head
	newNode->link = head;
	
	// Set the new node as the head
	head = newNode;
}


int main()
{
	Node *head = new Node();
	Node *second = new Node();
	Node *third = new Node();
	
	head->data = 1;
	head->link = second;
	second->data = 2;
	second->link = third;
	third->data = 3;
	third->link = NULL;
	
	// print the linked list
	std::cout << "Linked list before adding node at beginning:\n";
	printList(head);
	
	// insert a node at the beginning of the list and print the list
	insertFirst(head);
	std::cout << "Linked list after adding node at the beginning:\n";
	printList(head);
	
	return 0;
}

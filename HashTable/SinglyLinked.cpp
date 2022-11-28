#include "SinglyLinked.h"

//Constructor to make an object of the class.
myList::myList()
{

}

//print out front or head
void myList::front()
{
	if (head != NULL)
	{
		cout << head->data << endl;
	}

}

//print out back
void myList::back()
{
	//create temp so we dont mess with head
	struct Node* temp = head;
	//while loop to get to the last in list
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	//print out last
	cout << temp->data << endl;
}

//insert front
//redo this
void myList::insertFront(int val)
{
	//create new node
	struct Node* newNode = new Node;
	//set data
	newNode->data = val;
	//set position of node
	newNode->next = head;
	//reset position of head
	head = newNode;
}

//insert back
void myList::insertBack(int val)
{
	//create new node
	struct Node* newNode = new Node;
	//set value of node
	newNode->data = val;
	//set value of next to null so back of function can stop
	newNode->next = NULL;

	//create temp node
	struct Node* temp = head;

	//get the last node
	while (temp->next != NULL)
	{
		temp = temp->next;

	}
	//set newNode in the last position
	temp->next = newNode;

}

//insert funciton
void myList::insert(int val)
{
	//Create stuff- come on we know this
	Node* newNode = new Node;
	newNode->data = val;
	struct Node* temp = head;

	//if insert at the beginning of list
	if (head == NULL || val < head->data)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		//while loop to get position of temp
		while (temp->next != NULL && temp->next->data < val)
		{
			temp = temp->next;
		}

		//create the node
		newNode->next = temp->next;
		temp->next = newNode;

	}

}

//display
void myList::display()
{
	//create temp node = to head
	struct Node* temp;
	temp = head;

	//iterate through list and display data
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

//pop_front
void myList::pop_front()
{
	//create temp node = to head
	struct Node* temp = head;

	//get front of function
	if (temp != NULL)
	{
		//set the new head
		head = temp->next;
		//delete temp
		delete (temp);
	}

}

//pop_back
void myList::pop_back()
{
	//create temp node = to head
	struct Node* temp;
	temp = head;

	//while loop to get the second to last node
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	//set null node to the last node so the last node is deleted
	struct Node* lastNode = temp->next;
	temp->next = NULL;
}

//empty
bool myList::empty()
{
	// check to see if head is equal to something
	if (head = NULL)
	{
		return true;
	}
	else
		return false;
}

//size
int myList::size()
{
	//create temp node = to head
	struct Node* temp;
	temp = head;
	int count = 0;

	//iterate through list and increment count;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	//return count
	return count;
}

//reverse
void myList::reverse()
{
	//create temp node = to head
	struct Node* temp;
	temp = head;
	//initialize currVal
	int currVal = 0;

	//while loop to run through list
	while (temp != NULL)
	{
		//get the currVal
		int currVal = temp->data;
		//insert a new Node at the front with the currVal
		insertFront(currVal);

		//move temp
		temp = temp->next;
	}

	//iterate through list to delete the old list
	for (int i = 0; i < size(); i++)
	{
		pop_back();
	}
}


void myList::merge(myList aList)
{
	//create temp node = to head of given list
	struct Node* temp;
	temp = aList.head;
	int currVal = 0;

	//while loop to iterate through list
	while (temp != NULL)
	{
		//get currVal of new list node
		int currVal = temp->data;
		//insert given node in the back
		insertBack(currVal);
		//move temp
		temp = temp->next;

	}
}
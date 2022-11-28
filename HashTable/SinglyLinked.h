#pragma once
/*Jack Utzerath
* CST-201
* SIngly Linked List
*/

#include <iostream>
#include <string>
#include <cstddef>
using namespace std;


class myList
{

public:

	struct Node {
		int data;
		struct Node* prev;
		struct Node* next;
	};

	struct Node* head = NULL;
	myList();

	void front();
	void back();
	void insertFront(int val);
	void insertBack(int val);
	void insert(int val);
	void display();
	void pop_front();
	void pop_back();
	bool empty();
	int size();
	void reverse();
	void merge(myList aList);


};

#include <string>
#include <iostream>
using namespace std;


struct node
{
	string data;
	node* next = NULL;
  
};

struct node* bucketArr[11];
class hashing

{
public:

	const int SIZE = 11;
	const int HASH = 11;
	

	hashing()
	{
	}

	int toInt(string data)
	{
		int tot = 0;
		for (int i = 0; i < data.length(); i++)
		{
			int num = data.at(i);
			tot = tot + num;
		}
		return tot;
	}
	void insert(string data)
	{
		struct node* node = new(struct node);
		node->data = data;
		node->next = bucketArr[toInt(data) % HASH];
		bucketArr[toInt(data) % HASH] = node;
		
	}
  
	bool find(string lookup)
	{
		
		//cout << lookup << endl;
		int x = toInt(lookup) % HASH;
		//cout << x << endl;
    
		if (bucketArr[x] == NULL)
		{
		  cout << "No where to be found";
		  return false;
		}
		//cout << bucketArr[x]->data << endl;

		if (bucketArr[x]->data == lookup)
		{
			cout << "Found it here";
			return true;
		}
		struct node* temp = bucketArr[x];
		while (temp != NULL)
		{
			if (temp->data == lookup)
			{
				cout << "Found it :)";
				return true;
			}
			temp = temp->next;
		}
		
		return false;
		

	}

	void display()
	{
    
		struct node* temp = new(struct node);

		for (int i = 0; i < SIZE; i++)
		{
			int x = i % HASH;
			temp = bucketArr[x];
      
			while (temp != NULL)
			{
				cout << temp->data;
				temp = temp->next;
			}
		}
		

		cout << endl;
  
	}

	

};
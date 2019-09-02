#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class list
{
	
public:
	struct node
	{
		string data;
		int count = 1;
		node* next;
	};

	node * head, *tail;

	list();
		
	void nodegen(string fileName);
	
	void display();
	
	void duprem(node *node2);

	void sorter();
	
};

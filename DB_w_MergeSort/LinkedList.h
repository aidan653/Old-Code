#pragma once
#include "Node.h"
class LinkedList {
private:
	node* first, * last, * current;
public:
	int counter;
	LinkedList();
	void addNode(int ID, string fname, string lname);
	void editfName(string name);
	void editlName(string name);
	void editID(int id);
	void addNodeClass(Person p);
	bool goToNext();
	void goTo(int iterations);
	Person getCurrent();
	void goToFirst();
	void delNode();
	void clearAll();
	bool isEmpty();
	bool oneOrLess();
	bool isCurrNull();
	node* getHead();
};

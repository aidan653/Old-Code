#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() {
	first = NULL;
	last = NULL;
	current = NULL;
	counter = 0;
}

node* LinkedList::getHead() {
	if (first != NULL)
		return first;
}

void LinkedList::addNode(int ID, string fname, string lname) {
	counter++;
	node* tmp = new node;
	tmp->p.setID(ID);
	tmp->p.setfName(fname);
	tmp->p.setlName(lname);
	tmp->next = NULL;

	if (first == NULL) {
		first = tmp;
		current = tmp;
		last = tmp;
	}
	else {
		last->next = tmp;
		last = last->next;
	}
}

bool LinkedList::isCurrNull() {
	if (current->next == NULL)
		return true;
	else
		return false;
}

void LinkedList::goTo(int iterations) {
	current = first;
		int count = 0;
		while (current != NULL) {
			if (count == iterations)
				return;
			count++;
			current = current->next;
		}
}

bool LinkedList::goToNext() {
	if (current->next == NULL)
		return false;
	current = current->next;
	return true;
}

Person LinkedList::getCurrent() {
	if (current != NULL) {
		Person per = current->p;
		return per;
	}
	else {
		Person per;
		per.setfName("0");
		per.setlName("0");
		per.setID(0);
		return per;
	}
}

void LinkedList::editfName(string name) {
	current->p.setfName(name);
}

void LinkedList::editlName(string name) {
	current->p.setlName(name);
}

void LinkedList::editID(int id) {
	current->p.setID(id);
}

void LinkedList::goToFirst() {
	current = first;
}

void LinkedList::addNodeClass(Person p) {
	addNode(p.getID(), p.getfName(), p.getlName());
}

void LinkedList::delNode() {
	if (current == NULL)
		return;
	if (current == first) {
		if (first->next == NULL) {
			node* temp = first;
			first = NULL;
			current = NULL;
			last = NULL;
			delete temp;
			counter--;
			return;
		}
		else {
			node* deleteNode = first;
			current = first->next;
			first = first->next;
			delete deleteNode;
			counter--;
			return;
		}
	}
	else {
		current->p = first->p;
		node* deleteNode = first;
		first = first->next;
		delete deleteNode;
		counter--;
		if (first == NULL) {
			last = NULL;
		}
		return;
	}
}

bool LinkedList::isEmpty() {
	if (first == NULL)
		return true;
	else
		return false;
}

bool LinkedList::oneOrLess() {
	if (first == NULL)
		return true;
	else if (first->next == NULL)
		return true;
	else
		return false;
}

void LinkedList::clearAll() {
	goToFirst();
	int loopCounter = counter;
	for (int i = 0; i < loopCounter - 1; i++) {
		delNode();
	}
	delNode();
}

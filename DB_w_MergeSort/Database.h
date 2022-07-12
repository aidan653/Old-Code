#pragma once
#include "Person.h"
#include "LinkedList.h"

class Database {
private:
	LinkedList mainList;
	//void recursive(string& a);
	void MergeSort(node** headRef);
	void editOption();
	void writeIn();
	void addPersonPrompt();
	bool idSearch(int ID);
	void searchByID();
	void fNameSearch();
	void lNameSearch();
	void deletePerson();
	node** headRef;
	void FrontBackSplit(node* source, node** frontRef, node** backRef);
	node* SortedMerge(node* a, node* b);
	bool sorted();
	inline bool isInteger(const string& s);
public:
	Database();
	void rtm();
	void readIn();
	void addPerson(int ID, string fname, string lname);
	void display(LinkedList l);
	void prompt();
	void editFirstName(int id);
	void editLastName(int id);
	//void editActive(int id);
};
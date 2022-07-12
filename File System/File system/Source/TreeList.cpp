#include "../Header/TreeList.h"
#include <iostream>

using std::cout;

TreeList::TreeList()
{
	first = nullptr;
	last = nullptr;
	current = nullptr;
	lag = nullptr;
}

void TreeList::add(std::string dir)
{
	TreeNode* newSibiling = new TreeNode;
	if (first == nullptr) { //Sets appropriate variables if nothing exists
		first = newSibiling;
		last = newSibiling;
		current = first;
		newSibiling->name = dir;
	}
	else {
		last->next = newSibiling; //Otherwise tacks on to the end of the list
		last = newSibiling;
		newSibiling->name = dir;
	}
}

void TreeList::goNext() //Should be used any time current needs to move
{
	if (current == nullptr)
		return;
	else if (current->next != nullptr)
		lag = current;
		current = current->next;
}

int TreeList::deleteCurrent()
{
	if (current == nullptr)
		return 0;
	else if (first == last) { //Set everything to nullptr then delete
		TreeNode* temp = first;
		first = nullptr;
		last = first;
		current = first;
		lag = current;
		delete temp;
		return 0;
	}
	else if (first->next == last && current == last) { //Condition for list of two where current is last
		TreeNode* temp = current;
		last = first;
		current = first;
		delete temp;
		return 1;
	}
	else if (first->next == last && current == first) { //Condition for list of two where current is first
		TreeNode* temp = current;
		first = last;
		current = last;
		delete temp;
		return 1;
	}
	else if (current == first) { //Handles what to do if current is first by setting current equal to next
		TreeNode* temp = current;
		first = first->next;
		current = first;
		delete temp;
		return 1;
	}
	else if (current == last) {   //Assuming I program well enough there is a lag node pointer which is theoretically one behind current
		TreeNode* temp = current; //So I set last to the lag variable then delete a temp which was set to last
		last = lag;			      //Just don't delete last again without going to first, first ¯\_(ツ)_/¯
		current = lag;
		delete temp;
		return 1;
	}
	else {
		TreeNode* temp = current;//The only case not covered above is where current is somewhere in the middle of the list
		current = current->next; //Utilizes lag variable to keep list structure together
		lag->next = current;     //When in doubt go to first
		delete temp;
		return 1;
	}
}

bool TreeList::listOfOne() //If it's a list of one, first would equal last. Hopefully.
{
	if (first == last)
		return true;
	else
		return false;
}

bool TreeList::goTo(std::string folder) //returns false if not found
{
	goToFirst();
	if (current == nullptr) { //If list is somehow empty
		return false;
	}
	if (current->name == folder) { //If it's the first node
		return true;
	}
	else {
		while (!atEnd()) { //Goes next until current equals the folder name
			if (folder == current->name)
				return true;
			else
				goNext();
		}
		if (folder == current->name) //Does one last check to see if the folder name is last bc loop will break if current is last and won't check
			return true;
		return false;
	}
}

bool TreeList::goTo(TreeNode* node) //Same as goTo just an overload that takes in a node argument
{
	goToFirst();
	if (current == node) {
		return true;
	}
	else {
		while (!atEnd()) {
			if (node == current)
				return true;
			else
				goNext();
		}
		if (node == current)
			return true;
		return false;
	}
}

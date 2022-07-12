#pragma once
#include "../Header/TreeNode.h"
#include <string>

class TreeList{
public:
	TreeList();
	void add(std::string dir);
	bool isFirstNull() { return (first == nullptr) ? true : false; }
	void goNext();
	void goToFirst() { current = first; }
	std::string getCurrentName() { return current->name; }
	TreeNode* getCurrent() { return current; }
	bool atEnd() { return (current->next == nullptr) ? true : false; }
	int deleteCurrent();
	bool listOfOne();
	bool goTo(std::string folder);
	bool goTo(TreeNode* node);
private:
	TreeNode* first;
	TreeNode* last;
	TreeNode* current;
	TreeNode* lag;
};
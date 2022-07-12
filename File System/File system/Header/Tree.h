#include <string>
#include <iostream>
#include "../Header/TreeList.h"

class Tree {
private:
	TreeNode* root;
	TreeNode* lagx;
	TreeNode* currx;
public:
	Tree();
	void addDir(std::string dir);
	void displayChildren();
	bool deleteCurrx();
	void goToLowestLayer(TreeNode* node);
	bool cd(std::string dirName);
	bool goUp();
	std::string getCurrxName() { return currx->name; }
	bool doesExist(std::string dirName);
	TreeNode* getCurrx() { return currx; }
};
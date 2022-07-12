#pragma once
#include <string>
//#include "TreeList.h" //bUt iF yUo incLUde TreeNode.h iN TreeList.h tgeN yOu HaVe a .h lOOp

class TreeList; //Thats where forward declarations come in hope some other class knows what they're doing

class TreeNode{
public:
	std::string name;
	TreeNode* next;
	TreeNode* parent;
	TreeList* children;
	TreeNode();
};
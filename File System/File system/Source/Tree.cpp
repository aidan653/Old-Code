#include "../Header/Tree.h"

using std::string; 
using std::cout;
using std::cin;
using std::endl;

void Tree::addDir(string dir)
{
	if (currx->children == nullptr) { //If there are no children create a new list then add dir
		TreeList* newDir = new TreeList;
		currx->children = newDir;
		newDir->add(dir);
	}
	else {
		currx->children->add(dir); //Else add dir
	}
}

void Tree::displayChildren()
{
	if (currx->children == nullptr) {
		cout << endl <<"There are no files in this directory." << endl;
		return;
	}
	else {
		TreeList* child = currx->children;
		child->goToFirst();
		while (!child->atEnd()) {
			cout << child->getCurrentName() << endl; //While not at end display the current name and go next
			child->goNext();
		}
		cout << child->getCurrentName() << endl; //Once more bc of loop condition
	}
}

bool Tree::deleteCurrx()
{
	if (currx->children == nullptr) {
		return false;
	}
	else
		goToLowestLayer(currx);
	return true;
}
/*
					  ┌──────────────────┐					~~Recursive deletion function
					  │                  │                  ~~Works by sending in a currx (current tree node) and then evaluating and deleting it's children
					  │                  │                  ~~Looks at nodes children the sends that as the functions argument, then deletes that child node                 
					  │       NODE       │
					  │                  │
					  │                  │
		   ┌──────────┴───┬───────────┬──┴────────┐
		   │              │           │           │
	  ┌────▼────┐    ┌────▼────┐ ┌────▼────┐ ┌────▼────┐    ~~If a child node has children it just repeates the process
	  │         │    │         │ │         │ │         │    ~~If it doesn't then it just deletes the node
	  │  CHILD  ├────►  CHILD  ├─►  CHILD  ├─►  CHILD  │    ~~The delete function in the list handles everything so I opted just to go to
	  │    1    │    │    2    │ │    3    │ │    4    │    ~~the first node every time the function is called or at the start of every loop instead of going next
   ┌──┴────┬────┴──┐ └─────────┘ └─────────┘ └─────────┘    ~~Just because my deleteCurrent function is best used with deleting the first off the list
   │       │       │
┌──▼──┐ ┌──▼──┐ ┌──▼──┐										~~Once everything with children are out of the way, the higher stack function calls take care of parent sister and brothers
│ SUB │ │ SUB │ │ SUB │										~~It remembers this because every call has an instance of tree list for it to go through
│  1  ├─►  2  ├─►  3  │
└─────┘ └─────┘ └─────┘
 */
void Tree::goToLowestLayer(TreeNode* node) //Code I commented out is just for keeping track of the nodes I'm deleting to make sure I'm deleting them all
{
	TreeList* child = node->children;
	child->goToFirst();
	TreeNode* parent = node;
	TreeNode current = *child->getCurrent();
	while (!child->listOfOne()) {
		child->goToFirst();
		//current = *child->getCurrent();
		if (child->getCurrent()->children != nullptr) {
			goToLowestLayer(child->getCurrent());//If child has children call this function with child of node
			//current = *child->getCurrent();
			//cout << "Deleted extra 2 " << current.name << endl;
			if (child->deleteCurrent() == 0) {	//Delete current child after function gets called on it's children
				cout << "inside if statement" << endl;
				parent->children = nullptr;
				delete child;
				//cout << "Deleted 1 " << current.name << endl;
			}
		}
		else {                                  //Else, child has no children, delete node
			//current = *child->getCurrent();
			if (child->deleteCurrent() == 0) {			//Delete returns 0 if it deletes the last one in the list, or if current is null, 						
				cout << "inside if statement" << endl;  //which shouldn't happen-because of loop condition-but just in case something bizzare happens.
				parent->children = nullptr;				//Also useful for figuring out that something bizzare is happening if cout flag goes off
				delete child;
				//cout << "Deleted 2 " << current.name << endl;
			}
			//cout << "Deleted extra 1 " << current.name << endl;
		}
	}
	if (child->listOfOne() && child->getCurrent()->children == nullptr) { //If there is one child in the current list and has no children
		parent->children = nullptr;
		//current = *child->getCurrent();
		child->deleteCurrent();
		delete child;
		//cout << "Deleted 3 " << current.name << endl;
	}
	else if (child->listOfOne() && child->getCurrent()->children != nullptr) { //If it is a list of one and child has children
		goToLowestLayer(child->getCurrent()); //Call this function with child of node, then delete current child
		parent->children = nullptr;
		child->deleteCurrent();
		delete child;
		//cout << "Deleted 4 " << current.name << endl;
	}
}

bool Tree::cd(std::string dirName)
{
	TreeList* child = currx->children; //Not much here, just keeps track of a lag variable to set as every childs parent
	if (!child->goTo(dirName))
		return false;
	else {
		lagx = currx;
		currx = child->getCurrent();
		currx->parent = lagx;
		return true;
	}
}

bool Tree::goUp()
{
	if (currx->parent == nullptr) 
		return false;
	else {
		currx = currx->parent;
		return true;
	}
}
bool Tree::doesExist(std::string dirName) //Returns true or false if there is evidence of something already existing or not
{
	TreeList* child = currx->children;
	if (!child->isFirstNull()) {
		child->goToFirst();
	}
	if (child == nullptr) {
		return false;
	}
	if (!child->goTo(dirName)) { //Goto returns false if something can't be found
		return false;
	}
	else {
		return true;
	}
}

Tree::Tree()
{
	root = new TreeNode;
	root->name = "C:";
	currx = root;
	lagx = currx;
}
#include "../Header/FileSystem.h"
#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::endl;

bool FileSystem::compareString(string str, string comparison) //Creates a char array and goes through each char to see if first str matches what you want to compare it to
{
	int n = comparison.length();

	char checker[50];
	char compareChar[50];
	strcpy_s(checker, str.c_str());
	strcpy_s(compareChar, comparison.c_str());
	
	for (int i = 0; i < n; i++)
	{
		if (checker[i] != compareChar[i]) {
			return false;
		}
	}
	return true;
}

void FileSystem::makeFunction(std::string command)
{
	char cmd[50];
	strcpy_s(cmd, command.c_str());
	string append;
	for (int i = 5; i < command.length(); i++) //Anything after the length of the command plus the space will append to the append string and will be the new directory name
	{
		append += cmd[i];
	}
	if (fileTree.getCurrx()->children == nullptr) { //If there is no child, create a list then add node
		fileTree.addDir(append);
		cout << "Added Directory" << endl << endl;
	}
	else if (!fileTree.doesExist(append)) { //Makes it so you can't add in a directory with the same name because I'm a lazy programmer
		fileTree.addDir(append);
		cout << "Added Directory" << endl << endl;
	}
	else
		cout << "You are most likely trying to enter a directory name which already exists, please enter a new one." << endl;
}

void FileSystem::goToFunction(std::string command)
{
	char cmd[50];
	strcpy_s(cmd, command.c_str());
	string append;
	for (int i = 5; i < command.length(); i++) //Same append functionality as before
	{
		append += cmd[i];
	}
	if (fileTree.getCurrx()->children == nullptr) {
		cout << "The main directory has no children." << endl;
	}
	else if (fileTree.doesExist(append)) { //If it does exist the change currx to that directory, then push back directory name to the filePath vector
		fileTree.cd(append);
		filePath.push_back(fileTree.getCurrxName());
	}
	else {
		cout << "couldn't find :(" << endl;
	}
}

void FileSystem::deleteFunction()
{
	if (fileTree.getCurrx()->parent == nullptr) //If your at the C: directory, or somehow the parent of where you're at disappears
		cout << "I wouldn't recommend that" << endl;
	else {
		TreeNode* temp = fileTree.getCurrx();//Temp var to keep track of curr directory to delete after emptying of list & children
		fileTree.deleteCurrx();
		fileTree.goUp();
		filePath.pop_back();
		fileTree.getCurrx()->children->goTo(temp); //Go to that temp var, then delete it
		if (fileTree.getCurrx()->children->deleteCurrent() == 0) { //Delete current returns 0 when the list doesn't exist or it deletes the last one in the list
			TreeList* temp2 = fileTree.getCurrx()->children;
			delete temp2;
			fileTree.getCurrx()->children = nullptr;
		}
	}
}

FileSystem::FileSystem()
{
	filePath.push_back(fileTree.getCurrxName());
	cout << "Type QUIT to exit" << endl;
}

void FileSystem::mainDisplay()
{
	while (quit) {
		string command, fp;
		for (int i = 0; i < filePath.size(); i++) { //Display each index in the vector which changes based on currx level
			if (i + 1 == filePath.size())
				cout << filePath[i] << ">";
			else
				cout << filePath[i] << "\\";
		}
		std::getline(cin, command); //Breaks about 100% less than std::cin and can include spaces


		if (command == "LIST") {
			if (fileTree.getCurrx()->children != nullptr)
				fileTree.displayChildren();
			else
				cout << "No files are in this directory" << endl << endl;
		}
		else if (compareString(command, "MAKE "))
			makeFunction(command);
		else if (compareString(command, "GOTO "))
			goToFunction(command);
		else if (command == "GOUP") {
			if (fileTree.getCurrx()->parent == nullptr) { //Tree.cpp handles most of this
				cout << "I wouldn't recommend that" << endl;
			}
			fileTree.goUp();
			filePath.pop_back();
		}
		else if (command == "DEL") {
			deleteFunction();
		}
		else if (command == "QUIT")
			return;
		else
			cout << "Unrecognized command, please try again." << endl;
	}
}

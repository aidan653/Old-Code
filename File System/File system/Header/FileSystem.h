#pragma once
#include "../Header/Tree.h"
#include <vector>
#include <string>

class FileSystem {
private:
	Tree fileTree;
	std::vector<std::string> filePath;
	bool compareString(std::string str, std::string comparison);
	int counter = 0;
	bool quit = true;
	void makeFunction(std::string command);
	void goToFunction(std::string command);
	void deleteFunction();
public:
	FileSystem();
	void mainDisplay();
};
#include "Database.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	Database database;
	database.readIn();
	database.prompt();
	return 0;
}
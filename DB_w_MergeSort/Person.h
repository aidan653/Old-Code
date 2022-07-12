#pragma once
#include <string>
using namespace std;
class Person {
	private:
		int ID;
		string fname;
		string lname;
	public:
		Person() { ID = 0; }
		int getID();
		void setID(int iden);
		void setfName(string name);
		void setlName(string name);
		string getlName();
		string getfName();
		void display();
		void header();
};

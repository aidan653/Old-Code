#include "Person.h"

#include <iostream>

#include <string>

#include <fstream>

#include <iomanip>

using namespace std;

//Displays a person
void Person::display() {
    cout << setw(7) << left << ID;
    cout << setw(20) << left << fname;
    cout << setw(20) << left << lname;
    cout << endl;
}
//Header
void Person::header() {
    cout << "ID     ";
    cout << setw(20) << left << "First Name";
    cout << setw(20) << left << "Last Name";
    cout << "\n\n";
}

int Person::getID() {
    if (ID != NULL) {
        return ID;
    }
    return 0;
}

void Person::setID(int iden) {
    ID = iden;
}

void Person::setfName(string name) {
    fname = name;
}

void Person::setlName(string name) {
    lname = name;
}

string Person::getfName() {
    if (!empty(fname))
        return fname;
    return "0";
}

string Person::getlName() {
    if (!empty(lname))
        return lname;
    return "0";
}
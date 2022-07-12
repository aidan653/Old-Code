#include "Database.h"

#include <iostream>

#include <string>

#include <fstream>

#include <iomanip>

#include <vector>

using namespace std;

void Clear() {
    cout << "\x1B[2J\x1B[H";
}

Database::Database() {
    mainList.goToFirst();
    headRef = new node*;
}

//Validity Check
bool checkNum(string s) {
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]) == false)
            return false;
        return true;
    }
}
int userChoiceCheck(int low, int high) {
    cout << "Please Input A Number: ";
    if (low > high) {
        int temp = low;
        low = high;
        high = low;
    }
    string input = "?";
    cin >> input;
    if (!checkNum(input)) {
        userChoiceCheck(low, high);
    }
    if (stoi(input) > high || stoi(input) < low) {
        userChoiceCheck(low, high);
    }
    if (stoi(input) <= high && stoi(input) >= low) {
        return stoi(input);
    }
}

//Main prompt
void Database::prompt() {
    Clear();
    int optt;
    cout << "1...Add a Person" << endl;
    cout << "2...Edit Persons" << endl;
    cout << "3...Display Persons" << endl;
    cout << "4...Delete a person" << endl;
    cout << "5...Search by ID" << endl;
    cout << "6...Search by first name" << endl;
    cout << "7...Search by last name" << endl;
    cout << "8...Quit" << endl;
    optt = userChoiceCheck(1, 8);
    switch (optt) {
    case 1:
        addPersonPrompt();
        break;
    case 2:
        editOption();
        break;
    case 3:
        display(mainList);
        break;
    case 8:
        writeIn();
        break;
    case 5:
        searchByID();
        break;
    case 6:
        fNameSearch();
        break;
    case 7:
        lNameSearch();
        break;
    case 4:
        deletePerson();
    default:
        break;
    }
}

//reads people in from file
void Database::readIn() {
    ifstream fin;
    fin.open("people.txt");
    int ID;
    string fname, lname;
    while (fin >> ID >> fname >> lname) {
        mainList.addNode(ID, fname, lname);
    }
    fin.close();
    mainList.getCurrent().display();
    *headRef = mainList.getHead();
}

//Add person into array
void Database::addPerson(int ID, string fname, string lname) {
    mainList.addNode(ID, fname, lname);
}

//Delete
void Database::deletePerson() {
    Clear();
    int choice;
    string id;
    cout << "Enter the ID of ther person you would like to delete: ";
    cin >> id;

    while (!isInteger(id)) {
        cout << "Enter a valid number: ";
        cin >> id;
    }

    if (!idSearch(stoi(id))) {
        cout << "Person does not exist" << endl;
        rtm();
    }
    else {
        cout << "Would you like to delete " << endl; 
        mainList.getCurrent().display();
        cout << "Type 1 for yes and 0 for no: " << endl;
        int choice = userChoiceCheck(0, 1);
        if (choice == 1) {
            mainList.delNode();
            rtm();
        }
        else
            rtm();
    }
}

//Display population of persons in the array
void Database::display(LinkedList l) {
    Clear();
    l.goToFirst();
    if (l.isEmpty()) {
        cout << "This list is empty";
        rtm();
        return;
    }
    if (!sorted())
        MergeSort(headRef);

    l.getCurrent().header();
    for (int i = 0; i < l.counter; i++) {
        l.getCurrent().display();
        l.goToNext();
    }

    rtm();
}

void Database::rtm() {
    cout << "\n\n" << "Type 1 to Return to Menu: " << endl;
    bool opt = userChoiceCheck(0, 1);
    opt = 0;
    if (!opt)
        prompt();
    else
        rtm();
}

void Database::searchByID() {
    Clear();
    string id;
    cout << "Enter the id of the person you would like to see" << endl;
    cin >> id;

    while (!isInteger(id)) {
        cout << "Enter a valid number: ";
        cin >> id;
    }

    if(!idSearch(stoi(id))) {
        cout << "This person does not exist" << endl;
        rtm();
        return;
    }
    idSearch(stoi(id));

    mainList.getCurrent().header();
    mainList.getCurrent().display();
    rtm();
}

node* Database::SortedMerge(node* a, node* b)
{
    node* result = NULL;

    //Base cases
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    if (a->p.getlName() <= b->p.getlName()) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

void Database::MergeSort(node ** headRef) {
    node* head = *headRef;
    node* a;
    node* b;

    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    FrontBackSplit(head, &a, &b);

    MergeSort(&a);
    MergeSort(&b);

    *headRef = SortedMerge(a, b);
}

void Database::FrontBackSplit(node* source, node** frontRef, node** backRef)
{
    node* fast;
    node* slow;
    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

bool Database::sorted() {
    mainList.goToFirst();
    node* lead = *headRef;
    lead = lead->next;

    while (lead->next != NULL) {
        if (lead->p.getlName() < mainList.getCurrent().getlName())
            return false;
        lead = lead->next;
        mainList.goToNext();
    }

    cout << "Sorted";
    return true;
}

//Prompts user to enter a person
void Database::addPersonPrompt() {
    Clear();
    string ID;
    int actual;
    string fname, lname;

    cout << "ID: ";
    cin >> ID;
    while (!isInteger(ID))
    {
        cout << "Enter a valid number: ";
        cin >> ID;
    }
    actual = stoi(ID);

    cout << "First Name: ";
    cin >> fname;
    cout << "Last Name: ";
    cin >> lname;
    addPerson(actual, fname, lname);
    prompt();
}

inline bool Database::isInteger(const string& s) {
    if (s.empty() || (!isdigit(s[0]))) return false;

    char* p;
    strtol(s.c_str(), &p, 10);

    return (*p == 0);
}

//Allows user to go into another menu for editing people's ids
void Database::editOption() {
    Clear();
    string id;
    int choice;
    bool confirm;
    cout << "Enter ID of Person You Would Like to Edit: ";
    cin >> id;

    while (!isInteger(id)) {
        cout << "Input a valid number: " << endl;
        cin >> id;
    }

    int beef = stoi(id);
    if (!idSearch(beef)) {
        cout << "Person does not exist" << endl;
        rtm();
        return;
    }
    idSearch(beef);

    //Confirmation
    cout << "You Would Like to Edit " << mainList.getCurrent().getfName() << " " << mainList.getCurrent().getlName() << " Correct? 1 for Yes or 0 for No" << endl;
    confirm = userChoiceCheck(0, 1);
    if (confirm == false) {
        prompt();
    }
    else {
        cout << "What Would You Like to Edit?" << endl << "1...For First Name" << endl << "2...For Last Name" << endl;
        choice = userChoiceCheck(1, 2);
        switch (choice) {
        case 1:
            editFirstName(beef);
            break;
        case 2:
            editLastName(beef);
            break;
        default:
            rtm();
            break;
        }
    }
}

void Database::editFirstName(int id) {
    string newName;
    int choice;
    cout << "Enter New First Name: ";
    cin >> newName;
    idSearch(id);
    mainList.editfName(newName);
    cout << "What would you like to do?" << endl << "1...Edit Last Name" << endl << "2...Return to Menu" << endl;
    choice = userChoiceCheck(1, 2);
    switch (choice) {
    case 1:
        editLastName(id);
        break;
    case 2:
        prompt();
        break;
    default:
        rtm();
        break;
    }
}

void Database::editLastName(int id) {
    string newName;
    int choice;
    cout << "Enter New Last Name: ";
    cin >> newName;
    mainList.editlName(newName);
    cout << "What would you like to do?" << endl << "1...Edit First Name" << endl << "2...Return to Menu" << endl;
    choice = userChoiceCheck(1, 3);
    switch (choice) {
    case 1:
        editFirstName(id);
        break;
    case 2:
        prompt();
        break;
    default:
        rtm();
        break;
    }
}

bool Database::idSearch(int ID) {
    mainList.goToFirst();
    for (int i = 0; i < mainList.counter + 1; i++)
    {
        if (mainList.getCurrent().getID() == ID)
            return true;
        else mainList.goToNext();
    }
    return false;
}

void Database::fNameSearch() {
    mainList.goToFirst();
    Clear();
    string fname;
    cout << "Enter name you would like to search for: ";
    cin >> fname;
    cout << "\n\n";
    mainList.getCurrent().header();
    for (int i = 0; i < mainList.counter + 1; i++)
    {
        if (mainList.getCurrent().getfName() == fname) {
            mainList.getCurrent().display();
            mainList.goToNext();
        }
        else mainList.goToNext();
    }
    rtm();
}

void Database::lNameSearch() {
    mainList.goToFirst();
    Clear();
    string lname;
    cout << "Enter name you would like to search for: ";
    cin >> lname;
    cout << "\n\n";
    mainList.getCurrent().header();
    for (int i = 0; i < mainList.counter + 1; i++)
    {
        if (mainList.getCurrent().getlName() == lname) {
            mainList.getCurrent().display();
            mainList.goToNext();
        }
        else mainList.goToNext();
    }
    rtm();
}

//Writes to file
void Database::writeIn() {
    ofstream fout;
    mainList.goToFirst();
    fout.open("people.txt");
    for (int i = 0; i < mainList.counter; i++) {
        fout << mainList.getCurrent().getID() << " " << mainList.getCurrent().getfName() << " " << mainList.getCurrent().getlName() << endl;
        mainList.goToNext();
    }
}
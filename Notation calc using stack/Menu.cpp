#include "Menu.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void clear() {
	cout << "\x1B[2J\x1B[H";
}

bool choiceCheck(char choice) {
	if (choice == 'p')
		choice = 'P';
	else if (choice == 'c')
		choice = 'C';
	else if (choice == 'q')
		choice = 'Q';
	switch (choice) {
		case '=':
			return true;
		case '+':
			return true;
		case '-':
			return true;
		case '*':
			return true;
		case '/':
			return true;
		case 'P':
			return true;
		case 'C':
			return true;
		case 'Q':
			return true;
		default:
			return false;
	}
}

void Menu::prompt() {
	char temp = 4;
	char* choice = &temp;
	string chupapi;
	while (!choiceCheck(*choice)) { //Keeps repeating menu until user enters a listed option
		clear();
		cout << "Would you like to: " << endl;
		cout << "= ... Add new number to the stack" << endl;
		cout << "+ ... Add last two numbers on the stack" << endl;
		cout << "- ... Subtract last two numbers on the stack" << endl;
		cout << "* ... Multiply last two numbers on the stack" << endl;
		cout << "/ ... Divide last two of the stack" << endl;
		cout << "P ... Pop and discard top number from the stack" << endl;
		cout << "C ... Clear the stack" << endl;
		cout << "Q ... Quit" << "\n\n\n";
		cin >> chupapi;
		choice = &chupapi.at(0);
	}
	if (*choice == 'p')
		*choice = 'P';
	if (*choice == 'c')
		*choice = 'C';
	if (*choice == 'q')
		*choice = 'Q';
	switch (*choice) { //Switch case to execute different functions that correspond with choices 
	case '=':
		newNum();
		break;
	case '+':
		addTwo();
		break;
	case '-':
		subTwo();
		break;
	case '*':
		multTwo();
		break;
	case '/':
		divTwo();
		break;
	case 'P':
		popper();
		break;
	case 'C':
		clearStack();
		break;
	case 'Q':
		cout << endl << "Cya" << endl;
		break;
	}
}

void Menu::cont() { //A prompt to return to the menu
	string confirm;
	cout << endl << "Type 1 to return to menu: ";
	cin >> confirm;
	if (confirm.at(0) == '1') {
		prompt();
	}
	else
		cont();
}

void Menu::newNum() {
	if (theStack->isFull()) {
		cout << "Stack Overflow" << endl;
		cont();
	}
	else {
		int num;
		cout << "Type the number you would like to push to the stack: ";
		cin >> num;
		theStack->push(num);
		theStack->display();
		cont();
	}
}

void Menu::addTwo() {
	if (theStack->isEmpty()) {
		cout << "Stack Underflow" << endl;
		cont();
	}
	else if (theStack->top == 0) {
		cout << "Can not add with only 1 number in the stack" << endl;
		cont();
	}
	else {
		int one = theStack->pop();
		int two = theStack->pop();
		int product = one + two;
		cout << one << " + " << two << " = " << product << endl;
		theStack->push(product);
		theStack->display();
		cont();
	}
}

void Menu::subTwo() {
	if (theStack->isEmpty()) {
		cout << "Stack Underflow" << endl;
		cont();
	}
	else if (theStack->top == 0) {
		cout << "Can not subtract with only 1 number in the stack" << endl;
		cont();
	}
	else {
		int one = theStack->pop();
		int two = theStack->pop();
		int product = one - two;
		cout << one << " - " << two << " = " << product << endl;
		theStack->push(product);
		theStack->display();
		cont();
	}
}

void Menu::multTwo() {
	if (theStack->isEmpty()) {
		cout << "Stack Underflow" << endl;
		cont();
	}
	else if (theStack->top == 0) {
		cout << "Can not multiply with only 1 number in the stack" << endl;
		cont();
	}
	else {
		int one = theStack->pop();
		int two = theStack->pop();
		int product = one * two;
		cout << one << " * " << two << " = " << product << endl;
		theStack->push(product);
		theStack->display();
		cont();
	}
}

void Menu::divTwo() {
	if (theStack->isEmpty()) {
		cout << "Stack Underflow";
		cont();
	}
	else if (theStack->top == 0) {
		cout << "Can not divide with only 1 number in the stack" << endl;
		cont();
	}
	else {
		int one = theStack->pop();
		int two = theStack->pop();
		if (two == 0) {
			cout << "Can not divide by 0" << endl;
			cont();
		}
		else {
			int product = one / two;
			cout << one << " / " << two << " = " << product << endl;
			theStack->push(product);
			theStack->display();
			cont();
		}
	}
}

void Menu::clearStack() {
	for (int i = 0; i < (theStack->counter()); i++)
	{
		theStack->pop();
	}
	cout << "The stack is cleared" << endl;
	cont();
}

void Menu::popper() {
	if (theStack->isEmpty()) {
		cout << "Stack Underflow";
		cont();
	}
	else {
		cout << theStack->pop() << " is removed from the stack" << endl;
		cont();
	}
}

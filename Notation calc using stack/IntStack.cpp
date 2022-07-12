#include <iostream>
#include <string>
#include <fstream>
#include "IntStack.h"
using namespace std;

MyStack::MyStack() {
	top = -1;
	for (int i = 0; i < 999; i++)
	{
		arr[i] = 0;
	}
}

bool MyStack::isEmpty() {
	if (top == -1)
		return true;
	else
		return false;
}

bool MyStack::isFull() {
	if (top == 999)
		return true;
	else
		return false;
}

void MyStack::push(int num) {
	if (isFull())
		cout << "Stack Overflow" << endl;
	else {
		top++;
		arr[top] = num;
	}
}

int MyStack::pop() {
	if (isEmpty()) {
		cout << "Stack Underflow" << endl;
		return 0;
	}
	else {
		int popValue = arr[top];
		arr[top] = 0;
		top--;
		return popValue;
	}
}

int MyStack::counter() {
	return (top + 1);
}

void MyStack::display() {
	if (isEmpty()) {
		cout << "Stack has no values" << endl;
	}
	else {
		cout << "Stack values are:" << endl;
		for (int i = top; i >= 0; i--)
		{
			cout << arr[i] << endl;
		}
	}
}

int MyStack::peek(int num) {
	if (isEmpty()) {
		cout << "Stack has no values" << endl;
		return 0;
	}
	else if (num > top) {
		cout << "Not a valid position" << endl;
	}
	else {
		cout << arr[num] << endl;
	}
}
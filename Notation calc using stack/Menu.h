#pragma once
#include "IntStack.h"

class Menu {
public:
	void prompt();
	void newNum();
	void addTwo();
	void subTwo();
	void multTwo();
	void divTwo();
	void clearStack();
	void popper();
private:
	MyStack aStack;
	MyStack *theStack = &aStack;
	void cont();
};
#pragma once
#include "Person.h"

class node {
public:
	Person p;
	node* next;
	node() { next = NULL; }
};
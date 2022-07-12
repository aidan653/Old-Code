#pragma once

class MyStack {
	public:
		int top;
		MyStack();
		bool isEmpty();
		bool isFull();
		void push(int num);
		int pop();
		int counter();
		void display();
		int peek(int num);
	private:
		int arr[1000];
};
#include <iostream>
using namespace std;

class Node {
	int data;
	Node* link;
public:
	Node() {
		this->link = NULL;
		this->data = 0;
	}
	Node(int val) {
		this->data = val;
		this->link = NULL;
	}
	int getValue() {
		return data;
	}
	void setValue(int val) {
		this->data = val;
		this->link = NULL;
	}
	friend class Stack;
};

class Stack {
	Node* top;
public:
	Stack() {
		top = NULL;
	}
	void push(int val);
	void pop();
	void print();
};

void Stack::push(int val) {
	Node* newNode = new Node(val);
	if (top == NULL) {
		top = newNode;
		cout << "Pushed Successfully" << endl;
		return;
	}
	Node* temp = top;
	top = newNode;
	top->link = temp;

}

void Stack::pop() {
	if (top == NULL) {
		cout << "Stack Underflow" << endl;
	}
	Node* temp = NULL;
	temp = top;
	top = top->link;
	cout << "Popped Element " << temp->data << endl;
	delete temp;
}

void Stack::print() {
	Node* temp = top;
	while (temp != NULL) {
		cout << temp->data << " " << endl;
		temp = temp->link;
	}
}

int main() {
	int ch=0, val;
	Stack S;
	cout << "1) Push in stack" << endl;
	cout << "2) Pop from stack" << endl;
	cout << "3) Display stack" << endl;
	cout << "4) Exit" << endl;
	while (ch != 4) {
		cout << "Enter choice: " << endl;
		cin >> ch;
		switch (ch) {
		case 1: {
			cout << "Enter value to be pushed:" << endl;
			cin >> val;
			S.push(val);
			break;
		}
		case 2: {
			S.pop();
			break;
		}
		case 3: {
			S.print();
			break;
		}
		case 4: {
			cout << "Exit" << endl;
			break;
		}
		default: {
			cout << "Invalid Choice" << endl;
		}
		}
	}
	return 0;

}
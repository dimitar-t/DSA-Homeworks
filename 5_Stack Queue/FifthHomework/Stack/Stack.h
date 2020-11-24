#pragma once
#include "Node.h"
#include <limits>
#include <stack>

using namespace std;

template<class T>
class Stack {
public:
	Node<T>* head;
	stack<T> minValues;
	int size;

	Stack();

	void push(T value);
	void pop();
	T peek();
	T min();
};

template<class T>
Stack<T>::Stack() {
	this->head = nullptr;
	this->size = 0;
}

template<class T>
void Stack<T>::push(T value) {
	Node<T>* node = new Node<T>(value);

	if (this->head == nullptr) {
		this->head = node;
		this->minValues.push(node->value);

		return;
	}

	node->next = this->head;
	this->head = node;

	if (this->minValues.top() <= node->value) {
		this->minValues.push(this->minValues.top());
	}
	else {
		this->minValues.push(node->value);
	}

	this->size++;
}

template<class T>
void Stack<T>::pop() {
	if (this->head != nullptr) {
		Node<T>* temp = this->head;
		this->head = this->head->next;
		delete temp;

		this->minValues.pop();

		this->size--;
	}
}

template<class T>
T Stack<T>::peek() {
	if (this->head != nullptr) {
		return this->head->value;
	}

	return T();
}

template<class T>
T Stack<T>::min() {
	return this->minValues.top();
}
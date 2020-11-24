#pragma once
#include "DoublyLinkedListNode.h"

template<class T>
class DoublyLinkedList {
public:
	DoublyLinkedListNode<T>* head;
	DoublyLinkedListNode<T>* mid;
	DoublyLinkedListNode<T>* tail;
	int count;

	DoublyLinkedList();

	void addBack(int data);
	void removeTail();

	void print() const;
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
	this->head = nullptr;
	this->mid = nullptr;
	this->tail = nullptr;
	this->count = 0;
}

template<class T>
void DoublyLinkedList<T>::addBack(int data) {
	DoublyLinkedListNode<T>* node = new DoublyLinkedListNode<T>(data);

	if (this->head == nullptr) { // no items in list
		this->head = node;
		this->mid = node;
		this->tail = node;
	}
	else if (this->head == this->tail) { // 1 item in list
		this->head->next = node;
		node->prev = this->head;
		this->tail = node;
	}
	else {
		this->tail->next = node;
		node->prev = this->tail;
		this->tail = node;
	}

	this->count++;

	// change mid
	if (this->count % 2 == 0 && this->count != 2) {
		this->mid = this->mid->next;
	}
}

template<class T>
void DoublyLinkedList<T>::removeTail() {
	if (this->head == this->tail) { // 1 item in list
		DoublyLinkedListNode<T>* temp = this->head;
		this->head = nullptr;
		this->mid = nullptr;
		this->tail = nullptr;

		delete temp;
	}
	else if (this->head->next == this->tail) { // 2 items in list
		DoublyLinkedListNode<T>* temp = this->tail;
		this->head->next = nullptr;
		this->tail = this->head;

		delete temp;
	}
	else {
		DoublyLinkedListNode<T>* temp = this->tail;
		this->tail = this->tail->prev;
		this->tail->next = nullptr;

		delete temp;
	}

	this->count--;

	// change mid
	if (this->count % 2 != 0 && this->count != 1) {
		this->mid = this->mid->prev;
	}
}

template<class T>
void DoublyLinkedList<T>::print() const {
	printf("%d", this->count);
	printf("%s", "\n");

	DoublyLinkedListNode<T>* current = this->head;
	while (current != nullptr) {
		printf("%d", current->data);
		printf("%s", " ");

		current = current->next;
	}
}
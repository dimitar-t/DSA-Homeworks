#pragma once
template<class T>
class DoublyLinkedListNode {
public:
	T data;
	DoublyLinkedListNode* next;
	DoublyLinkedListNode* prev;

	DoublyLinkedListNode(T data);
};

template<class T>
DoublyLinkedListNode<T>::DoublyLinkedListNode(T data) {
	this->data = data;
	this->next = nullptr;
	this->prev = nullptr;
}
#pragma once

template<class T>
class Node {
public:
	T value;
	Node<T>* next;

	Node(T value);
};

template<class T>
Node<T>::Node(T value) {
	this->value = value;
	this->next = nullptr;
}
#pragma once

template<class T>
class Node {
public:
	T key;
	Node* left;
	Node* right;

	Node(T key);
};

template<class T>
Node<T>::Node(T key) {
	this->key = key;
	this->left = nullptr;
	this->right = nullptr;
}

template<class T>
class BST {
private:
	Node<T>* minValueNode(Node<T>* root);

public:
	Node<T>* root;

	BST();

	void insertNode(T key);
	Node<T>* deleteNode(Node<T>* root, T key);
};

template<class T>
BST<T>::BST() {
	this->root = nullptr;
}

template<class T>
void BST<T>::insertNode(T key) {
	if (this->root == nullptr) {
		this->root = new Node<T>(key);

		return;
	}

	Node<T>* current = this->root;

	while (true) {
		if (key < current->key) {
			if (current->left != nullptr) {
				current = current->left;
			}
			else {
				current->left = new Node<T>(key);

				break;
			}
		}
		else if (key > current->key) {
			if (current->right != nullptr) {
				current = current->right;
			}
			else {
				current->right = new Node<T>(key);

				break;
			}
		}
		else {
			return;
		}
	}
}

template<class T>
Node<T>* BST<T>::deleteNode(Node<T>* root, T key) {
	if (root == nullptr) {
		return root;
	}
	
	if (key < root->key) {
		root->left = deleteNode(root->left, key);
	}
	else if (key > root->key) {
		root->right = deleteNode(root->right, key);
	}
	else {
		if (root->left == nullptr) {
			Node<T>* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == nullptr) {
			Node<T>* temp = root->left;
			free(root);
			return temp;
		}
		else {
			Node<T>* temp = minValueNode(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);

			return root;
		}
	}
}

template<class T>
Node<T>* BST<T>::minValueNode(Node<T>* root) {
	Node<T>* current = root;

	while (current->left != nullptr) {
		current = current->left;
	}

	return current;
}
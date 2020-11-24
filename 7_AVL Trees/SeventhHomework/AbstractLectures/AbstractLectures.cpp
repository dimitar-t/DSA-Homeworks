#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Node {
public:
	int value;
	Node* left;
	Node* right;
	int height;

	Node(int value) {
		this->value = value;
		this->left = nullptr;
		this->right = nullptr;
		this->height = 1;
	}
};

int max(int a, int b);

int height(Node* node);

Node* rightRotate(Node* y);

Node* leftRotate(Node* x);

int getBalance(Node* node);

Node* insert(Node* root, int value);

Node* minValueNode(Node* node);

Node* deleteNode(Node* root, int key);

void inorderTraversal(Node* root);

int main() {
	int n;
	cin >> n;

	Node* root = nullptr;

	cin.ignore();

	for (int i = 0; i < n; i++) {
		string input;

		getline(cin, input);		

		if (input == "inorder") {
			inorderTraversal(root);
			printf("\n");
		}
		else {
			string cmd = input.substr(0, input.find(" "));
			int num = stoi(input.substr(input.find(" "), input.length() - 1));

			if (cmd == "add") {
				root = insert(root, num);
			}
			else {
				root = deleteNode(root, num);
			}
		}
	}

	return 0;
}

int max(int a, int b) {
	return a >= b ? a : b;
}

int height(Node* node) {
	if (node == nullptr) {
		return 0;
	}

	return node->height;
}

Node* rightRotate(Node* y) {
	Node* leftChild = y->left;
	Node* grandChild = leftChild->right;

	leftChild->right = y;
	y->left = grandChild;

	y->height = max(height(y->left), height(y->right)) + 1;
	leftChild->height = max(height(leftChild->left), height(leftChild->right)) + 1;

	return leftChild;
}

Node* leftRotate(Node* x) {
	Node* rightChild = x->right;
	Node* grandChild = rightChild->left;

	x->right = grandChild;
	rightChild->left = x;

	x->height = max(height(x->left), height(x->right)) + 1;
	rightChild->height = max(height(rightChild->left), height(rightChild->right)) + 1;

	return rightChild;
}

int getBalance(Node* node) {
	if (node == nullptr) {
		return 0;
	}

	return height(node->left) - height(node->right);
}

Node* insert(Node* root, int value) {
	if (root == nullptr) {
		return new Node(value);
	}

	if (value < root->value) {
		root->left = insert(root->left, value);
	}
	else if (value > root->value) {
		root->right = insert(root->right, value);
	}
	else {
		return root;
	}

	root->height = max(height(root->left), height(root->right)) + 1;

	int balance = getBalance(root);

	if (balance > 1 && value < root->left->value) {
		return rightRotate(root);
	}

	if (balance < -1 && value > root->right->value) {
		return leftRotate(root);
	}

	if (balance > 1 && value > root->left->value) {
		root->left = leftRotate(root->left);

		return rightRotate(root);
	}

	if (balance < -1 && value < root->right->value) {
		root->right = rightRotate(root->right);

		return leftRotate(root);
	}

	return root;
}

Node* minValueNode(Node* node)
{
	Node* current = node;

	while (current->left != nullptr) {
		current = current->left;
	}

	return current;
}

Node* deleteNode(Node* root, int value)
{
	if (root == nullptr) {
		return root;
	}

	if (value < root->value) {
		root->left = deleteNode(root->left, value);
	}
	else if (value > root->value) {
		root->right = deleteNode(root->right, value);
	}
	else { 
		if ((root->left == nullptr) || (root->right == nullptr)) {
			Node* temp;
			if (root->left != nullptr) {
				temp = root->left;
			}
			else {
				temp = root->right;
			}
  
			if (temp == nullptr) {
				temp = root;
				root = nullptr;
			}
			else {
				*root = *temp;
			}
				   
			free(temp);
		}
		else {
			Node* temp = minValueNode(root->right);

			root->value = temp->value;
  
			root->right = deleteNode(root->right, temp->value);
		}
	}

	if (root == nullptr) {
		return root;
	}

	root->height = max(height(root->left), height(root->right)) + 1;

	int balance = getBalance(root);

	if (balance > 1 && getBalance(root->left) >= 0) {
		return rightRotate(root);
	}
 
	if (balance > 1 && getBalance(root->left) < 0) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if (balance < -1 && getBalance(root->right) <= 0) {
		return leftRotate(root);
	}

	if (balance < -1 && getBalance(root->right) > 0) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void inorderTraversal(Node* root) {
	if (root == nullptr) {
		return;
	}

	inorderTraversal(root->left);
	printf("%d ", root->value);
	inorderTraversal(root->right);
}
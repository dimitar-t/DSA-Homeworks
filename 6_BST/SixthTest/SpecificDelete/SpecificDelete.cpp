#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	Node* left;
	Node* right;
	int value;
	Node(int value) {
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}
};

class BST {

public:
	BST() {
		root = NULL;
	}

	void insert(int value) {
		root = insert(root, value);
	}

	void deletePenultimateAndPrint() {
		queue<Node*> queue;
		queue.push(this->root);

		while (!queue.empty()) {
			Node* current = queue.front();
			queue.pop();

			bool isValid = true;

			if (current->left == nullptr && current->right == nullptr) {
				isValid = false;
			}
			
			if (current->left != nullptr && (current->left->left != nullptr || current->left->right != nullptr)) {
				isValid = false;
			}

			if (current->right != nullptr && (current->right->left != nullptr || current->right->right != nullptr)) {
				isValid = false;
			}

			if (isValid) {
				if (current->left != nullptr && current->right == nullptr) {
					current->value = current->left->value;
					current->left = nullptr;
				}
				else {
					current->value = current->right->value;
					current->right = nullptr;
				}
			}

			if (current->left != nullptr) {
				queue.push(current->left);
			}

			if (current->right != nullptr) {
				queue.push(current->right);
			}
		}

		inOrderPrint(this->root);
	}

	void inOrderPrint(Node* root) {
		if (root == nullptr) {
			return;
		}

		inOrderPrint(root->left);
		cout << root->value << " ";
		inOrderPrint(root->right);
	}

private:
	//you can write helper functions if needed
	Node* root;

	Node* insert(Node* curNode, int value) {
		if (curNode == NULL) {
			curNode = new Node(value);
		}
		else if (curNode->value < value) {
			curNode->right = insert(curNode->right, value);
		}
		else if (curNode->value > value) {
			curNode->left = insert(curNode->left, value);
		}
		else {
			//if we already have this value at the tree - do nothing
		}
		return curNode;
	}
};

int main() {
	int n;
	cin >> n;
	int value;
	BST tree;
	for (int i = 0; i < n; i++) {
		cin >> value;
		tree.insert(value);
	}
	tree.deletePenultimateAndPrint();
	return 0;
}
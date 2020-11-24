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
		this->left = nullptr;
		this->right = nullptr;
	}
};

class BST {

public:
	BST() {
		root = nullptr;
	}

	void insert(int value) {
		root = insert(root, value);
	}

	void printSFB() {
		queue<Node*> queue;
		queue.push(this->root);

		bool goLeft = true;

		while (!queue.empty()) {
			if (goLeft) {
				vector<Node*> nodes;
				while (!queue.empty()) {
					nodes.push_back(queue.front());
					queue.pop();
				}

				for (int i = nodes.size() - 1; i >= 0; i--) {
					cout << nodes[i]->value << " ";
					
					if (nodes[i]->left != nullptr) {
						queue.push(nodes[i]->left);
					}

					if (nodes[i]->right != nullptr) {
						queue.push(nodes[i]->right);
					}
				}

				goLeft = false;
			}
			else {
				vector<Node*> nodes;
				while (!queue.empty()) {
					nodes.push_back(queue.front());
					queue.pop();
				}

				for (int i = nodes.size() - 1; i >= 0; i--) {
					cout << nodes[i]->value << " ";

					if (nodes[i]->right != nullptr) {
						queue.push(nodes[i]->right);
					}

					if (nodes[i]->left != nullptr) {
						queue.push(nodes[i]->left);
					}
				}

				goLeft = true;
			}
		}
	}

private:
	//you can write helper functions if needed
	Node* root;

	Node* insert(Node* curNode, int value) {
		if (curNode == nullptr) {
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

	tree.printSFB();
	return 0;
}
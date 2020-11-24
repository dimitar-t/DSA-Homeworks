#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include "BST.h"

using namespace std;

void getReverseOrder(vector<int>& elements, Node<int>* root);
void printTree(Node<int>* root);

int main() {
	int n, k;
	cin >> n >> k;

	BST<int> tree;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		tree.insertNode(input);
	}

	vector<int> elements;
	getReverseOrder(elements, tree.root);
	int kBiggest = elements[k - 1];

	tree.deleteNode(tree.root, kBiggest);

	printTree(tree.root);

	return 0;
}

void getReverseOrder(vector<int>& elements, Node<int>* root) {
	if (root == nullptr) {
		return;
	}

	getReverseOrder(elements, root->right);
	elements.push_back(root->key);
	getReverseOrder(elements, root->left);
}

void printTree(Node<int>* root) {
	if (root == nullptr) {
		return;
	}

	queue<Node<int>*> nodes;
	nodes.push(root);

	while (!nodes.empty()) {
		Node<int>* node = nodes.front();
		nodes.pop();

		printf("%d ", node->key);

		if (node->left != nullptr) {
			nodes.push(node->left);
		}

		if (node->right != nullptr) {
			nodes.push(node->right);
		}
	}
}
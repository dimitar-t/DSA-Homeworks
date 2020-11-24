#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Node {
public:
	int index;
	vector<Node*> children;

	Node(int index);
};

Node::Node(int index) {
	this->index = index;
}

int countSuccessors(Node* node);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<Node*> tree;

	for (int i = 0; i < n - 1; i++) {
		int parent, child;
		cin >> parent >> child;

		Node* childNode = new Node(child);
		if (i == 0) {
			Node* parentNode = new Node(parent);
			parentNode->children.push_back(childNode);
			tree.push_back(parentNode);
		}
		else {
			Node* parentNode = tree[parent];
			parentNode->children.push_back(childNode);
		}

		tree.push_back(childNode);
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", countSuccessors(tree[i]));
	}

	return 0;
}

int countSuccessors(Node* node) {
	int count = -1;

	queue<Node*> queue;
	queue.push(node);

	while (!queue.empty()) {
		count++;

		Node* child = queue.front();
		queue.pop();

		for (int i = 0; i < child->children.size(); i++) {
			queue.push(child->children[i]);
		}
	}

	return count;
}
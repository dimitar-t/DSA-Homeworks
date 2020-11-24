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
	int x;
	Node* left;
	Node* right;

	Node(int index, int x) {
		this->index = index;
		this->x = x;
		this->left = nullptr;
		this->right = nullptr;
	}
};

void traverseTree(Node* root, vector<Node*>& leftVisited, vector<Node*>& rightVisited);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<Node*> tree(n);
	tree[0] = new Node(0, 0); // root

	for (int i = 0; i < n; i++) {
		int left, right;
		cin >> left >> right;

		if (left != -1) {
			tree[left] = new Node(left, tree[i]->x - 1);
			tree[i]->left = tree[left];
		}

		if (right != -1) {
			tree[right] = new Node(right, tree[i]->x + 1);
			tree[i]->right = tree[right];
		}
	}

	vector<Node*> leftVisited;
	vector<Node*> rightVisited;
	traverseTree(tree[0], leftVisited, rightVisited);

	for (int i = leftVisited.size() - 1; i >= 0; i--) {
		printf("%d ", leftVisited[i]->index);
	}

	for (int i = 0; i < rightVisited.size(); i++) {
		printf("%d ", rightVisited[i]->index);
	}

	return 0;
}

void traverseTree(Node* root, vector<Node*>& leftVisited, vector<Node*>& rightVisited) {
	queue<Node*> queue;
	queue.push(root);

	while (!queue.empty()) {
		Node* current = queue.front();
		queue.pop();

		if (current->x < 0) {
			if (find_if(leftVisited.begin(), leftVisited.end(), [current](const Node* n) { return current->x == n->x; }) == leftVisited.end()) {
				leftVisited.push_back(current);
			}
		}
		else {
			if (find_if(rightVisited.begin(), rightVisited.end(), [current](const Node* n) { return current->x == n->x; }) == rightVisited.end()) {
				rightVisited.push_back(current);
			}
		}

		if (current->left != nullptr) {
			queue.push(current->left);
		}

		if (current->right != nullptr) {
			queue.push(current->right);
		}
	}
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Node {
public:
	Node* parent;

	Node(Node* parent) {
		this->parent = parent;
	}
};

bool isParent(Node* parent, Node* child);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<Node*> tree(n);
	tree[0] = new Node(nullptr);

	for (int i = 0; i < n - 1; i++) {
		int parent, child;
		cin >> parent >> child;

		Node* childNode = new Node(tree[parent]);
		tree[child] = childNode;
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		int parent, child;
		cin >> parent >> child;

		if (isParent(tree[parent], tree[child])) {
			printf("%s\n", "YES");
		}
		else {
			printf("%s\n", "NO");
		}
	}

	return 0;
}

bool isParent(Node* parent, Node* child) {
	Node* current = child->parent;

	bool isFound = false;
	while (current != nullptr) {
		if (current == parent) {
			isFound = true;

			break;
		}

		current = current->parent;
	}

	return isFound;
}
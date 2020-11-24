#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "BST.h"

using namespace std;

int main() {
	int n;
	cin >> n;

	BST<string> tree;

	for (int i = 0; i < n; i++)	{
		string input;
		cin >> input;
		tree.insertNode(input);
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		string input;
		cin >> input;

		if (tree.findNode(input)) {
			printf("%s\n", "YES");
		}
		else {
			printf("%s\n", "NO");
		}
	}

	return 0;
}
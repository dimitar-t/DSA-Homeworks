#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int vertices;
	cin >> vertices;

	vector<vector<int>> adjacency(vertices);

	for (int i = 0; i < vertices; i++) {
		int n;
		cin >> n;

		for (int j = 0; j < n; j++) {
			int vertice;
			cin >> vertice;

			adjacency[i].push_back(vertice);
			adjacency[vertice].push_back(i);
		}
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		int n;
		cin >> n;

		int start;
		cin >> start;

		bool exists = true;

		for (int j = 1; j < n; j++) {
			int vertice;
			cin >> vertice;

			if (find(adjacency[start].begin(), adjacency[start].end(), vertice) != adjacency[start].end()) {
				start = vertice;
			}
			else {
				exists = false;
			}
		}

		cout << exists << " ";
	}

	return 0;
}

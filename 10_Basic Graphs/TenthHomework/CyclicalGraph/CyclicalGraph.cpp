#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isCyclical(vector<vector<int>>& adjacency);

bool dfs(int start, vector<vector<int>>& adjacency, vector<bool> visited, bool hasCycle = false);

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int v, e;
		cin >> v >> e;

		vector<vector<int>> adjacency(v);

		for (int i = 0; i < e; i++) {
			int start, end, weight;
			cin >> start >> end >> weight;

			start--;
			end--;

			adjacency[start].push_back(end);
		}

		if (isCyclical(adjacency)) {
			cout << "true" << " ";
		}
		else {
			cout << "false" << " ";
		}
	}

	return 0;
}

bool isCyclical(vector<vector<int>>& adjacency) {
	vector<bool> visited(adjacency.size());

	for (int j = 0; j < adjacency.size(); j++) {
		visited[j] = false;
	}

	for (int i = 0; i < adjacency.size(); i++) {

		if (dfs(i, adjacency, visited)) {
			return true;
		}
	}

	return false;
}

bool dfs(int start, vector<vector<int>>& adjacency, vector<bool> visited, bool hasCycle) {
	visited[start] = true;

	if (!hasCycle) {
		for (int i = 0; i < adjacency[start].size(); i++) {

			if (!visited[adjacency[start][i]]) {
				hasCycle = dfs(adjacency[start][i], adjacency, visited, hasCycle);
			}
			else {
				return true;
			}
		}
	}

	return hasCycle;
}
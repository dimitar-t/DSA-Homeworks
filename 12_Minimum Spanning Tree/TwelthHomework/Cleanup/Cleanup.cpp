#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& used);

int main() {
	int crossroads, streets;
	cin >> crossroads >> streets;

	if (crossroads == 1) {
		cout << 0 << endl;

		return 0;
	}

	vector<vector<int>> graph(crossroads + 1);
	vector<bool> visitedCrossroads(crossroads + 1);
	int counter = 0;

	int hours = 0;

	for (int i = 0; i < streets; i++) {
		int first, second;
		cin >> first >> second;

		graph[first].push_back(second);
		graph[second].push_back(first);

		if (!visitedCrossroads[first]) {
			visitedCrossroads[first] = true;
			counter++;
		}

		if (!visitedCrossroads[second]) {
			visitedCrossroads[second] = true;
			counter++;
		}

		hours++;

		// check if all nodes have been visited
		if (counter == visitedCrossroads.size() - 1) {
			// check if graph is connected
			vector<bool> used(crossroads + 1, false);

			dfs(1, graph, used);

			// graph is connected
			if (find(next(used.begin()), used.end(), false) == used.end()) {
				cout << hours << endl;

				return 0;
			}
		}
	}

	cout << -1 << endl;

	return 0;
}

void dfs(int node, vector<vector<int>>& graph, vector<bool>& used) {
	if (!used[node]) {
		used[node] = true;

		for (int i = 0; i < graph[node].size(); i++) {
			dfs(graph[node][i], graph, used);
		}
	}
}
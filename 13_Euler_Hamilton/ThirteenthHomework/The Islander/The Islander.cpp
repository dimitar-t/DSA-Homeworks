#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool isConnected(unordered_map<int, vector<int>>& graph, int totalVertices);

pair<bool, bool> checkEuler(unordered_map<int, vector<int>>& graph);

int main() {
	int queries;
	cin >> queries;

	for (int i = 0; i < queries; i++) {
		int vertices, edges;
		cin >> vertices >> edges;

		// read graph
		unordered_map<int, vector<int>> graph;

		for (int j = 0; j < edges; j++) {
			int from, to;
			cin >> from >> to;

			graph[from].push_back(to);
			graph[to].push_back(from);
		}

		if (isConnected(graph, vertices)) {
			pair<bool, bool> eulerResult = checkEuler(graph);

			if (eulerResult.first) {
				if (eulerResult.second) {
					cout << "ecycle" << endl;
				}
				else {
					cout << "epath" << endl;
				}
			}
			else {
				cout << "none" << endl;
			}
		}
		else {
			cout << "none" << endl;
		}
	}

	return 0;
}

bool isConnected(unordered_map<int, vector<int>>& graph, int totalVertices) {
	unordered_set<int> visitedVertices;

	for (auto keyValuePair : graph) {
		vector<int> currentValue = keyValuePair.second;

		if (!currentValue.empty()) {
			visitedVertices.insert(currentValue.begin(), currentValue.end());
		}
	}

	if (visitedVertices.size() == totalVertices) {
		return true;
	}

	return false;
}

// first bool is for Euler path; second bool is for Euler loop
pair<bool, bool> checkEuler(unordered_map<int, vector<int>>& graph) {
	int oddDegrees = 0;

	for (auto keyValuePair : graph) {
		if (keyValuePair.second.size() % 2 == 1) {
			oddDegrees++;
		}
	}

	if (oddDegrees == 0) {
		return { true, true };
	}
	else if (oddDegrees == 2) {
		return { true, false };
	}
	else {
		return { false, false };
	}
}
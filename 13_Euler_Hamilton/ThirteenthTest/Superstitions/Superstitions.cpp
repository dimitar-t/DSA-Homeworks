#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct Edge {
	int to;
	int weight;
};

bool findNeighbour(vector<vector<Edge>>& graph, int from, int to, set<int>& superstitions);

int main() {
	int vertices, edges;
	cin >> vertices >> edges;

	vector<vector<Edge>> graph(vertices);

	for (int i = 0; i < edges; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;

		graph[from].push_back({ to, weight });
	}

	int k;
	cin >> k;

	set<int> superstitions;

	for (int i = 0; i < k; i++) {
		int superstition;
		cin >> superstition;

		superstitions.insert(superstition);
	}

	int queries;
	cin >> queries;

	for (int i = 0; i < queries; i++) {
		int length;
		cin >> length;

		vector<int> road;

		for (int j = 0; j < length; j++) {
			int town;
			cin >> town;

			road.push_back(town);
		}

		bool notPossible = false;

		for (int j = 0; j < length - 1; j++) {
			if (!findNeighbour(graph, road[j], road[j + 1], superstitions)) {
				notPossible = true;

				break;
			}
		}

		cout << !notPossible;
	}

	return 0;
}

bool findNeighbour(vector<vector<Edge>>& graph, int from, int to, set<int>& superstitions) {
	for (int i = 0; i < graph[from].size(); i++) {
		if (graph[from][i].to == to && superstitions.find(graph[from][i].weight) == superstitions.end()) {
			return true;
		}
	}

	return false;
}
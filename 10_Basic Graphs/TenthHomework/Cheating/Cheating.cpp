#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

int getLeastRiskyPath(int start, int end, vector<vector<pair<int, int>>>& adjacency);

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	int cheater = 0;
	int target = n - 1;

	vector<vector<pair<int, int>>> adjacency(n);

	// safe edges
	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;

		adjacency[start].push_back({ end, 0 });
		adjacency[end].push_back({ start, 0 });
	}

	// risky edges
	for (int i = 0; i < k; i++) {
		int start, end;
		cin >> start >> end;

		adjacency[start].push_back({ end, 1 });
		adjacency[end].push_back({ start, 1 });
	}

	cout << getLeastRiskyPath(cheater, target, adjacency);

	return 0;
}

int getLeastRiskyPath(int start, int end, vector<vector<pair<int, int>>>& adjacency) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;

	vector<int> distances(adjacency.size(), numeric_limits<int>::max());

	queue.push({ 0, start });
	distances[start] = 0;

	while (!queue.empty()) {
		int current = queue.top().second;
		queue.pop();

		for (pair<int, int> adj : adjacency[current]) {
			int value = adj.first;
			int weight = adj.second;

			if (distances[value] > distances[current] + weight) {
				distances[value] = distances[current] + weight;

				queue.push({ distances[value], value });
			}
		}
	}

	if (distances[end] == numeric_limits<int>::max()) {
		return -1;
	}

	return distances[end];
}

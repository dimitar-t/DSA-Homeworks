#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<long long> findShortestPaths(int source, vector<vector<pair<int, int>>>& adjacency);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int vertices, edges;
	cin >> vertices >> edges;

	vector<vector<pair<int, int>>> adjacency;
	adjacency.resize(vertices + 1);

	for (int i = 0; i < edges; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;

		adjacency[start].push_back({ end, weight });
		adjacency[end].push_back({ start, weight });
	}

	int source;
	cin >> source;

	vector<long long> result = findShortestPaths(source, adjacency);

	for (int i = 1; i <= vertices; i++) {
		if (i != source) {
			if (result[i] == numeric_limits<long long>::max()) {
				cout << -1 << " ";
			}
			else {
				cout << result[i] << " ";
			}
		}
	}

	return 0;
}

vector<long long> findShortestPaths(int source, vector<vector<pair<int, int>>>& adjacency) {
	vector<long long> distances(adjacency.size(), numeric_limits<long long>::max());

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dijkstraQueue;

	dijkstraQueue.push({ 0, source });

	distances[source] = 0;

	while (!dijkstraQueue.empty()) {
		pair<int, int> currentNode = dijkstraQueue.top();
		dijkstraQueue.pop();

		int currentIndex = currentNode.second;
		long long length = currentNode.first;

		int loopSize = adjacency[currentIndex].size();

		for (int i = 0; i < loopSize; i++) {
			pair<int, int> childNode = adjacency[currentIndex][i];
			int childIndex = childNode.first;
			int childWeight = childNode.second;

			if (distances[childIndex] > length + childWeight) {
				dijkstraQueue.push({ length + childWeight, childIndex });

				distances[childIndex] = distances[currentIndex] + childWeight;
			}
		}
	}

	return distances;
}
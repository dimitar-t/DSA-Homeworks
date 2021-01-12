#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

pair<long long, long long> findCountAndWeightOfShortestPaths(int source, int destination, vector<vector<pair<int, int>>>& adjacency);

int main() {
	int vertices, edges;
	cin >> vertices >> edges;

	vector<vector<pair<int, int>>> adjacency;
	adjacency.resize(vertices + 1);

	for (int i = 0; i < edges; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;

		adjacency[start].push_back({ end, weight });
	}

	int source = 1;
	int destination = vertices;

	pair<long long, long long> output = findCountAndWeightOfShortestPaths(source, destination, adjacency);

	cout << output.first << " " << output.second;

	return 0;
}

pair<long long, long long> findCountAndWeightOfShortestPaths(int source, int destination, vector<vector<pair<int, int>>>& adjacency) {
	vector<long long> distances(adjacency.size(), numeric_limits<long long>::max());
	vector<long long> paths(adjacency.size(), 0);

	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> djikstraQueue;
	djikstraQueue.push({ 0, source });

	distances[source] = 0;
	paths[source] = 1;

	while (!djikstraQueue.empty()) {
		int currentNode = djikstraQueue.top().second;
		long long length = djikstraQueue.top().first;

		djikstraQueue.pop();

		for (int i = 0; i < adjacency[currentNode].size(); i++) {
			int childNode = adjacency[currentNode][i].first;
			long long weight = adjacency[currentNode][i].second;

			if (distances[childNode] > length + weight) {
				djikstraQueue.push({ length + weight, childNode });
				distances[childNode] = distances[currentNode] + weight;
				paths[childNode] = paths[currentNode];
			}
			else if (distances[childNode] == length + weight) {
				if (paths[childNode] + paths[currentNode] > 1000000007) {
					paths[childNode] = (paths[childNode] + paths[currentNode]) - 1000000007;
				}
				else {
					paths[childNode] = paths[childNode] + paths[currentNode];
				}
			}
		}
	}

	long long pathLength = distances[destination] == numeric_limits<long long>::max() ? -1 : distances[destination];
	long long pathsCount = paths[destination];

	return { pathLength, pathsCount };
}
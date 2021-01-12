#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void addHelperVertice(vector<int>& destinationSet, vector<vector<pair<int, int>>>& adjacency);

vector<long long> findShortestPaths(int source, vector<vector<pair<int, int>>>& adjacency);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int vertices, edges;
	cin >> vertices >> edges;

	vector<vector<pair<int, int>>> adjacency;
	adjacency.resize(vertices);

	for (int i = 0; i < edges; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;

		adjacency[start].push_back({ end, weight });
		adjacency[end].push_back({ start, weight });
	}

	int k;
	cin >> k;

	vector<int> destinationSet;

	for (int i = 0; i < k; i++) {
		int dest;
		cin >> dest;

		destinationSet.push_back(dest);
	}

	addHelperVertice(destinationSet, adjacency);

	vector<long long> destinations = findShortestPaths(adjacency.size() - 1, adjacency);

	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		int source;
		cin >> source;

		printf("%lld\n", destinations[source]);
	}

	return 0;
}

void addHelperVertice(vector<int>& destinationSet, vector<vector<pair<int, int>>>& adjacency) {
	int newVertice = adjacency.size();

	adjacency.push_back(vector<pair<int, int>>());

	for (int i = 0; i < destinationSet.size(); i++) {
		adjacency[newVertice].push_back({ destinationSet[i], 0 });
		adjacency[destinationSet[i]].push_back({ newVertice, 0 });
	}
}

vector<long long> findShortestPaths(int source, vector<vector<pair<int, int>>>& adjacency) {
	vector<long long> distances(adjacency.size(), numeric_limits<long long>::max());

	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> djikstraQueue;
	djikstraQueue.push({ 0, source });

	distances[source] = 0;

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
			}
		}
	}

	return distances;
}
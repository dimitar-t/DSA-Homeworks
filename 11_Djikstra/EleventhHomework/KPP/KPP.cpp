#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

void topologicalSort(int vertice, bool visited[], stack<int>& sortStack, vector<vector<pair<int, int>>>& adjacency);

pair<long long, long long> findCountAndWeightOfLongestPaths(int source, int destination, vector<vector<pair<int, int>>>& adjacency);

int main() {
	int vertices, edges;
	cin >> vertices >> edges;

	vector<vector<pair<int, int>>> adjacency;
	adjacency.resize(vertices);

	for (int i = 0; i < edges; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;

		adjacency[start].push_back({ end, weight });
	}

	int source, destination;
	cin >> source >> destination;

	pair<long, long> result = findCountAndWeightOfLongestPaths(source, destination, adjacency);

	cout << result.first << " " << result.second;

	return 0;
}

void topologicalSort(int vertice, bool visited[], stack<int>& sortStack, vector<vector<pair<int, int>>>& adjacency) {
	visited[vertice] = true;

	for (int i = 0; i < adjacency[vertice].size(); i++) {
		int childIndex = adjacency[vertice][i].first;

		if (!visited[childIndex]) {
			topologicalSort(childIndex, visited, sortStack, adjacency);
		}
	}

	sortStack.push(vertice);
}

pair<long long, long long> findCountAndWeightOfLongestPaths(int source, int destination, vector<vector<pair<int, int>>>& adjacency) {
	vector<long long> distances(adjacency.size(), numeric_limits<long long>::min());
	vector<long long> paths(adjacency.size(), 0);

	stack<int> sortStack;
	bool* visited = new bool[adjacency.size()];

	for (int i = 0; i < adjacency.size(); i++) {
		visited[i] = false;
	}

	for (int i = 0; i < adjacency.size(); i++) {

		if (!visited[i]) {
			topologicalSort(i, visited, sortStack, adjacency);
		}
	}

	distances[source] = 0;
	paths[source] = 1;

	while (!sortStack.empty()) {
		int currentNode = sortStack.top();
		sortStack.pop();

		if (distances[currentNode] != numeric_limits<long long>::min()) {

			for (int i = 0; i < adjacency[currentNode].size(); i++) {
				pair<int, int> childNode = adjacency[currentNode][i];
				int childIndex = childNode.first;
				int childWeight = childNode.second;

				if (distances[childIndex] < distances[currentNode] + childWeight) {
					distances[childIndex] = distances[currentNode] + childWeight;
					paths[childIndex] = paths[currentNode];
				}
				else if (distances[childIndex] == distances[currentNode] + childWeight) {
					paths[childIndex] += paths[currentNode];
				}
			}
		}
	}

	long long pathLength = distances[destination] == numeric_limits<long long>::min() ? -1 : distances[destination];
	long long pathsCount = paths[destination];

	return { pathLength, pathsCount };
}
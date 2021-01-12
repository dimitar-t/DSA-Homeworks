#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int m, n;
	cin >> m >> n;

	vector<vector<int>> adjacency(m);

	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;

		adjacency[start].push_back(end);
		adjacency[end].push_back(start);
	}

	vector<bool> visited(m, false);

	int components = 0;

	for (int i = 0; i < m; i++) {

		if (!visited[i] && !adjacency[i].empty()) {
			visited[i] = true;

			queue<int> bfsQueue;
			bfsQueue.push(i);
			
			while (!bfsQueue.empty()) {
				int current = bfsQueue.front();
				bfsQueue.pop();

				for (int j = 0; j < adjacency[current].size(); j++) {
					if (!visited[adjacency[current][j]]) {
						visited[adjacency[current][j]] = true;

						bfsQueue.push(adjacency[current][j]);
					}
				}
			}

			components++;
		}
	}

	cout << components;

	return 0;
}

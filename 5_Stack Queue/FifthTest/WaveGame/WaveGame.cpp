#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Trio {
	int x;
	int y;
	int distance;
};

int main() {
	int n, m;
	cin >> n >> m;

	// read matrix
	vector<vector<int>>	labyrinth;
	for (int i = 0; i < n; i++) {
		vector<int> row;
		for (int j = 0; j < m; j++) {
			int input;
			cin >> input;
			row.push_back(input);
		}

		labyrinth.push_back(row);
	}

	int x, y, r;
	cin >> x >> y >> r;

	queue<Trio> cells;
	vector<pair<int, int>> visited;

	if (labyrinth[x - 1][y - 1] == -1) {
		cout << 0 << endl;

		return 0;
	}
	else {
		cells.push({ x - 1, y - 1, 1 });
		visited.push_back({ x - 1, y - 1 });
	}

	int sum = 0;
	while (!cells.empty()) {
		Trio current = cells.front();
		cells.pop();

		if (current.distance < r) {
			if (current.x + 1 < n) {
				if (labyrinth[current.x + 1][current.y] > -1 && find(visited.begin(), visited.end(), make_pair(current.x + 1, current.y)) == visited.end()) {
					cells.push({ current.x + 1, current.y, current.distance + 1 });
					visited.push_back({ current.x + 1, current.y });
				}
			}

			if (current.x - 1 >= 0) {
				if (labyrinth[current.x - 1][current.y] > -1 && find(visited.begin(), visited.end(), make_pair(current.x - 1, current.y)) == visited.end()) {
					cells.push({ current.x - 1, current.y, current.distance + 1 });
					visited.push_back({ current.x - 1, current.y });
				}
			}

			if (current.y + 1 < m) {
				if (labyrinth[current.x][current.y + 1] > -1 && find(visited.begin(), visited.end(), make_pair(current.x, current.y + 1)) == visited.end()) {
					cells.push({ current.x, current.y + 1, current.distance + 1 });
					visited.push_back({ current.x, current.y + 1 });
				}
			}

			if (current.y - 1 >= 0) {
				if (labyrinth[current.x][current.y - 1] > -1 && find(visited.begin(), visited.end(), make_pair(current.x, current.y - 1)) == visited.end()) {
					cells.push({ current.x, current.y - 1, current.distance + 1 });
					visited.push_back({ current.x, current.y - 1 });
				}
			}
		}
		else if (current.distance == r) {
			sum += labyrinth[current.x][current.y];
		}
	}

	cout << sum << endl;

	return 0;
}
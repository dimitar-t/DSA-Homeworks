#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct ForestEntity {
	int row;
	int col;
	int value;
};

int getBoundingBox(ForestEntity startEntity, vector<vector<ForestEntity>>& forest, vector<vector<bool>>& visited);

int main() {
	int n;
	cin >> n;

	vector<vector<bool>> visited;

	for (int i = 0; i < n; i++) {
		visited.push_back(vector<bool>());

		for (int j = 0; j < n; j++) {
			visited[i].push_back(false);
		}
	}

	vector<vector<ForestEntity>> forest;

	for (int i = 0; i < n; i++) {
		forest.push_back(vector<ForestEntity>());

		for (int j = 0; j < n; j++) {
			int value;
			cin >> value;

			forest[i].push_back({ i, j, value });
		}
	}

	priority_queue<int> boundingBoxes;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			if (!visited[i][j] && forest[i][j].value == 1) {
				visited[i][j] = true;

				boundingBoxes.push(getBoundingBox(forest[i][j], forest, visited));
			}
		}
	}

	while (!boundingBoxes.empty()) {
		cout << boundingBoxes.top() << " ";

		boundingBoxes.pop();
	}

	return 0;
}

int getBoundingBox(ForestEntity startEntity, vector<vector<ForestEntity>>& forest, vector<vector<bool>>& visited) {
	queue<ForestEntity> bfsQueue;
	bfsQueue.push(startEntity);

	int minRow = startEntity.row;
	int maxRow = startEntity.row;
	int minCol = startEntity.col;
	int maxCol = startEntity.col;

	while (!bfsQueue.empty()) {
		ForestEntity current = bfsQueue.front();
		bfsQueue.pop();

		// go up
		if (current.row - 1 >= 0) {

			if (!visited[current.row - 1][current.col] && forest[current.row - 1][current.col].value == 1) {
				visited[current.row - 1][current.col] = true;

				bfsQueue.push(forest[current.row - 1][current.col]);

				if (current.row - 1 < minRow) {
					minRow = current.row - 1;
				}
			}
		}

		// go down
		if (current.row + 1 < forest.size()) {

			if (!visited[current.row + 1][current.col] && forest[current.row + 1][current.col].value == 1) {
				visited[current.row + 1][current.col] = true;

				bfsQueue.push(forest[current.row + 1][current.col]);

				if (current.row + 1 > maxRow) {
					maxRow = current.row + 1;
				}
			}
		}

		// go left
		if (current.col - 1 >= 0) {

			if (!visited[current.row][current.col - 1] && forest[current.row][current.col - 1].value == 1) {
				visited[current.row][current.col - 1] = true;

				bfsQueue.push(forest[current.row][current.col - 1]);

				if (current.col - 1 < minCol) {
					minCol = current.col - 1;
				}
			}
		}

		// go right
		if (current.col + 1 < forest.size()) {

			if (!visited[current.row][current.col + 1] && forest[current.row][current.col + 1].value == 1) {
				visited[current.row][current.col + 1] = true;

				bfsQueue.push(forest[current.row][current.col + 1]);

				if (current.col + 1 > maxCol) {
					maxCol = current.col + 1;
				}
			}
		}
	}

	return (maxCol - minCol + 1) * (maxRow - minRow + 1);
}
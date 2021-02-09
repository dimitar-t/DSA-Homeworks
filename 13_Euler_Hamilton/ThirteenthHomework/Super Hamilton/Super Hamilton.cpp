#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void findAllPaths(vector<vector<char>> maze, int currentRow, int currentCol, int keysLeft, int& pathsFound);

int main() {
	int rows, cols;
	cin >> rows >> cols;

	vector<vector<char>> maze(rows);
	
	int startRow = 0;
	int startCol = 0;

	int wallsCount = 0;

	for (int row = 0; row < rows; row++) {

		for (int col = 0; col < cols; col++) {
			char symbol;
			cin >> symbol;

			maze[row].push_back(symbol);

			if (symbol == 'x') {
				wallsCount++;
			}

			if (symbol == 's') {
				startRow = row;
				startCol = col;
			}
		}
	}

	int mazeSize = rows * cols;
	int totalKeys = mazeSize - (wallsCount + 2); // 2 for 's' and 'e'
	int paths = 0;
	
	findAllPaths(maze, startRow, startCol, totalKeys, paths);

	cout << paths << endl;

	return 0;
}

void findAllPaths(vector<vector<char>> maze, int currentRow, int currentCol, int keysLeft, int& pathsFound) {
	int totalRows = maze.size();
	int totalCols = maze.front().size();

	// princess found
	if (maze[currentRow][currentCol] == 'e') {

		// all keys are found
		if (keysLeft == 0) {
			pathsFound++;
		}
	}
	else if (maze[currentRow][currentCol] == '-') { // key found
		keysLeft--;

		maze[currentRow][currentCol] = 'x';
	}
	else if (maze[currentRow][currentCol] == 's'){ // start
		maze[currentRow][currentCol] = 'x';
	}
	else { // wall
		return;
	}

	// go up
	if (currentRow - 1 >= 0) {
		findAllPaths(maze, currentRow - 1, currentCol, keysLeft, pathsFound);
	}

	// go left
	if (currentCol - 1 >= 0) {
		findAllPaths(maze, currentRow, currentCol - 1, keysLeft, pathsFound);
	}

	// go right
	if (currentCol + 1 < totalCols) {
		findAllPaths(maze, currentRow, currentCol + 1, keysLeft, pathsFound);
	}

	// go down
	if (currentRow + 1 < totalRows) {
		findAllPaths(maze, currentRow + 1, currentCol, keysLeft, pathsFound);
	}
}
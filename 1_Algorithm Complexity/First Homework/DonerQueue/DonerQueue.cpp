#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int size = 0;
	cin >> size;

	vector<char> queue;
	for (int i = 0; i < size; i++) {
		char input;
		cin >> input;
		queue.push_back(input);
	}

	int bestDistance = -1;
	int currentDistance = -1;
	int startIndex = -1;
	for (int i = 0; i < size; i++) {
		if (queue[i] == '-') {
			currentDistance++;

			if (currentDistance == 0) {
				startIndex = i;
			}
		}

		if (queue[i] == 'x') {
			if (currentDistance != -1) {
				if (startIndex == 0) { // first place is empty
					bestDistance = currentDistance;
				}
				else {
					if (currentDistance / 2 > bestDistance) {
						bestDistance = currentDistance / 2;
					}
				}
			}

			currentDistance = -1;
		}

		// last place is empty
		if (queue[i] == '-' && i == size - 1) {
			if (currentDistance > bestDistance) {
				bestDistance = currentDistance;
			}
		}
	}

	cout << bestDistance;

	return 0;
}
